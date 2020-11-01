#include <bits/stdc++.h>

using namespace std;
const int N = 4005;
int a[N], b[N], n, del, pos, tmp, prex, prey, Nx, Ny, x, ans, f[N], cnt ;
vector<int> vec[N], res[N];
int main() {
    freopen("LIONDANCE.inp","r",stdin);
    freopen("LIONDANCE.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> del;
    for(int i = 1; i <= n; ++ i) cin >> a[i];
    for(int i = 1; i <= n; ++ i) cin >> b[i];
    for(int i = 1; i <= n; ++ i) {
        for(int j = 1; j <= n; ++ j) {
            if( a[i] == b[j] ) vec[i].push_back(j), res[i].push_back(0);
        }
    }

    for(int i = n; i >= 1; -- i) {
        for(int pos = int(vec[i].size() ) - 1; pos >= 0; -- pos) {
            int j = vec[i][pos];
            res[i][pos] = 1;
            for(int k = i + 1; k <= n; ++ k) {
                if( abs( a[k] - a[i] ) <= del ) {
                    x = (upper_bound( vec[k].begin(), vec[k].end(), j ) - vec[k].begin());
                    if( x >= vec[k].size() ) continue;
                    res[i][pos] = max( res[i][pos], res[k][x] + 1 );
                }
            }
            ans = max( ans, res[i][pos] );
        }
    }
    for(int x = ans; x >= 1; -- x) {
        tmp = 0;
        for(int i = prex + 1; i <= n; ++ i) {
            pos = ( upper_bound( vec[i].begin(), vec[i].end(), prey ) - vec[i].begin() );
            if( pos >= vec[i].size() ) continue;
            if( res[i][pos] == x ) {
                if( tmp == 0 ) {
                    tmp = i, Nx = i, Ny = vec[i][pos];
                }
                else {
                    if( a[i] > a[tmp] ) {
                        tmp = i, Nx = i, Ny = vec[i][pos];
                    }
                }
            }
        }
        f[++ cnt] = tmp;
        prex = Nx; prey = Ny;
    }
    cout << cnt << '\n';
    for(int i = 1; i <= cnt; ++ i) {
        cout << a[ f[i] ] << " ";
    }
    return 0;
}
