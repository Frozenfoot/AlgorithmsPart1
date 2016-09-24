#include <iostream>

void printNSquares(int n);

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    printNSquares(n);
    return 0;
}

void printNSquares(int n)
{
    int currentSquare = 0;
    int currentNotEven = 1;
    for(int i = 0; i < n; ++i)
    {
        currentSquare += currentNotEven;
        currentNotEven += 2;
        cout << currentSquare << " ";
    }
}
