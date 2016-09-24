#include <iostream>

int JosephusProblem(int n, int k);

using namespace std;

int main()
{
    int n = 0;
    int k = 0;
    cin >> n >> k;
    cout << JosephusProblem(n, k);
    return 0;
}

int JosephusProblem(int n, int k)
{
    if (n == 1)
        return 1;
    else
    {
        return (JosephusProblem(n - 1, k) + k - 1) % n + 1;
    }
}
