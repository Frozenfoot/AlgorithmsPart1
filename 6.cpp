/*Дано N кубиков. Требуется определить каким количеством способов можно выстроить из этих кубиков

пирамиду.

Формат входных данных:

На вход подается количество кубиков N.

Формат выходных данных:

Вывести число различных пирамид из N кубиков.

Высокая пирамида. ​Каждый вышележащий слой пирамиды должен быть не больше нижележащего.

N ≤ 200.

*/

#include <iostream>

using namespace std;

long numberOfTallPyramdes(int n, int k, long **decompositions);

int main()
{
    int n;
    cin >> n;

    long **numberOfDecompositions = new long*[n + 1];
    for(auto i = 0; i <= n; ++i)
        numberOfDecompositions[i] = new long[n + 1];

    for(auto i = 0; i <= n; ++i)
        for(auto j = 0; j <= n; ++j)
            numberOfDecompositions[i][j] = -1;

    numberOfDecompositions[0][0] = 1;
    cout << numberOfTallPyramdes(n, n, numberOfDecompositions);

    for(auto i = 0; i < n + 1; ++i)
        delete numberOfDecompositions[i];

    delete[] numberOfDecompositions;

    return 0;
}

long numberOfTallPyramdes(int n, int k, long **decompositions)
{
    if(n >= 0 && k >= 0 && decompositions[n][k] > 0)
        return decompositions[n][k];

    if(n < 0)
        return 0;

    if(n <= 1 || k == 1)
        return 1;

    decompositions[n][k] = numberOfTallPyramdes(n, k - 1, decompositions) +
    numberOfTallPyramdes(n - k, k, decompositions);

    return decompositions[n][k];
}
