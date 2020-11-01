#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define NAME "BUBBLETEA."
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,int> ii;
struct edge{
    int u,v,c;
    bool free;
    edge(){}
    edge(int iu, int iv, int ic){
        u=iu; v=iv; c=ic;
    }
};
#define maxn (50000+5)
int n,k;
int a[maxn];
vector<vector<edge>> g(maxn);

void input(){
    cin>>n>>k;
    FOR(i,1,k) cin>>a[i];
    int u,v; ll c;
    FOR(i,1,n-1){
        cin>>u>>v>>c;
        edge x=edge(u,v,c);
        g[u].push_back(x);
        x=edge(v,u,c);
        g[v].push_back(x);
    }


}
struct subtask1{
    priority_queue<ii,vector<ii>,greater<ii>> q;
    int name[maxn]={0};

    bool ok(){
        return (k<=10);
    }
//
//    void Init(){
//        FOR(i,1,k) name[a[i]]=i;
//    }

    ll D[maxn];
    int trace[maxn];
    ll Dijkstra(int x, int y){
        FOR(i,1,n) trace[i]=0;
        FOR(i,1,n) D[i]=1e17;
        D[x]=0;
        q.push(mp(0,x));
        while (!q.empty()){
            int u=q.top().second;
            ll curd=q.top().first;
            q.pop();
            if (curd>D[u]) continue;
            for(auto it=g[u].begin(); it!=g[u].end(); ++it) if (it->free){
                int v=it->v; ll c=it->c;
                if (D[v]>D[u]+c){
                    D[v]=D[u]+c;
                    q.push(mp(D[v],v));
                    trace[v]=u;
                }// else if (D[v]>=D[u]+c) {trace[v]=u;}
            }
        }
        int v=y;
        do{
            for(auto it=g[v].begin(); it!=g[v].end(); ++it) if (it->v ==trace[v]) {it->free=false; break;}
            for(auto it=g[trace[v]].begin(); it!=g[trace[v]].end(); ++it) if (it->v ==v) {it->free=false; break;}
            v=trace[v];
            if (trace[v]==x || trace[v]==0)  break;
        } while (v!=x);
        return D[y];
    }
    ll sum, maxsum;
    ll res=1e15;
    void Xuli(){
        do{
            FOR(i,1,n) for(auto it=g[i].begin(); it!=g[i].end(); ++it) it->free=true;
            maxsum=0;
            FOR(i,1,k) if (i&1){
                sum=Dijkstra(a[i],a[i+1]);
                maxsum=max(maxsum,sum);
            }
            res=min(res,maxsum);
        } while (next_permutation(a+1,a+k+1));
        cout<<res;
    }
} st1;


int main()
{
    freopen(NAME"inp","r",stdin);
    freopen(NAME"out","w",stdout);
    iostream::sync_with_stdio(0);
    input();
    if (st1.ok()){
//           st1.Init();
            st1.Xuli();
            return 0;
        }
}
