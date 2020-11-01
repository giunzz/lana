#include<bits/stdc++.h>
#define maxn 50005
#define ll long long
using namespace std;
template<typename T> inline void read(T &x)
{
        char c;
        bool neg = false;
        while (!isdigit(c = getchar()) && c != '-');
        x = 0;
        if (c == '-')
        {
                neg = true;
                c = getchar();
        }
        do
        {
                x = x * 10 + c - '0';
        }
        while (isdigit(c = getchar()));
        if (neg) x = -x;
}
template<typename T> inline void write(T x)
{
        if (x < 0)
        {
                putchar('-');
                write(-x);
                return;
        }
        if (x < 10)
        {
                putchar(char(x + 48));
        }
        else
        {
                write(x/10);
                putchar(char(48 + x%10));
        }
}
template<typename T> inline void writeln(T x)
{
        write(x);
        putchar('\n');
}
ll d[maxn],res;
int n,a[maxn],trc[maxn],k,dem[maxn],S[maxn][3],D[maxn];
struct data
{
        int v,c;
};
vector<data >e[maxn];
int p[maxn][30],h[maxn];
void dfs(int u,int t)
{
        for (int i=0;i<e[u].size();++i)
        {
                int v=e[u][i].v;
                int c=e[u][i].c;
                if (v==t) continue;
                trc[v]=u;
                h[v]=h[u]+1;
                d[v]=d[u]+c;
                dfs(v,u);
        }
}
int lca(int u,int v)
{
        if (h[u]<h[v]) swap(u,v);
        int log=log2(u);
        for (int i=log;i>=0;--i)
        if (h[u]-(1<<i)>=h[v]) u=p[u][i];
        if(u==v) return u;
        for (int i=log;i>=0;--i)
        if (p[u][i]!=-1&&p[v][i]!=-1&&p[u][i]!=p[v][i])
        {
                u=p[u][i];
                v=p[v][i];
        }
        return trc[u];
}
ll dis(int u,int v)
{
        int w=lca(u,v);
        ll res=0;
        res+=d[u]-d[w];
        res+=d[v]-d[w];
        return res;
}
void DFS(int x)
{
        if (x==k+1)
        {
                ll ans=0;
                for (int i=1;i<=k/2;++i)
                {
                        int u=S[i][1];
                        int v=S[i][2];
                        ans=max(ans,dis(u,v));
                }
                res=min(res,ans);
                return;
        }
        for (int i=1;i<=k/2;++i)
        {
                if(dem[i]==2) continue;
                S[i][dem[i]+1]=D[x];
                ++dem[i];
                DFS(x+1);
                dem[i]--;
        }
}
void sub1()
{
        res=1e18;
        DFS(1);
        write(res);
}
int main()
{
        freopen("BUBBLETEA.inp","r",stdin);
        freopen("BUBBLETEA.out","w",stdout);
        cin.tie(0);
        cout.tie(0);
        read(n);read(k);
        for (int i=1;i<=k;++i)
                read(D[i]);
        for (int i=2;i<=n;++i)
        {
                int u,v,c;
                read(u);read(v);read(c);
                e[u].push_back({v,c});
                e[v].push_back({u,c});
        }
        dfs(1,-1);
        memset(p,-1,sizeof p);
        for (int i=1;i<=n;++i)
                p[i][0]=trc[i];
        for (int j=1;1<<j<=n;++j)
        {
                for (int i=1;i+(1<<j)<=n;++i)
                if (p[i][j-1]!=-1)
                {
                        p[i][j]=p[p[i][j-1]][j-1];
                }
        }
        sub1();
}
