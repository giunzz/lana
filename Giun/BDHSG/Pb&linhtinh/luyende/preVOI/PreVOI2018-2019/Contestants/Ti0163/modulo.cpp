/*
  *	Author : Thien
  *	Tre Trau Cop Code
*/

#include <bits/stdc++.h>
#define maxn 100010
#define maxm 1000010
#define ll long long
#define pb push_back
#define MP make_pair
#define pii pair <int, int>
#define piii pair <pii, int>
#define fi first
#define se second
#define mod 1000000007
#define ull unsigned long long int
#define reset(d) memset(d, 0, sizeof d)
#define endl "\n"
#define Task "modulo"

using namespace std;

main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen(Task".inp", "r", stdin);
	freopen(Task".out", "w", stdout);

    int a, b, n, k;
    cin >> a >> b >> n >> k;
    if( n > 19 ) { cout << -1; return 0; }
    ll x = 1;
    for(int i = 1; i <= n; i++) x *= 2;
    for(int i = 0; i < (1 << n); i++) {
        ll res = 0;
        for(int j = 0; j < n; j++)
            if( (i >> j) & 1 ) res = res * 10 + a;
            else res = res * 10 + b;
        if( res % x == k ) {
            cout << res;
            return 0;
        }
    }
    cout << -1;

	return 0;
}
