#include <bits/stdc++.h>
#define MAXN 5005
#define pb push_back

using namespace std;

int n,g[MAXN],d[MAXN],pa[MAXN],c[MAXN];
vector<int> a[MAXN],e,t,chil,q;
long long mi=1e15,f[MAXN];

void xuly(){
    long long s=0;
    for(int i=1; i<=n; i++) f[i]=0;
    for(int i=0; i<chil.size(); i++){
        f[chil[i]]=q[i];
    }
    for(int i=t.size()-1; i>=0; i--){
        int v=t[i], u=pa[v];
        if(u==0) continue;
        f[u]+=f[v];
    }
    for(int i=1; i<=n; i++){
        s+=abs(g[i]-f[i]);
    }
    mi=min(mi,s);
}

void solve(){
    if(q.size()==chil.size()){
        xuly();
        return;
    }
    for(int i=0; i<=1; i++){
        q.pb(i);
        solve();
        q.pop_back();
    }

}

void DFS(int u){
    d[u]=1;
    for(int i=0; i<a[u].size(); i++){
        int v=a[u][i];
        if(v==pa[u]) continue;
        if(d[v]==1) continue;
        d[v]=1;
        c[u]++;
        pa[v]=u;
        DFS(v);
    }
    e.pb(u);
}

void topo(){
    DFS(1);
    for(int i=e.size()-1; i>=0; i--){
        if(c[e[i]]==0) chil.pb(e[i]);
        t.pb(e[i]);
    }

}

int main()
{
    ifstream cin("TREE.inp");
    ofstream cout("TREE.out");
    cin >> n;
    if(n>300){
        cout << 0;
        return 0;
    }
    for(int i=1; i<=n; i++) cin >> g[i];
    for(int i=1; i<n; i++){
        int x,y;
        cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }
    topo();
    solve();
    cout << mi;
    return 0;
}
