#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("BUBBLETEA.inp","r",stdin);
    freopen("BUBBLETEA.out","w",stdout);
    ios::sync_with_stdio(0);
    int n,k; cin>>n>>k;
    for (int i=1; i <= k; i++){
        int x; cin>>x;
    }
    int mx=0;
    for (int i=1; i < n; i++){
        int u,v,c; cin>>u>>v>>c;
        mx=max(mx,c);
    }
    if (k == n)
        cout<<mx;
      else
        cout<<-1;
    return 0;
}
