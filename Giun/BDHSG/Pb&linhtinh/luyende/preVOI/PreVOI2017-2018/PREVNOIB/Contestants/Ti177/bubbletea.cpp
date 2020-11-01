#include <bits/stdc++.h>
#define nmax 50007
#define vc 9999999999

using namespace std;
typedef pair <int,int> ii;

vector <ii> a[50007];
long long n,k,kvc[nmax],x[nmax],ans=vc,d[nmax],tr[nmax],dd[nmax],dd1[nmax];
bool ok;

void dijkstra(long uu)
{
    priority_queue <ii> pq;
    fill(d,d+n+1,1e9);
    d[uu]=0;
    pq.push(ii(0,uu));

    long u,du;
    while (!pq.empty())
    {
        u=pq.top().second;
        du=-pq.top().first;
        pq.pop();
        if (du!=d[u]) continue;
        for (long i=0;i<a[u].size();i++)
        {
            long v=a[u][i].first;
            long wv=a[u][i].second;
            if (d[v]>d[u]+wv)
            {
                d[v]=d[u]+wv;
                tr[v]=u;
                pq.push(ii(-d[v],v));
            }
        }
    }
}

void check()
{
    for (long i=1; i<=n; i++) {dd[i]=0; tr[i]=0;dd1[i]=0;}
    ok=true;

    long long minn=-1,dem,dn=0;
    for (long i=1; i<=k; i++)
      for (long j=1; j<=k; j++)
        if (x[j]==x[i]+1)
         {
             if (dd1[kvc[i]]==1 || dd1[kvc[j]]==1) continue;
             dn++;
             dd1[kvc[i]]=1;
             dd1[kvc[j]]=1;
             if (!ok) break;
             dem=0;
             dijkstra(kvc[j]);
             minn=max(minn,d[kvc[i]]);

             if (dd[kvc[j]]==1) dem++;
             dd[kvc[j]]=1;
             long chay1=kvc[j],chay2=kvc[i];
             while (chay2!=chay1)
              {
                if (dd[chay2]==1) dem++;
                if (dem>=2)
                {
                    ok=false;
                    break;
                }
                dd[chay2]=1;
                chay2=tr[chay2];
              }
         }
    if (ok==1 && minn!=-1 && dn==k/2) ans=min(ans,minn);
}

void tryy_(long i)
{
    for (long j=1; j<=k; j++)
    {
        x[i]=j;
        if (i==k) check();
        else tryy_(i+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("bubbletea.inp","r",stdin);
    freopen("bubbletea.out","w",stdout);
    cin >> n >> k;
    for (long i=1; i<=k; i++) cin >> kvc[i];
    for (long i=1; i<=n-1; i++)
    {
        long u,v,w;
        cin >> u >> v >> w;
        a[u].push_back(ii(v,w));
        a[v].push_back(ii(u,w));
    }
    if (k<=10)
    {
        tryy_(1);
        if (ans!=vc) cout <<ans;
        else cout << -1;
    }
    else
        cout << -1;
}
