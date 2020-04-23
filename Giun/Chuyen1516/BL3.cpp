#include <bits/stdc++.h>

using namespace std;

int daoso(int n)
{
    int sodao = 0;
    while (n != 0)
    {
        sodao = sodao * 10 + n % 10;
        n /= 10;
    }
    return sodao;
}

int main()
{
    freopen("BL3.INP", "r", stdin);
    freopen("BL3.OUT", "w", stdout);
    int n, sodao;
    cin >> n;
    sodao = daoso(n);
    while (n != sodao)
    {
        n += sodao;
        sodao = daoso(n);
    }
    cout << sodao;
    return 0;
}
