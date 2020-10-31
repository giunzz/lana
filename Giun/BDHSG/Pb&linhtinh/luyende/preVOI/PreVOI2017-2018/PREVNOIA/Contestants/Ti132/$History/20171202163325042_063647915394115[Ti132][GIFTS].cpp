#include <bits/stdc++.h>
using namespace std;
long n,res1,res2,k,ok1,ok2,tam=LONG_MAX;
long f[1000001],h[1000001],a[1000001];
queue <long> q ;
int main()
{
    freopen("GIFTS.INP","r",stdin);
    freopen("GIFTS.OUT","w",stdout);
    cin >> n >> k ;
    for (long i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for (long i=1;i<=n;i++)
        f[i]=f[i-1]+a[i];
    for (long i=1;i<=n-k+1;i++)
    {
        h[i]=f[i+k-1]-f[i-1];
    }
    for (long i=1;i<=n-k+1;i++)
    if (h[i]>res1)
    {
        res1=h[i];
    }
    for (long i=1;i<=n-k+1;i++)
    {
        if (h[i]==res1)
        {
            q.push(i);
            q.push(i+k-1);
        }
    }
    while (!q.empty())
    {
    ok1=q.front();
    q.pop();
    ok2=q.front();
    q.pop();
    res2=0;
    for (long i=1;i<=n;i++)
    {
        if (h[i] > res2)
        {
            if (ok2<i || ok1>i+k-1)
            {
                res2=h[i];
            }
        }
    }
    tam=min(tam,res2);
    }
    cout << tam ;
    return 0;
}
