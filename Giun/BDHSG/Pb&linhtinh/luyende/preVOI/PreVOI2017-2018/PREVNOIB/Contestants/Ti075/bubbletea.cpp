#include <bits/stdc++.h>
#define tr(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define maxn 100001
#define mp make_pair
using namespace std;
typedef pair<int,int> II;
II c[maxn];
set <II> s;
vector <II> g[maxn];
int n,m,k,a[maxn],b,gt;
int cl[maxn],pre[maxn];long long kc[maxn],kcb[maxn],ds=0;

void Dijkstra1(int xp) {
    memset(cl,0,sizeof(cl));
    memset(kc,0,sizeof(kc));
    cl[xp]=1;
    kc[xp]=0;
    pre[xp]=-1;
    s.insert(mp(kc[xp],xp));
    while(!s.empty()) {
        II x=*s.begin();
        s.erase(x);
        int u=x.second;
        cl[u]=2;
        tr(i,g[u]) {
            II y=*i;
            int q=y.first;
            int v=y.second;
            if(cl[v]==0) {
                cl[v]=1;
                pre[v]=u;
                kc[v]=kc[u]+q;
                s.insert(mp(kc[v],v));
            }
            else if(cl[v]==1) {
                if(kc[v]>kc[u]+q){
                    s.erase(mp(kc[v],v));
                    kc[v]=kc[u]+q;
                    s.insert(II(kc[v],v));
                    pre[v]=u;
                }
            }
        }
    }
}
void dungdt() {
    cin>>m>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=1;i<=m-1;i++) {
        int u,v,t;
        cin>>u>>v>>t;
        g[u].push_back(make_pair(t,v));
        g[v].push_back(make_pair(t,u));
    }
}

int main() {
    freopen("bubbletea.inp","r",stdin);
    freopen("bubbletea.out","w",stdout);
    dungdt();
    for(int i=1;i<=n;i++){
    Dijkstra1(a[i]);
    for(int i=1;i<=n;i++)ds=max(ds,kc[a[i]]),kc[a[i]]=0;
    }
    cout<<ds;
}
