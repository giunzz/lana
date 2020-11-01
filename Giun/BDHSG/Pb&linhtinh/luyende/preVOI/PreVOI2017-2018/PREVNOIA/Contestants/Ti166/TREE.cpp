#include <bits/stdc++.h>
#define forr(i,a,b) for( int i=(a);i<=(b);++i)
#define ford(i,a,b) for( int i=(a);i>=(b);--i)
#define f first
#define s second
#define ll long long
#define pii pair<int,int>
#define task "TREE"

using namespace std;

const long long mod=1e14+7;
const long dad=5002;
int n ;
ll a[dad],dp[dad][18002],mx[dad];
vector<int> aa[dad] ;


int getint()
{
   int ww = 0; char cc = getchar();
   while (cc > '9' || cc < '0') cc = getchar();
   while (cc >= '0' && cc <= '9') { ww = ww * 10 + cc - '0'; cc = getchar(); }
   return ww;
}

ll getll()
{
   ll ww = 0; char cc = getchar();
   while (cc > '9' || cc < '0') cc = getchar();
   while (cc >= '0' && cc <= '9') { ww = ww * 10 + cc - '0'; cc = getchar(); }
   return ww;
}

int getbit(int bit,int id)
{
    return bit>>id&1;
}

void dfs(int u)
{
    if (aa[u].size()==0)
    {
        mx[u]=1;
        dp[u][0]=a[u];
        dp[u][1]=abs(a[u]-1);
        return;
    }else
    if (aa[u].size()==1)
    {
        int v=aa[u][0];
        dfs(v);
        mx[u]=mx[v];
        forr(i,0,mx[u]) dp[u][i]=dp[v][i]+abs(i-a[u]);
    }else
    {
        int v1=aa[u][0];
        int v2=aa[u][1];
        dfs(v1);
        dfs(v2);
        mx[u]=mx[v1]+mx[v2];
        forr(i,0,mx[u]) dp[u][i]=mod;
        forr(i,0,mx[v1])
            forr(j,0,mx[v2])
                dp[u][i+j]=min(dp[u][j+i],dp[v1][i]+dp[v2][j]+abs(j+i-a[u]));
    }
}

void input()
{
    n=getint();
    forr(i,1,n) a[i]=getll();
    forr(i,1,n-1)
    {
        int u,v;
        u=getint();
        v=getint();
        aa[u].push_back(v);
    }
    dfs(1);
    ll ans=mod;
    forr(i,1,mx[1])
    ans=min(ans,dp[1][i]);
    cout<< ans;
}

void output()
{

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen( task".inp" , "r" , stdin );
    freopen( task".out" , "w" , stdout );
    input();
    output();
    return 0;
}
