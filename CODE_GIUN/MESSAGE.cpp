#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
const int maxn = 1e6+7;
int N,M,u,v , visited[maxn]={0} , cnt = 0 , low[maxn]={0} , ans = 0;
int dd[maxn]={0} , lt[maxn]={0};
vector<int>G[maxn] ;
pair<int,int> TPLT[maxn];
stack<int> a;
void TARJAN (int u)
{
    visited[u] = low[u] = ++cnt ;
    a.push(u);
    for (int v : G[u])
    {
        if (visited[v]) low[u] = min(low[u],visited[v]);
        else
        {
            TARJAN(v);
            low[u] = min(low[u],low[v]);
        }
    }
    if (visited[u] == low[u])
    {
        ans++;
        do {
            v = a.top();
            a.pop();
            visited[v] = low[v] = INT_MAX;
            lt[v] = ans;
            } while (u != v);
    }
}
int main()
{
    int tin = 0 ;
    giuncute;
    //freopen("giun.inp","r",stdin);
    //freopen("giun.out","w",stdout);
    cin >> N >> M;
    for (int i = 1 ; i <= M ; i++) cin >> u >> v , G[u].push_back(v) , TPLT[i].first= u , TPLT[i].second = v;
    for (int i = 1 ; i <= N ; i++)
        if (!visited[i] ) TARJAN(i);
    for (int i = 1 ; i <= M ; i++)
    {
        u = TPLT[i].first ;
        v = TPLT[i].second;
        if (lt[u] != lt[v]) dd[lt[v]] = 1;
    }
    for (int i = 1 ; i <= ans ; i++)
    {
        if (dd[i] == 0) tin++;
    }
    cout << tin << endl;

}