#include <bits/stdc++.h>
#define maxn 5005
using namespace std;
int n,f[maxn][maxn],nho[maxn][maxn],a[maxn];
vector <int> g[maxn];
int tinh(int i,int x){
    if(nho[i][x]) return f[i][x];
    if(g[i].size()==0&&x<=1) return abs(a[i]-x);
    if(g[i].size()==0) return 5005;
    nho[i][x]=1;f[i][x]=1e9;
    if(g[i].size()==2)for(int y=0;y<=x;y++)
        f[i][x]=min(f[i][x],tinh(g[i][0],y)+tinh(g[i][1],x-y)+abs(a[i]-x));
    if(g[i].size()==1) f[i][x]=min(f[i][x],tinh(g[i][0],x)+abs(a[i]-x));
    return f[i][x];
}
int main(){
    freopen("tree.inp","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n-1;i++){
        int u,v;scanf("%d%d",&u,&v);
        g[u].push_back(v);
    }
    int o=0;
    for(int i=1;i<=n;i++) if(g[i].size()==0) o++;
    int ds=1e9;
    for(int i=0;i<=o;i++) ds=min(ds,tinh(1,i));
    printf("%d",ds);
}
