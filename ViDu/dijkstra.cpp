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
#define vec(type) vector<type>
#define vecite(type) vector<type>::iterator
using namespace std;
int n, m, d[1007] = {INT_MAX};
bool f[1007] = {0};
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

}

int main(){
    opt;
    fin("input.inp");
    fout("output.txt");
    cin >> n >> m;
    g.resize(n);
    enter();
    dijkstra();
}