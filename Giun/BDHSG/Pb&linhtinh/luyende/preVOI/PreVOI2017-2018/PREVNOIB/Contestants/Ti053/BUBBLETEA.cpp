#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge{
    ll u,val;
};
inline edge make_edge(ll u,ll val){
    edge res;
    res.u=u;res.val=val;
    return res;
}
#define NMAX 50005
#define pb push_back
ll n,k;
ll a[NMAX];
ll p[NMAX][20],h[NMAX],d[NMAX];
vector <edge> adj[NMAX];
void enter(){
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        ll u,v,val;
        cin>>u>>v>>val;
        adj[u].pb(make_edge(v,val));
        adj[v].pb(make_edge(u,val));
    }
}
inline void DFS(int u,int fa){
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i].u;
        if(v!=fa){
            p[v][0]=u;
            d[v]=d[u]+1;
            h[v]=h[u]+adj[u][i].val;
            DFS(v,u);
        }
    }
}
inline int getlca(int u,int v){
    if(d[u]<d[v]) swap(u,v);
    for(int i=19;i>=0;i--){
        if(d[u]-(1<<i)>=d[v]) u=p[u][i];
    }
    if(u==v) return u;
    for(int i=19;i>=0;i--){
        if(p[u][i]!=-1&&p[u][i]!=p[v][i]){
            u=p[u][i];
            v=p[v][i];
        }
    }
    return p[u][0];
}
int x[11],y[11];
void progress(){
    for(int i=0;i<NMAX;i++){
        for(int j=0;j<20;j++){
            p[i][j]=-1;
        }
    }
    DFS(1,1);
    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i<=n;i++){
            p[i][j]=p[p[i][j-1]][j-1];
        }
    }
    for(int i=1;i<=k;i++){
        x[i]=i;
    }
  //  exit(0);
    ll res=1e15;
    do{
        ll dis=0;
        for(int i=1;i<=k/2;i++){
            int lca=getlca(a[x[i]],a[x[i+k/2]]);
            dis=max(dis,h[a[x[i]]]+h[a[x[i+k/2]]]-2*h[lca]);
        }
        res=min(res,dis);
    }while(next_permutation(x+1,x+k+1));
    cout<<res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BUBBLETEA.inp","r",stdin);
    freopen("BUBBLETEA.out","w",stdout);
    enter();
    progress();
}
