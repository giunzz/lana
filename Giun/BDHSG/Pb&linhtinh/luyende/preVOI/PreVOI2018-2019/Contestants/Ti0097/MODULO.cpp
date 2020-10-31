#include<bits/stdc++.h>
using namespace std;
const int maxn = 63;

long long lt[maxn];
long long lt10[maxn];
int A, B;
int n;
long long mod;
int p[maxn];

void io()
{
    freopen("MODULO.INP","r",stdin);
    freopen("MODULO.OUT","w",stdout);
}

void Enter()
{
    cin>>A>>B;
    cin>>n;
    cin>>mod;
}

void Init()
{
    lt[0] = lt10[0] = 1;
    lt[1] = 2;
    lt10[1] = 10;
    for(int i=1; i<=n; ++i)
    {
        lt[i] = (long long) lt[i-1] * 2;
    }
    for(int i = 2; i<=18; ++i)
        lt10[i] =(long long) lt10[i-1] * 10;
}

void Solve()
{
    for(int i = 0; i<(1<<n) ; ++i)
    {
        long long k = 0;
        for(int j = 0; j<n; ++j)
        {
            p[j+1] = (i>>j)&1;
            if(p[j+1] == 1)
            {
                k += (A * lt10[n-1 -j]);
            }
            else
            {
                k += (B * lt10[n-1 -j]);
            }
        }
        if(k % lt[n] == mod)
        {
            cout<<k;
            return;
        }
    }
    cout<<-1;
}

int main()
{
    io();
    Enter();
    Init();
    if(n <= 18) Solve();
    else
    {
        cout<<-1;
    }
}

