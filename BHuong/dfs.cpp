#include<bits/stdc++.h>
using namespace std;

int  m , n , u, v , dd[5007]={0} , s , f , trace[5007]={0};
vector<int>g[5007];
stack<int> sk;
/*void dfs (int u)
{
    cout << u << " ";
    dd[u] = 1;
    for (int v : g[u])
    {
        if (!dd[v]) trace[v] = u ,dfs(v);
    }
}*/
void dfs()
{
    cout << s << " ";
    dd[s] = 1 , sk.push(s);
    while (!sk.empty())
    {
        u = sk.top();
        sk.pop();
        for (int v : g[u])
        {
            if (!dd[v])
            {
                cout << v << " ";
                dd[v] = 1;
                trace[v] = u;
                sk.push(u) , sk.push(v);
                break;
            }
        }
    }
}

int main()
{
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >>  n >> m  >> s >> f; // n dinh m canh s : dinh dau f : dinh cuoi
        for (int i = 1 ; i <= m ; i++)
        {
            cin  >> u >> v;
            g[u].push_back(v) , g[v].push_back(u);
        }
    dfs();
    cout << endl;
    if (!trace[f]) cout << "NO";
    else 
    {
        while (s != f)
        {
            cout << f << " ";
            f = trace[f];
        }
        cout << s ;
    }
}


