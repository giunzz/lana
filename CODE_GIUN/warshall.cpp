#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
int m , n , u , v  , dd[5007]={0};
vector<int>g[5007];
void warshall()
{
    for (int k = 1 ; k <= n ; k++)
    {
        for (int u = 1 ; u <= n ; u++)
        {
            if (g[u] == g[k] )
                for (int v = 1 ; v <= n ; v++)
                    if (g[k] == g[v]) g[u] = g[v];
        }
    }
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("g.out","w",stdout);
    cin >> n >> m ;
    for (int i = 1 ; i <= m ; i++) 
    {
        cin >> u >> v;
        g[u].push_back(v) , g[v].push_back(u);
    }
    warshall();
    int count = 0 ;
    for (int u = 1; u <= n ; u++)
    {
        if (!dd[u])
        {
            count++;
            cout << "dothi " << count << endl;
            for (int v : g[u]) cout << v << " " , dd[v] = 1;
            cout << endl;
        }
    }
}