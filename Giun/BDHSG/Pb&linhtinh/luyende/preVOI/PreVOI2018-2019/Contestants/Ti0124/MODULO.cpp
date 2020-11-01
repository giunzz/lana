#include <bits/stdc++.h>
using namespace std;

const int maxn = 70;

long long a, b, n, k, d;

void Try(int x)
{
    if(x > n)
    {
        if(d % (1 << n) == k)
        {
            cout << d;
            exit(0);
        }
        return;
    }
    for(int i = 0; i <= 1; i++)
    {
        if(i) d = d * 10 + a;
        if(!i) d = d * 10 + b;
        Try(x + 1);
        d /= 10;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("MODULO.inp","r",stdin); freopen("MODULO.out","w",stdout);
    cin >> a >> b >> n >> k;
    if(n <= 20)
    {
        Try(1);
        cout << -1;
    }
    else cout << -1;
}
