#include <bits/stdc++.h>

using namespace std;

void pool(){
    freopen("TREE.INP","r",stdin);
    freopen("TREE.OUT","w",stdout);
    return;
}

const long long MAXN=5005;
long long n,a[MAXN];
vector<long long> g[MAXN];

void ip(){
    cin>>n;
    for (long long i=1;i<=n;i++) cin>>a[i];
    for (long long i=1;i<=n-1;i++){
        long long u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    return;
}
long long maxx[MAXN];
long long cp=0;
bool ok[MAXN];
long long la[MAXN],slla=0;

void DFS(long long x){
    ok[x]=1;maxx[x]=1;
    long long tong=0;
    bool zz=0;

    for (long long i=0;i<g[x].size();i++)
    if (ok[g[x][i]]==0){
        DFS(g[x][i]);
        tong+=maxx[g[x][i]];
        zz=1;
    }
    if (zz==0) la[++slla]=x;
    maxx[x]=max(maxx[x],tong);//cout<<maxx[x]<<" "<<a[x]<<'\n';
    if (maxx[x]<a[x]) {cp+=(a[x]-maxx[x]);a[x]=maxx[x];}//cout<<x<<" "<<a[x]<<'\n';
    return;
}

long long ok2[MAXN];

long long DFS2(long long x){
    ok[x]=1;bool zz=0;
    long long tong=0;
    for (long long i=0;i<g[x].size();i++)
    if (ok[g[x][i]]==0){
        zz=1;
        tong+=DFS2(g[x][i]);
    }
    if (zz==0) return a[x]=a[x];
    else return a[x]=tong;
}

long long b[MAXN];

void NIX(){
    DFS(1);
    long long p=(1<<slla)-1;
    for (long long i=1;i<=n;i++) b[i]=a[i];

    long long minx=1e9+7;
    for (long long i=0;i<=p;i++){
        for (long long j=0;j<slla;j++)
        if ((i>>j)&1) a[la[j+1]]=1;
        else a[la[j+1]]=0;
        for (long long j=1;j<=n;j++) ok[j]=0;
        a[1]=DFS2(1);
        long long tamm=0;
        for (long long j=1;j<=n;j++) tamm+=(fabs(a[j]-b[j]));
        minx=min(minx,tamm);
    }

    cout<<cp+minx;

    return;
}

int main()
{
    pool();
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ip();
    NIX();
    return 0;
}
