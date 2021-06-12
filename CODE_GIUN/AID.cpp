#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
ll  t , n , k , visited[(int) 1e3 + 7];

void bfs ( vector<ll> G[(int) 1e3 + 7] , int k )
{
    queue<ll> q;
    int cnt = 1;
    vector<ll> res;
    q.push(1);
    res.push_back(lo1);
    for (int i = 1 ; i <= n ; i++) visited[i] = 0 ;
    visited[1] = 1;
    while (!q.size() && cnt != k)
    {
        int u = q.front();
        q.pop();
        for (int v : G[u])
        {
            if (!visited[v]) res.push_back(v) , visited[v] = 1 , q.push(v);
        }
    }
    cout << res.size()-1 << endl;
    for (int i = 0 ; i < res.size() ; i++) cout << res[i] << " ";
    cout << endl;
}

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin>> t ; 
    int x ;
    while (t--)
    {
        vector<ll> G[(int) 1e3+7];
        cin >> n >> k ;
        for (int i = 1 ; i <= n ; i++) 
        {
            cin >> x;
            G[x].push_back(i+1);
            G[i+1].push_back(x);
        }
        bfs(G,k);
    }
}