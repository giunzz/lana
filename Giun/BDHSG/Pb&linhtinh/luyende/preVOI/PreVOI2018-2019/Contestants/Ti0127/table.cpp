#include <bits/stdc++.h>
#define int long long
#define mn 305
#define fi first
#define se second
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
int n,m,k,a[mn][mn],l[mn][mn],u,v,p,q,s,t;
int cnt,res;
vector<pair<int,int> >g;
void vet(int u,int v,int p,int q)
{
    int i=p,j=q;
    g.clear();
    g.push_back({p,q});
    while(i>=u&&j>=v)
    {
        if(l[i][j]==l[i-1][j]+a[i][j])
        {
            if(i-1>0)
            g.push_back({i-1,j});
            i--;
        }
        else
        {
            if(j-1>0)
            g.push_back({i,j-1});
            j--;
        }
    }
}
template <typename T> inline void read(T &x)
{
    char c=getchar();
    x=0;
    while(!isdigit(c)) c=getchar();
    while(isdigit(c))
    {
        x=x*10+(c-'0');
        c=getchar();
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    read(m);
    read(n);
    read(k);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        read(a[i][j]);
    while(k--)
    {
        read(u);
        read(v);
        read(p);
        read(q);
        for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            l[i][j]=0;
        for(int i=u;i<=p;i++)
            for(int j=v;j<=q;j++)
            l[i][j]=max(l[i-1][j],l[i][j-1])+a[i][j];
        vet(u,v,p,q);
        res=1e17;
        for(auto x:g)
        {
            if((x.fi==u&&x.se==v)||(x.fi==p&&x.se==q))
                continue;
            for(int i=1;i<=m;i++)
                for(int j=1;j<=n;j++)
                l[i][j]=0;
            for(int i=u;i<=p;i++)
                for(int j=v;j<=q;j++)
            {
                if(i-1!=x.fi||j!=x.se)
                    l[i][j]=l[i-1][j]+a[i][j];
                if(i!=x.fi||j-1!=x.se)
                    l[i][j]=max(l[i][j],l[i][j-1]+a[i][j]);
            }
            res=min(res,l[p][q]);
        }
        cout<<res<<'\n';
    }
    return 0;
}
