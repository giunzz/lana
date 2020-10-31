#include <bits/stdc++.h>
#define f0(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define nmax 5002

using namespace std;
typedef long long ll;

int n, c[nmax], x; ll f[nmax][1 << 13];
vector <int> a[nmax];

bool check(int u){
    return a[u].size()==0;
}

void dfs(int u){
    bool ok = 0;
    for(int i=0; i<a[u].size(); i++){
        int v = a[u][i];
        dfs(v);
        ok = 1;
    }
    if(ok==0){
        f[u][0] = c[u];
        f[u][1] = abs(c[u] - 1);
    }
    else{
        int k1 = -1, k2 = -1;
        if(a[u].size()==1) k1 = a[u][0];
        if(a[u].size()==2){
            k1 = a[u][0], k2 = a[u][1];
        }
        if(k2==-1){
            f0(j, x + 1){
                f[u][j] = f[k1][j] + abs(c[u] - j);
            }
        }
        else{
            f0(j, x + 1){
                f[u][j] = f[k1][j] + abs(c[u] - j) + f[k2][0];
                f[u][j] = min(f[u][j], f[k2][j] + abs(c[u] - j) + f[k1][0]);
                for(int t=1; t<j; t++){
                    int x1 = t, x2 = j - t;
                    if(check(k1) || check(k2)){
                        if(check(k1) && x1>1) continue;
                        if(check(k2) && x2>1) continue;
                        f[u][j] = min(f[u][j], abs(c[u] - j) + f[k1][x1] + f[k2][x2]);

                    }
                }
            }
        }
    }
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("TREE.inp", "r", stdin);
    freopen("TREE.out", "w", stdout);

    cin >> n;
    f1(i, n) cin >> c[i];
    f1(i, n - 1){
        int u, v; cin >> u >> v;
        a[u].push_back(v);
    }

    int k = log2(n);
    x = ( 1 << k );
    f1(i, n){
        f0(j, x + 1) f[i][j] = 1e14;
    }
    dfs(1);

    ll res = 1e16;
    f0(i, x + 1) res = min(res, f[1][i]);

    cout << res;
}
