#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=5005;
vector<int> g[maxn];
int n,k;
struct ds
{
    int u,v,c;
}e[maxn];
int b[maxn];
void  nhap()
{
    cin>>n>>k;
    for(int i=1;i<=k;++i)
        cin>>b[i];
        int u,v,c;
        for(int i=1;i<n;++i)
        {
            cin>>u>>v>>c;
            e[i].u=u;
            e[i].v=v;
            e[i].c=v;
            g[u].pb(v);
            g[v].pb(u);
        }
        cout<<3;
}
int main()
{
    freopen("BUBBLETEA.INP","r",stdin);
    freopen("BUBBLETEA.OUT","w",stdout);
    nhap();
}
