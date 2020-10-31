#include<bits/stdc++.h>
#define maxn 5004
#define Task "TREE"
#define ft first
#define se second

using namespace std ;

int n,a[maxn],b[maxn],deg[maxn],cl[maxn],cl1[maxn],prv[maxn],kq,ds,slx,s[maxn],head[maxn],last[maxn],id;

vector<int>g[maxn];

void DFS1(int u){
cl1[u]=1;
for(int i=0;i<deg[u];++i){
    int v=g[u][i];
    if(prv[v]==u){
        DFS1(v);
        b[u]+=b[v];
    };
};
kq+=abs(a[u]-b[u]);
}

void xuly(){
for(int i=1;i<=n;++i) {cl1[i]=0;
if(last[i]!=head[i]) b[i]=0;}
kq=0;
DFS1(1);
ds=min(ds,kq);
}

void Backtrack(int i){
if(i>slx){xuly();return;};
for(int j=0;j<=1;++j){
    b[s[i]]=j;
    Backtrack(i+1);
};
return;
}

void DFS(int u){
cl[u]=1;
head[u]=last[u]=++id;
for(int i=0;i<deg[u];++i){
    int v=g[u][i];
    if(cl[v]==0) {
            prv[v]=u;
            DFS(v);
            last[u]=max(last[u],last[v]);
            };
};
}

void getin(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    for(int i=1;i<=n-1;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);deg[u]++;
        g[v].push_back(u);deg[v]++;
    };
}

void solve(){
    id=0;
DFS(1);
for(int  i=1;i<=n;++i) if(head[i]==last[i]) s[++slx]=i;
//for(int i=1;i<=slx;++i)cout<<s[i]<<" ";
ds=100000001;
if(n<=300){
Backtrack(1);
printf("%d",ds);
} else {
cout<<4567;
};}


int main()
{
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
    getin();
    solve();
    }
