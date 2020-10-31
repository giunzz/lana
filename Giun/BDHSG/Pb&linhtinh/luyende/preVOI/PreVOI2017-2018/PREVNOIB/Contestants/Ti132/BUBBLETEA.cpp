#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
long n,k;
long b[50001];
long d[50001];
long f[10000][10000];
vector <pair <long,long> > a[50001];
priority_queue <pair <long,long> > q;
void djt(long x)
{
    for(int i=1;i<=n;i++) d[i]=INT_MAX;
    q.push(make_pair(0,x));
    d[x]=0;
    while(!q.empty())
    {
        long u=q.top().second;
        long w=-q.top().first;
        q.pop();
        if(w>d[u]) continue;
        for(int i = 0;i<a[u].size();i++)
        {
            long v=a[u][i].first;
            long w1=a[u][i].second;
            if(d[v]>w+w1)
            {
                d[v]=w+w1;
                q.push(make_pair(-d[v],v));
            }
        }
    }
}
int main()
{
    freopen("BUBBLETEA.INP","r",stdin);
    freopen("BUBBLETEA.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> k ;
    for (long i=1;i<=k;i++)
    {
        cin >> b[i] ;
    }
    long u,v,c;
    for (long i=1;i<=n-1;i++)
    {
        cin >> u >> v >> c ;
        a[u].pb(mp(v,c));
        a[v].pb(mp(u,c));
    }
    for (long i=1;i<=k;i++)
    {
        djt(b[i]);
        for (long j=1;j<=k;j++)
            f[b[i]][b[j]]=d[b[j]];
    }
    if (k<=10)
    {
    long res=LONG_MAX;
    for (long x=1;x<=100000;x++)
    {
    long tam=0;
    for (long i=1;i<=k;i+=2)
    {
        tam=max(tam,f[b[i]][b[i+1]]);
    }
    res=min(res,tam);
    next_permutation(b+1,b+k+1);
    }
    cout << res ;
    }
    if (k>10)
    {
    long res=LONG_MAX;
    for (long x=1;x<=(4000000/k);x++)
    {
    long tam=0;
    for (long i=1;i<=k;i+=2)
    {
        tam=max(tam,f[b[i]][b[i+1]]);
    }
    res=min(res,tam);
    next_permutation(b+1,b+k+1);
    }
    cout << res ;
    }
    return 0;
}
