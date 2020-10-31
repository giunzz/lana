#include <bits/stdc++.h>

#define TASK "TREE"

using namespace std;

template<typename T> inline void read(T &x){
    x = 0; char ch; bool neg = 0;
    while(!isdigit(ch=getchar())&&ch!='-');
    if(ch=='-'){neg=1;ch=getchar();}
    do{x=10*x+ch-'0';} while(isdigit(ch=getchar()));
    if(neg) x = -x;
}

const int N = 5555;

int n, A[N], tin[N], tout[N], counter, res, BIT[N];
vector<int> Adj[N];
vector<int> T;

void DFS(int u){
    tin[u] = ++counter;
    for(int i = 0; i < (int)Adj[u].size(); i++){
        int v = Adj[u][i];
        DFS(v);
    }
    tout[u] = counter;
    T.push_back(u);
}

void update(int x, int val){
    while(x<=n){
        BIT[x] += val;
        x += x&(-x);
    }
}

int get(int x){
    int ret = 0;
    while(x>0){
        ret += BIT[x];
        x -= x&(-x);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    read(n);
    for(int i = 1; i <= n; i++) read(A[i]);
    for(int i = 1; i < n; i++){
        int u, v;
        read(u); read(v);
        Adj[u].push_back(v);
    }
    DFS(1);
    for(int i = 1; i <= n; i++){
        if(Adj[i].size()==0&&A[i]>1){
            res += A[i]-1;
            A[i] = 1;
        }
    }
    for(int i = 1; i <= n; i++){
        update(i,A[i]);
    }
    for(int i = 0; i < (int)T.size(); i++){
        int u = T[i];
        if(Adj[u].size()==0) continue;
        int sum = get(tout[u])-get(tin[u]);
        if(sum!=A[u]){
            int tmp = sum-A[u];
            res += abs(tmp);
            A[u] = sum;
            update(tin[u],tmp);
        }
    }
    cout<<res<<'\n';
    return 0;
}
