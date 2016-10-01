/*​Дан отсортированный массив целых чисел A[0..n­1] и массив целых чисел
B[0..m­1]. Для каждого элемента массива B[i] найдите минимальный индекс
k минимального элемента массива A, равного или превосходящего
B[i]: A[k] >= B[i]. Если такого элемента нет, выведите n. Время работы
поиска k для каждого элемента B[i]: O(log(k)).*/

#include <iostream>

void findMinimalIndex(int *a, int *b, int lengthA, int lengthB);
                                        /*Finds minimal k from A for
                                        each element of B such that
                                        A[k] >= B[i]. If element
                                        does not exists, print n*/

int binarySearch(int *arr, int length, int element);/*Finds index, such that
                                                       Arr[i] == element or
                                                       minimal index, s.t
                                                       Arr[i] > element if
                                                       index Arr[i] == element
                                                       doesn't exist*/

using namespace std;

int main()
{
    int n = 0;
    int m = 0;

    cin >> n >> m;

    int *a = new int [n];
    int *b = new int [m];

    for(auto i = 0; i < n; ++i)
        cin >> a[i];

    for(auto i = 0; i < m; ++i)
        cin >> b[i];

    findMinimalIndex(a, b, n, m);

    delete a;
    delete b;

    return 0;
}

int binarySearch(int *arr, int length, int element)
{
    int rightBorder = 1;

    while(arr[rightBorder] < element && rightBorder < length / 2)
        rightBorder <<= 1;

    int leftBorder = rightBorder >> 1;

    if(arr[rightBorder] < element)
    {
        leftBorder = rightBorder;
        rightBorder = length - 1;
    }

    while(leftBorder < rightBorder)
    {
        int middle = (leftBorder + rightBorder) / 2;

        if(element <= arr[middle])
            rightBorder = middle;

        else
            leftBorder = middle + 1;
    }

    return (element > arr[leftBorder]) ? -1 : leftBorder;
}

void findMinimalIndex(int *a, int *b, int lengthA, int lengthB)
{
    for(int i = 0; i < lengthB; ++i)
    {
        int index = binarySearch(a, lengthA, b[i]);

        if (index == -1)
            cout << lengthA << " ";

        else
            cout << index << " ";
    }
}
