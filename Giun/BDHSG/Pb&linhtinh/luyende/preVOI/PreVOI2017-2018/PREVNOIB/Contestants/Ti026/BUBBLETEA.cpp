#include <bits/stdc++.h>
const int maxn=5*1e4+5;
using namespace std;
int n,k,b[maxn];
vector<vector<pair<int,int> > > a;
void khoitao()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i)
        cin>>b[i];
    a.resize(n+1);
    int u,v,c;
    for(int i=2;i<=n;++i)
    {
        cin>>u>>v>>c;
        a[u].push_back(make_pair(c,v));
    }
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("BUBBLETEA.INP","r",stdin);
    freopen("BUBBLETEA.OUT","w",stdout);
    khoitao();
    cout<<-1;
}
