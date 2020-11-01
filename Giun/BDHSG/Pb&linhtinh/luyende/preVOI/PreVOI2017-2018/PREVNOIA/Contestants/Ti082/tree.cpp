#include<bits/stdc++.h>
#define maxn 6005
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
int n,a[maxn];
vector<int > E[maxn],e[maxn];
ll res,f[maxn][maxn];
void dfs(int u,int trc)
{
        for (int i=0;i<E[u].size();++i)
        {
                int v=E[u][i];
                if (v==trc) continue;
                e[u].push_back(v);
                dfs(v,u);
        }
}
ll cal(int u,int val)
{
        if (f[u][val]!=-1) return f[u][val];
        if (e[u].size()==0)
        {
                if (val>1) return 1e18;
                f[u][val]=abs(a[u]-val);
                return f[u][val];
        }
        if (e[u].size()==1)
        {
                int v=e[u][0];
                f[u][val]=abs(a[u]-val)+cal(v,val);
                return f[u][val];
        }
        ll res=1e18;
        for (int i=0;i<=val;++i)
        {
                int v1=e[u][0];
                int v2=e[u][1];
                res=min(res,cal(v1,i)+cal(v2,val-i));
        }
        res+=abs(a[u]-val);
        f[u][val]=res;
        return f[u][val];
}
int main()
{
        freopen("TREE.inp","r",stdin);
        freopen("TREE.out","w",stdout);
        cin.tie(0);
        cout.tie(0);
        read(n);
        for (int i=1;i<=n;++i)
                read(a[i]);
        for (int i=2;i<=n;++i)
        {
                int u,v;
                read(u);read(v);
                E[u].push_back(v);
                E[v].push_back(u);
        }
        dfs(1,-1);
        res=1e18;
        memset(f,-1,sizeof f);
        for (int i=0;i<=n;++i)
                res=min(res,cal(1,i));
        write(res);
}
