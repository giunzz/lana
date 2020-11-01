#include <bits/stdc++.h>
#define maxn 50005
#define pii pair <int,int>
using namespace std;
int n,k,summax;
int t[maxn],d[maxn],pra[maxn];
vector<pii> a[maxn];
void dfs(int u){
    for(int i=0;i<a[u].size();i++){
        int v=a[u][i].first;
        int w=a[u][i].second;
        if(pra[u]!= v){
            d[v]=d[u]+w;
            pra[v]=u;
            dfs(v);
        }
    }
}
int main()
{
    freopen("BUBBLETEA.INP","r",stdin);
    freopen("BUBBLETEA.OUT","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        cin>>t[i];
    }
    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        summax=max(summax,w);
        a[u].push_back(pii(v,w));
        a[v].push_back(pii(u,w));
    }
    if(k==n){
        cout<<summax;
    }
    else cout<<-1;
    return 0;
}
