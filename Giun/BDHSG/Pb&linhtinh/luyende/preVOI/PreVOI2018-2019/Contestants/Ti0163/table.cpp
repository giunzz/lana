/*
  *	Author : Thien
  *	Tre Trau Cop Code
*/

#include <bits/stdc++.h>
#define maxn 550
#define maxm 1000010
#define ll long long
#define pb push_back
#define MP make_pair
#define pii pair <int, int>
#define piii pair <pii, int>
#define fi first
#define se second
#define mod 1000000007
#define ull unsigned long long
#define reset(d) memset(d, 0, sizeof d)
#define endl "\n"
#define Task "table"

using namespace std;

int m, n, k;
int a[maxn][maxn];
ll f[maxn][maxn];

void sub1() {
    while( k-- ) {
        int u1, v1, u2, v2; cin >> u1 >> v1 >> u2 >> v2;
        ll res = LLONG_MAX;
        for(int x1 = u1; x1 <= u2; x1++) {
            for(int x2 = v1; x2 <= v2; x2++) {
                if( (x1 == u1 && x2 == v1) || (x1 == u2 && x2 == v2) ) continue;
                int xx = a[x1][x2]; a[x1][x2] = 0;
                for(int i = u1; i <= u2; i++)
                    for(int j = v1; j <= v2; j++)
                        f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];
                res = min(res, f[u2][v2]);
                a[x1][x2] = xx;
                for(int i = u1; i <= u2; i++)
                    for(int j = v1; j <= v2; j++) f[i][j] = 0;
            }
        }
        cout << res << endl;
    }
}

void sub2() {
    while( k-- ) {
        int u1, v1, u2, v2; cin >> u1 >> v1 >> u2 >> v2;
        ll res = LLONG_MAX;
        for(int i = u1; i <= u2; i++)
            for(int j = v1; j <= v2; j++)
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];
        int x = f[u2][v2], u = u2, v = v2;
        vector < pii > tv;
        while( x - a[u][v] != 0 && u != u1 && v != v1 ) {
            x -= a[u][v];
            if( x == f[u - 1][v] ) tv.pb(MP(u - 1, v)), u--;
            else tv.pb(MP(u, v - 1)), v--;
        }
        for(int x1 = 0; x1 < tv.size(); x1++) {
            int xx = a[tv[x1].fi][tv[x1].se];
            a[tv[x1].fi][tv[x1].se] = 0;
            for(int i = u1; i <= u2; i++)
                for(int j = v1; j <= v2; j++)
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];
            res = min(res, f[u2][v2]);
            a[tv[x1].fi][tv[x1].se] = xx;
            for(int i = u1; i <= u2; i++)
                for(int j = v1; j <= v2; j++) f[i][j] = 0;
        }
        cout << res << endl;
    }
}

main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen(Task".inp", "r", stdin);
	freopen(Task".out", "w", stdout);

    cin >> m >> n >> k;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    if( m <= 30 && n <= 30 && k <= 30 ) {
        sub1();
        return 0;
    }
    sub2();

	return 0;
}
