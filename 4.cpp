#include <iostream>
#include <string.h>

using namespace std;

class Dequeue
{
public:
    Dequeue()
    {
        buffer = new long[4];
        bufferSize = 4;
        headIndex = 0;
        tailIndex = 0;
    }

    ~Dequeue()
    {
        delete[] buffer;
    }

    Dequeue(long newBufferSize)
    {
        buffer = new long[newBufferSize];
        bufferSize = newBufferSize;
        headIndex = 0;
        tailIndex = 0;
    }

    void pushFront(long b);
    void pushBack(long b);
    long popFront();
    long popBack();
    void enlarge();

private:
    long *buffer;
    long bufferSize;
    long headIndex;
    long tailIndex;
};

void Dequeue::enlarge()
{
    long *newBuffer = new long[bufferSize * 2];

    if(headIndex < tailIndex)
    {
        memcpy(newBuffer, buffer, sizeof(int) * bufferSize);
    }

    else
    {
        memcpy(newBuffer, buffer + headIndex, sizeof(int) * (bufferSize - headIndex));
        memcpy(newBuffer + bufferSize - headIndex, buffer, sizeof(int) * (tailIndex + 1));
    }

    delete[] buffer;
    buffer = newBuffer;

    headIndex = 0;
    tailIndex = bufferSize - 1;
    bufferSize *= 2;
}

void Dequeue::pushFront(long b)
{
    if(headIndex == (tailIndex + 1) % bufferSize)
        enlarge();

    headIndex = (headIndex - 1 + bufferSize) % bufferSize;
    buffer[headIndex] = b;
}

void Dequeue::pushBack(long b)
{
    if(headIndex == (tailIndex + 1) % bufferSize)
        enlarge();

    buffer[tailIndex] = b;
    tailIndex = (tailIndex + 1) % bufferSize;
}

long Dequeue::popFront()
{
    if(headIndex != tailIndex)
    {
        long result = buffer[headIndex];
        headIndex = (headIndex + 1) % bufferSize;
        return result;
    }

    return -1;
}

long Dequeue::popBack()
{
    if(headIndex != tailIndex)
    {
        tailIndex = (tailIndex - 1 + bufferSize) % bufferSize;
        return buffer[tailIndex];
    }

    return -1;
}

int main()
{
    int numberOfCommands = 0;
    cin >> numberOfCommands;

    int commandCode = 0;
    int b = 0;
    long expectedNumber = 0;

    Dequeue commandDequeue(numberOfCommands);

    long popped;
    for(int i = 0; i < numberOfCommands; ++i)
    {
        cin >> commandCode;
        cin >> b;

        switch(commandCode)
        {
        case(1):
            commandDequeue.pushFront(b);
            break;

        case(2):
            expectedNumber = b;
            popped = commandDequeue.popFront();
            if (expectedNumber != popped)
            {
                cout << "NO ";
                return 0;
            }
            break;

        case(3):
            commandDequeue.pushBack(b);
            break;

        case(4):
            expectedNumber = b;
            popped = commandDequeue.popBack();
            if (expectedNumber != popped)
            {
                cout << "NO";
                return 0;
            }
            break;
        }
    }

    cout << "YES";
    return 0;
}
