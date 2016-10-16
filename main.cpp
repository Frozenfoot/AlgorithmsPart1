#include <iostream>
#include <vector>
#include <list>
#include <cstring>

using namespace std;

int *increaseMemory(int **arr, int &length);

int main()
{
    int beginTime, endTime;

    int currentSizeBegin = 2;
    int currentSizeEnd = 2;
    int scanned = 0;

    int* beginTimeArray = new int[currentSizeBegin];
    int* endTimeArray = new int[currentSizeEnd];

    for(auto i = 0; cin >> beginTime && cin >> endTime; ++i)
    {
        if(currentSizeBegin == i + 1)
        {
            beginTimeArray = increaseMemory(&beginTimeArray, currentSizeBegin);
            endTimeArray = increaseMemory(&endTimeArray, currentSizeEnd);
        }

        beginTimeArray[i] = beginTime;
        endTimeArray[i] = endTime;

        ++scanned;
    }

    int maximalNumberOfRequests = 1;
    int minimalEndTime = endTimeArray[0];
    int minimalBeginTime = beginTimeArray[0];
    int indexForSearching = 0;

    for(auto i = 0; i < scanned; ++i)
    {
        if(endTimeArray[i] < minimalEndTime)
        {
            minimalEndTime = endTimeArray[i];
            minimalBeginTime = beginTimeArray[i];
        }

        if(endTimeArray[i] > endTimeArray[indexForSearching])
            indexForSearching = i;
    }

    //cout << "First request is " << minimalBeginTime << " " << minimalEndTime << endl;

    bool newRequestIsFound = false;
    int minimalIndex = indexForSearching;

    while(true)
    {
        minimalIndex = indexForSearching;
        for(auto i = 0; i < scanned; ++i)
        {
            if(beginTimeArray[i] >= minimalEndTime &&
               endTimeArray[i] <= endTimeArray[minimalIndex])
            {
                minimalIndex = i;
                newRequestIsFound = true;
            }
        }

        if(newRequestIsFound)
        {
            //cout <<"Next request is " << beginTimeArray[minimalIndex] << " " << endTimeArray[minimalIndex] << endl;
            minimalEndTime = endTimeArray[minimalIndex];
            ++maximalNumberOfRequests;
            newRequestIsFound = false;
        }

        else
            break;
    }

    cout << maximalNumberOfRequests << endl;

    return 0;
}

int *increaseMemory(int **arr, int &length)
{
    int *newArray = new int[length * 2];
    length *= 2;
    memcpy(newArray, *arr, (length / 2) * sizeof(int));
    delete[] arr;
    return newArray;
}
