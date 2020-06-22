#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define fin(tenfile) freopen(tenfile, "r", stdin)
#define fout(tenfile) freopen(tenfile, "w", stdout)
#define errl(variable) cerr << variable << "\n"
#define loop(variable, valuegan, valuebehonbang) for(long long variable = valuegan; variable <= valuebehonbang; variable++)
#define loopd(variable, valuegan, valuelonhonbang) for(long long variable = valuegan; variable >= valuelonhonbang; variable--)
#define loopdk(variable, valuegan, conditions, thaydoi) for(long long variable = valuegan; conditions; thaydoi) 
#define pp(type) pair<type, type>
#define mp make_pair
#define fi first
#define se second
#define vec(type) vector<type>
#define vecite(type) vector<type>::iterator
using namespace std;
const int maxn = INT_MAX/100;
int n, m, d[1007], t[1007];
bool f[1007];
vec(vec(pp(int))) g;

void enter(){
    int u, v, w;
    loop(i, 1, m){
        cin >> u >> v >> w;
        g[u].push_back(mp(v, w));
        g[v].push_back(mp(u, w));
    }
}

void dijkstra(){
    int u, mi, v;
    while(true){
        u = 0, mi = maxn;
        loop(i, 1, n){
        if(f[i] && d[i] < mi){
            u = i, mi = d[i];
            }
        }
        if(!u || u == 5) break;
        f[u] = 0;
        loop(i, 0, g[u].size() - 1){
            if (d[g[u][i].fi] > (d[u] + g[u][i].se)){
            d[g[u][i].fi] = d[u] + g[u][i].se, t[g[u][i].fi] = u;
            }
        }
    }
}

void init(){
    d[1] = 0, f[1] = 1;
    loop(i, 2, n) d[i] = maxn, f[i] = 1;
}

int main(){
    opt;
    fin("input.inp");
    fout("output.txt");
    cin >> n >> m;
    g.resize(n + 2);
    init();
    enter();
    dijkstra();
    cout << d[5] << endl;
    int u = 5;
    while (u != 1){
        cout << u << " ";
        u = t[u];
    }
    cout << 1;
}
