#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
using namespace std;
ll n , q , c , u , v , dd[(int) 1e6+7] , ok ;
vector<ll> g[(int) 1e6+7];
void dfs(int u)
{
    dd[u] = 1;
    for (int x : g[u])
    {
        if (!dd[x]) 
        {
           // cerr << x << " ";
            if (x == v)
            {
                ok = 1;
                break;
            } 
            dfs(x);
        }
    }
}
int main()
{
    giuncute;
    freopen("gpath.inp","r",stdin);
    freopen("gpath.out","w",stdout);
    cin >> n >> q;
    for (int i = 1 ; i <= q ; i++)
    {
        cin >> c >> u >> v;
        if (c == 0) g[u].push_back(v) , g[v].push_back(u);
        if (c == 1)
        {
            /*vector<int> dd(n,0);
            int ok = 0;
            stack<int> sk;
            dd[u] = 1 , sk.push(u);
            while (!sk.empty())
            {
                u = sk.top();
                sk.pop();
                for (int x : g[u])
                {
                    if (!dd[x])
                    {
                        if (x == v)
                        {
                            cout <<"YES" << endl;
                            ok = 1 ;
                            break;
                        }
                        dd[x] = 1;
                        sk.push(u) , sk.push(x);
                        break;
                    }
                }
            }
            if (ok == 0 ) cout << "NO" << endl;*/
            for (int i = 1 ; i <= n ; i++) dd[i] = 0;
            ok = 0;
            dfs(u);
            if (ok == 1) cout << "YES" << endl;
            else cout << "NO" << endl;
 //           cerr << endl;
        }
    }
}