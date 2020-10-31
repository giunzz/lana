#include<bits/stdc++.h>

using namespace std;

const int MAXN = 5010;
int n,child[4] , nChild[MAXN] , dp[MAXN][MAXN] , vis[MAXN] , ans = INT_MAX , a[MAXN];
vector<int> g[MAXN];

void dfs(int u)
{
    vis[u] = 1;
    int cnt = 0 , c1 = 0 ,c2 = 0;
    for(int i = 0 ; i<g[u].size() ; i++)
    {
        int v = g[u][i];
        if(!vis[v])
        {
            dfs(v);
            cnt++;
            if(cnt == 1) c1 = v;
            else c2 = v;
        }
    }
    nChild[u] = cnt;
    //cerr<<u<<" "<<cnt<<endl;
    if(cnt == 0)
    {
        dp[u][0] = a[u] - 0;
        dp[u][1] = abs(a[u] - 1);
        return ;
    }

    if(cnt == 1)
    {
        for(int s1 = 0 ; s1<=max(nChild[c1] , 1) ; s1++)
            dp[u][s1] = min(dp[u][s1] , dp[c1][s1] + abs(s1 - a[u]));
        return;
    }

    for(int s1 = 0 ; s1<=max(nChild[c1] , 1) ; s1++)
    if(dp[c1][s1] < 1e9)
        for(int s2 = 0 ; s2 <=max(nChild[c2],1) ; s2++)
        if(dp[c2][s2] < 1e9)
        {
            int sum = s1+s2;
            dp[u][sum] = min(dp[u][sum] , dp[c1][s1] + dp[c2][s2] + abs(sum - a[u]));
        }
    nChild[u] += nChild[c1] + nChild[c2];
}

int main()
{
    freopen("TREE.inp" , "r" , stdin);
    freopen("TREE.out" , "w" , stdout);
    scanf("%d",&n);
    for(int i = 1 ; i<=n ;i++)
        scanf("%d",&a[i]);
    for(int i = 1 ;i<n ;i++)
    {
        int u , v;
        scanf("%d%d",&u , &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(vis , 0 , sizeof(vis));
    memset(nChild , 0 , sizeof(nChild));
    memset(dp , 0x3f , sizeof(dp));
    dfs(1);
    for(int i = 0 ; i<=n ; i++)
        ans = min(ans , dp[1][i]);
    printf("%d",ans);
    return 0;
}
