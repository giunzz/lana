#include<bits/stdc++.h>
using namespace std;
#define NAME "SEQUENCE"
const int maxn = 3e3 + 5;
int a[maxn];
int b[maxn];
int m,n,k;

void io()
{
    freopen(NAME".inp","r",stdin);
    freopen(NAME".out","w",stdout);
}

void Input()
{
    scanf("%d%d%d",&m,&n,&k);
    for(int i = 1; i <= m; ++i) scanf("%d",&a[i]);
    for(int i = 1; i <= n; ++i) scanf("%d",&b[i]);
}

void Solve()
{
    if(m == k) for(int i = 1; i <= m; ++i) cout << a[i] <<" ";
    else if(n == k) for(int i = 1; i <= n; ++i) cout << b[i] <<" ";
    else if(m + n == k)
    {
        bool ok = 0;
        if(m > n) ok = 1;
        else if(m == n)
        {
            for(int i = 1; i <= m; ++i)
            {
                if(a[i] > b[i]) ok = 1;
                break;
            }
        }
        if(!ok)
        {
            for(int i = 1; i <= m; ++i) cout << a[i] <<" ";
            for(int i = 1; i <= n; ++i) cout << b[i] <<" ";
        }
        else
        {
            for(int i = 1; i <= n; ++i) cout << b[i] <<" ";
            for(int i = 1; i <= m; ++i) cout << a[i] <<" ";
        }
    }
    else
    {
        for(int i = 1; i <= k - m; ++i) cout << 1 <<" ";
        for(int i = 1; i <= m; ++i) cout << a[i] <<" ";
    }
}

int main()
{
    io();
    Input();
    Solve();
}
