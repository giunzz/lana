#include<bits/stdc++.h>
const long long N = 50005;
using namespace std;

ifstream fi ("BUBBLETEA.inp");
ofstream fo ("BUBBLETEA.out");

typedef pair <long long, long long> ii;
vector <ii> adj[N];

long long n, k, f[N];
bool ck, check[N];

void dfs(long long u, long long p, long long num){
    if (!ck) return; f[u] = -1;
    for (long long i = 0; i < adj[u].size(); i++){
        long long v = adj[u][i].first;
        if (v == p) continue;
        dfs(v, u, num);
    }
    set <ii> ms;
    for (long long i = 0; i < adj[u].size(); i++){
        long long v = adj[u][i].first, cost = adj[u][i].second;
        if (v == p) continue;
        if (f[v] != -1) ms.insert(ii(f[v] + cost, v));
    }
    if (check[u]) ms.insert(ii(0, u));
    while (ms.size() > 1){
        ii cur = *(ms.rbegin());
        if (cur.first > num) ck = 0;
        ms.erase(cur);
        set<ii>::iterator it = ms.lower_bound(ii(num-cur.first+1, -1));
        if (it == ms.begin()) {
            if (f[u] != -1) {
                ck = 0;
                return;
            }
            else{
                f[u] = cur.first;
                continue;
            }
        }
        else it--;
        ms.erase(it);
    }
    if (ms.size()) f[u] = (*ms.begin()).first;
}

bool correct(long long num){
    ck = 1; dfs(1, 1, num);
    return ck;
}

long long bsearch(){
    long long l = 0, r = 1e9*N;
    while (l != r){
        long long mid = (l + r) / 2;
        if (correct(mid)) r = mid;
        else l = mid+1;
    }
    if (correct(l)) return l;
    return -1;
}

int main(){
    fi >> n >> k;
    for (long long i = 1; i <= k; i++) {long long a; fi >> a; check[a] = 1;}
    for (long long i = 1; i <  n; i++){
        long long u, v, c; fi >> u >> v >> c;
        adj[u].push_back(ii(v, c));
        adj[v].push_back(ii(u, c));
    }
    fo << bsearch() << "\n";
}
/*
8 6
1 4 5 6 7 8
1 2 1
2 3 1
3 4 1
2 5 1
2 6 1
3 7 1
3 8 1
*/
