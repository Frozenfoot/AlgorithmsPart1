/*Дано выражение в инфиксной записи. Вычислить его, используя перевод выражения в постфиксную запись.

Выражение не содержит отрицительных чисел.

Количество операций ≤ 100.*/

#include <iostream>
#include <string>

using namespace std;

int getPriority(char operation)
{
    switch (operation)
    {
    case '+':
        return 1;

    case '-':
        return 1;

    case '*':
        return 2;

    case '/':
        return 2;

    default:
        return 0;
    }
}

class Stack
{
private:
    int capacity;
    int *storage;
    int top;

public:
    Stack()
    {
        storage = new int[4];
        this->capacity = 4;
        top = -1;
    }

    Stack(int capacity)
    {
        storage = new int[capacity];
        this->capacity = capacity;
        top = -1;
    }

    int getTopIndex()
    {
        return top;
    }

    int getTop()
    {
        return storage[top];
    }

    void push(int value)
    {
        if(top == capacity - 1)
        {
            int *temp = new int[capacity];
            for(auto i = 0; i < capacity; ++i)
                temp[i] = storage[i];
            delete[] storage;

            capacity *= 2;
            storage = new int[capacity];
            for(auto i = 0; i < capacity / 2; ++i)
                storage[i] = temp[i];

            delete[] temp;
        }
        ++top;
        storage[top] = value;
    }

    int pop()
    {
        if(top == -1)
        {
            cout << "Error, stack is empty" << endl;
            return -1;
        }

        else
        {
            --top;
            return storage[top + 1];
        }
    }

    ~Stack()
    {
        delete[] storage;
    }
};

string getPolishNotation(string infixString)
{
    Stack operatorStack = Stack(2);
    string inPolishNotation = "";

    for(auto i = 0; i < infixString.length(); ++i)
    {
        if(isdigit(infixString[i]))
            inPolishNotation += infixString[i];

        else if(infixString[i] == '(')
            operatorStack.push('(');

        else if(infixString[i] == ')')
        {
            while(operatorStack.getTop() != '(')
                inPolishNotation += char(operatorStack.pop());

            operatorStack.pop();
        }

        else if(infixString[i] == '+')
        {
            inPolishNotation += ' ';

            while(getPriority(operatorStack.getTop()) >= getPriority('+'))
                inPolishNotation += char(operatorStack.pop());

            operatorStack.push('+');
        }

        else if(infixString[i] == '-')
        {
            inPolishNotation += ' ';

            while(getPriority(operatorStack.getTop()) >= getPriority('-'))
                inPolishNotation += char(operatorStack.pop());

            operatorStack.push('-');
        }

        else if(infixString[i] == '*')
        {
            inPolishNotation += ' ';

            while(getPriority(operatorStack.getTop()) >= getPriority('*'))
                inPolishNotation += char(operatorStack.pop());

            operatorStack.push('*');
        }

        else if(infixString[i] == '/')
        {
            inPolishNotation += ' ';

            while(getPriority(operatorStack.getTop()) >= getPriority('/'))
                inPolishNotation += char(operatorStack.pop());

            operatorStack.push('/');
        }
    }

    while(operatorStack.getTopIndex() != -1)
        inPolishNotation += char(operatorStack.pop());

    return inPolishNotation;
}

bool isOperation(char symbol)
{
    return symbol == '+' || symbol == '-'
    || symbol == '*' || symbol == '/';
}
int calculatePolishNotation(string polishNotation)
{
    Stack calculationStack = Stack();
    int number = 0;

    for(auto i = 0; i < polishNotation.length(); ++i)
    {
        if(isdigit(polishNotation[i]))
        {
            number *= 10;
            number += polishNotation[i] - '0';
        }

        else if(isdigit(polishNotation[i - 1]))
        {
            calculationStack.push(number);
            number = 0;
        }

        if(polishNotation[i] == ' ')
                continue;
        else
        {
            switch(polishNotation[i])
            {
            case '+':
                {
                    int a = calculationStack.pop();
                    int b = calculationStack.pop();
                    calculationStack.push(a + b);
                    break;
                }

            case '-':
                {
                    int a = calculationStack.pop();
                    int b = calculationStack.pop();
                    calculationStack.push(b - a);
                    break;
                }

            case '*':
                {
                    int a = calculationStack.pop();
                    int b = calculationStack.pop();
                    calculationStack.push(a * b);
                    break;
                }

            case '/':
                {
                    int a = calculationStack.pop();
                    int b = calculationStack.pop();
                    calculationStack.push(b / a);
                    break;
                }
            }
        }
    }

    return calculationStack.pop();
}

int main()
{
    string testString;
    cin >> testString;
    cout << calculatePolishNotation(getPolishNotation(testString)) << endl;
    return 0;
}
