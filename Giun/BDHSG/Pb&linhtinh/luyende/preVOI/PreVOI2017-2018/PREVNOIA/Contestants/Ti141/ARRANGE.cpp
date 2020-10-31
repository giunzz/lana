#include <bits/stdc++.h>

#define TASK "ARRANGE"

using namespace std;

template<typename T> inline void read(T &x){
    x = 0; char ch; bool neg = 0;
    while(!isdigit(ch=getchar())&&ch!='-');
    if(ch=='-'){neg=1;ch=getchar();}
    do{x=10*x+ch-'0';} while(isdigit(ch=getchar()));
    if(neg) x = -x;
}

typedef long long ll;

const int N = 1e5+111;
const ll INF = 1e18;

int n;
ll A[N], sum, res;
vector<int> T;

void sol(){
    ll need = (ll)sum/n;
    for(int i = 1; i <= n; i++){
        if(A[i]<need) T.push_back(i);
        else if(A[i]>need){
            ll rest = A[i]-need;
            while(T.size()>0){
                int p = T.back();
                if(rest<need-A[p]){
                    A[p] += rest;
                    res += rest*(ll)(i-p);
                    break;
                }
                rest -= need-A[p];
                res += (need-A[p])*(i-p);
                A[p] = need;
                T.pop_back();
            }
            A[i] = rest+need;
            if(A[i]>need){
                reverse(A+1,A+n+1);
                sol();
                return;
            }
        }
    }
}

void solve1(){
    res = 0;
    ll need = (ll)sum/n;
    int pmin = 0, pmax = 0;
    for(int i = 1; i <= n; i++){
        if(A[i]<need&&pmin==0) pmin = i;
        if(A[i]>need&&pmax==0) pmax = i;
    }
    if(pmin<pmax) sol();
    else{
        reverse(A+1,A+n+1);
        sol();
    }
    cout<<res<<'\n';;
}

struct MaxFlow{
    struct Edge{
        int u, v;
        ll cap, flow;
    };
    int n, s, t;
    vector<vector<int> > G;
    vector<int> D, pnt;
    vector<Edge> E;
    void reset(int x){
        n = x;
        G.resize(n+1);
        D.resize(n+1);
        pnt.resize(n+1);
        E.clear();
        for(int i = 1; i <= n; i++) G[i].clear();
    }
    void addEdge(int u, int v, ll cap){
        Edge e1 = {u,v,cap,0};
        Edge e2 = {v,u,0,0};
        G[u].push_back((int)E.size());
        E.push_back(e1);
        G[v].push_back((int)E.size());
        E.push_back(e2);
    }
    ll getMaxFlow(int _s, int _t){
        s = _s; t = _t;
        ll flow = 0;
        while(BFS()){
            for(int i = 1; i <= n; i++) pnt[i] = 0;
            ll delta;
            while(delta=DFS(s,INF)){
                flow += delta;
            }
        }
        return flow;
    }
    ll getAnswer(){
        ll ret = 0;
        for(int i = 0; i < (int)E.size(); i+=2){
            if(E[i].u==s||E[i].v==t) continue;
            int u = E[i].u;
            int v = E[i].v;
            A[u] -= E[i].flow;
            A[v] += E[i].flow;
            ret += E[i].flow;
        }
        return ret;
    }
private:
    bool BFS(){
        queue<int> Qu;
        for(int i = 1; i <= n; i++) D[i] = -1;
        Qu.push(s);
        D[s] = 0;
        while(!Qu.empty()){
            int u = Qu.front(); Qu.pop();
            if(u==t) return 1;
            for(int i = 0; i < (int)G[u].size(); i++){
                int id = G[u][i];
                if(E[id].flow==E[id].cap) continue;
                int v = E[id].v;
                if(D[v]==-1){
                    D[v] = D[u]+1;
                    Qu.push(v);
                }
            }
        }
        return 0;
    }
    ll DFS(int u, ll flow){
        if(!flow) return 0;
        if(u==t) return flow;
        for(; pnt[u] < G[u].size(); pnt[u]++){
            int id = G[u][pnt[u]];
            int v = E[id].v;
            if(D[v]!=D[u]+1) continue;
            ll delta = DFS(v,min(flow,E[id].cap-E[id].flow));
            if(delta){
                E[id].flow += delta;
                E[id^1].flow -= delta;
                return delta;
            }
        }
        return 0;
    }
} Flow;

void solve2(){
    ll need = (ll)sum/n;
    Flow.reset(n+2);
    int s = n+1, t = n+2;
    for(int i = 2; i <= n; i++){
        Flow.addEdge(i-1,i,INF);
        Flow.addEdge(i,i-1,INF);
    }
    for(int i = 1; i <= n; i++){
        if(A[i]>need){
            Flow.addEdge(s,i,A[i]-need);
        }
        else{
            Flow.addEdge(i,t,need-A[i]);
        }
    }
    Flow.getMaxFlow(s,t);
    res = Flow.getAnswer();
    Flow.reset(n+2);
    for(int i = 2; i <= n; i++){
        Flow.addEdge(i-1,i,INF);
        Flow.addEdge(i,i-1,INF);
    }
    for(int i = 1; i <= n; i++){
        if(A[i]>need+1){
            Flow.addEdge(s,i,A[i]-need-1);
        }
        else{
            Flow.addEdge(i,t,need-A[i]+1);
        }
    }
    Flow.getMaxFlow(s,t);
    res += Flow.getAnswer();
    cout<<res<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    read(n);
    for(int i = 1; i <= n; i++){
        read(A[i]);
        sum += A[i];
    }
    if(sum%n==0){
        solve1();
        return 0;
    }
    solve2();
    return 0;
}
