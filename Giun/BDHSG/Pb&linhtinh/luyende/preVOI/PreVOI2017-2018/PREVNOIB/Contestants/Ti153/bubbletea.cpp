#include <bits/stdc++.h>
#define maxn 50005
using namespace std;
int n,k,a[maxn],x[maxn],pre[22][maxn],cl[22][maxn],q[maxn];
long long ds=1e18,kc[22][maxn];
map <int,int> d;
int doiso(int i,int j){return i*maxn +j;}
typedef pair<int,int> II;
vector <II> g[maxn];
void xuli(){
    long long o=0;int ok=1;
    for(int i=1;i<=k;i++)
    for(int j=i+1;j<=k;j++)if(x[i]==x[j]){
        o=max(o,kc[i][a[j]]);
        int u=a[j];
        while(pre[i][u]) {
            if(d[doiso(u,pre[i][u])]==1) ok=0;
            d[doiso(u,pre[i][u])]=1;d[doiso(pre[i][u],u)]=1;u=pre[i][u];
        }
    }
    for(int i=1;i<=k;i++)
    for(int j=i+1;j<=k;j++)if(x[i]==x[j]){
        int u=a[j];
        while(pre[i][u]) {
            d[doiso(u,pre[i][u])]=0;d[doiso(pre[i][u],u)]=0;u=pre[i][u];
        }
    }
    if(ok)ds=min(ds,o);
}
void thu(int u){
    if(u>k){xuli();return;}
    for(int i=1;i<=k/2;i++)if(d[i]<2){
        d[i]++;
        x[u]=i;
        thu(u+1);
        d[i]--;
        x[u]=0;
    }
}
void bfs(int xp){
    int l=1,r=0;
    q[++r]=a[xp];cl[xp][a[xp]]=1;kc[xp][a[xp]]=0,pre[xp][a[xp]]=0;
    while(l<=r){
        int u=q[l++];
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i].first;
            int w=g[u][i].second;
            if(cl[xp][v]==0) cl[xp][v]=1,q[++r]=v,kc[xp][v]=kc[xp][u]+w,pre[xp][v]=u;
        }
    }
}
int main(){
    freopen("bubbletea.inp","r",stdin);
    freopen("bubbletea.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n-1;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        g[u].push_back(II(v,w));
        g[v].push_back(II(u,w));
    }
    for(int i=1;i<=k;i++) bfs(i);
    thu(1);
    printf("%I64d",ds);
}
