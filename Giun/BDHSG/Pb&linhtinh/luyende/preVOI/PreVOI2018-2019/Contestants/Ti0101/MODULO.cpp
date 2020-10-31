#include<bits/stdc++.h>
using namespace std;
#define NAME "MODULO"
const int maxn = 45;
int c[maxn];
int a,b,n,k;

void io()
{
    freopen(NAME".inp","r",stdin);
    freopen(NAME".out","w",stdout);
}

void Input()
{
    cin >> a >> b >> n >> k;
}

void Solve()
{
    long long mod = (1 << n);
    for(int i = 0; i < (1 << n); ++i)
    {
        long long S = 0;
        for(int j = 0; j < n; ++j) c[j + 1] = (i >> j) & 1;
        for(int j = 1; j <= n; ++j)
        {
            if(c[j] == 0) S = (S * 10 + a) % mod;
            else S = (S * 10 + b) % mod;
        }
        if(S == k)
        {
            for(int j = 1; j <= n; ++j)
                if(c[j] == 0) printf("%d",a);
                else printf("%d",b);
            return;
        }
    }
    cout << -1;
}

int main()
{
    io();
    Input();
    Solve();
}
