#include<bits/stdc++.h>
using namespace std;
const int N=5e4+2;
struct line
{
    int u, v, w;
    line() {};
    line(int u, int v, int w): u(u), v(v), w(w) {};
} node[N];
int n, k, d[N], vis[N];
bool cmp( line a, line b )
{
    if ( a.w==b.w ) return a.u < b.u;
    return a.w<b.w;
}
/*void sub2()
{
    cerr << 1;
    sort(node+1, node+n, cmp);
    for ( int i=1; i<n; i++ )
    {
        if ( vis[ node[i].u ] || vis[node[i].v]  )  continue;
        vis[ node[i].u ]=vis[node[i].v]=1;
    }
}*/
int main()
{
    freopen("bubbletea.inp","r",stdin);
    freopen("bubbletea.out","w",stdout);
    cin >> n >> k;
    for ( int i=1; i<=k; i++ )
    {
        int x;
        cin >> x;
        d[x]=1;
    }
    for ( int i=1; i<n; i++ )
    {
        int x, y, w;
        cin >> x >> y >> w;
        node[i]=line(x, y, w);
    }
    cout << "-1";
}
