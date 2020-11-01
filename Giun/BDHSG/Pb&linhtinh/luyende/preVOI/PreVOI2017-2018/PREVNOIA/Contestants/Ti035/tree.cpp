#include<bits/stdc++.h>
using namespace std;
#define F1(i,a,b) for(int i=a;i<=b;++i)
#define F2(i,a,b) for(int i=a;i>=b;--i)
const int maxn=5e3+10;
int res=1e9,a[maxn],n,x[maxn],s[maxn];
vector<int> e[maxn],v;
int dfs(int i)
{
    int re=0;
    if (e[i].size())
    F1(j,0,e[i].size()-1)
    {
        re+=dfs(e[i][j]);
        s[i]+=s[e[i][j]];
    }
    return re+abs(a[i]-s[i]);
}
void sol(int x[])
{
    F1(i,1,n) s[i]=0;
    F1(i,0,v.size()-1)
     s[v[i]]=x[i];
    res=min(res,dfs(1));
}
void duyet(int i,int x[])
{
    if (i>v.size()-1)
    {
        sol(x);
        return;
    }
    x[i]=0;
    duyet(i+1,x);
    x[i]=1;
    duyet(i+1,x);
}
int main()
{
    freopen("tree.inp","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    F1(i,1,n) scanf("%d",&a[i]);
    F1(i,1,n-1)
     {
         int x,y;
         scanf("%d%d",&x,&y);
         e[x].push_back(y);
     }
    F1(i,1,n)
     if (!e[i].size()) v.push_back(i);
    duyet(0,x);
    cout<<res;
    return 0;
}
