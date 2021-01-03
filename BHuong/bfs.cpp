#include<bits/stdc++.h>
using namespace std;

int  m , n , u, v , s , f , trace[5007]={0} , dd[5007]={0};
vector<int>g[5007];
deque<int> dq;
void bfs()
{
    dd[s] = 1 ;
    dq.push_back(s);
    while (!dq.empty())
    {
        u = dq.front();
        dq.pop_front();
        cout << u << " ";
        for (int v : g[u])
        {
            if(!dd[v])
            {
                dd[v] = 1;
                trace[v] = u ;
                dq.push_back(v);
            }
        }
    }
}
int main()
{
    freopen("giun.inp","r",stdin);
    freopen("g.out","w",stdout);
    cin >>  n >> m  >> s >> f; // n dinh m canh s : dinh dau f : dinh cuoi
        for (int i = 1 ; i <= m ; i++)
        {
            cin  >> u >> v;
            g[u].push_back(v) , g[v].push_back(u);
        }
    bfs();
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
