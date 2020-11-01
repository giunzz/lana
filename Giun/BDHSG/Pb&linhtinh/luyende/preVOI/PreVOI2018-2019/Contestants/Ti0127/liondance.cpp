#include <bits/stdc++.h>
#define mn 4005
#define int long long
using namespace std;
int n,f[(1<<20)+5],d;
int l[mn],r[mn];
vector <int> g,v;
int getbit(int i,int j)
{
    return (i>>j)&1;
}
int cmp(vector<int> &g,vector<int> &v)
{
    for(int i=0;i<g.size();i++)
    {
        if(l[g[i]]>l[v[i]])
            return 1;
        else
            if(l[g[i]]<l[v[i]])
            return 0;
    }
    return 0;
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
    freopen("liondance.inp","r",stdin);
    freopen("liondance.out","w",stdout);
    read(n);
    read(d);
    for(int i=1;i<=n;i++)
        read(l[i]);
    for(int i=1;i<=n;i++)
        read(r[i]);
    for(int i=0;i<(1<<n);i++)
    {
        g.clear();
        for(int j=1;j<=n;j++)
            if(getbit(i,j-1))
            g.push_back(j);
        int t=1;
        int ok=1;
        for(int j=1;j<g.size();j++)
            if(abs(l[g[j]]-l[g[j-1]])>d)
            {
                ok=0;
                break;
            }
        if(!ok)
            continue;
        ok=1;
        for(auto u:g)
        {
            int kt=0;
            for(int j=t;j<=n;j++)
                if(l[u]==r[j])
            {
                kt=1;
                t=j+1;
                break;
            }
            if(!kt)
            {
                ok=0;
                break;
            }
        }
            if(ok)
            {
            if(g.size()>v.size())
                v=g;
            if(g.size()==v.size()&&cmp(g,v))
                v=g;
            }
    }
    cout<<v.size()<<'\n';
        for(auto x:v)
        cout<<l[x]<<" ";
    return 0;
}
