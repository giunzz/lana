/*
  *	Author : Thien
  *	Tre Trau Cop Code
*/

#include <bits/stdc++.h>
#define maxn 10010
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
#define Task "liondance"

using namespace std;

int n, delta, m, cnt, res;
int a[maxn], ab[maxn];
vector <int> ans, ke;

main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen(Task".inp", "r", stdin);
	freopen(Task".out", "w", stdout);

    cin >> n >> delta;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        int b; cin >> b;
        if( a[i] == b ) ab[++m] = a[i];
    }
    sort(ab + 1, ab + m + 1);
    ke.pb(a[1]);
    for(int i = 2; i <= m; i++)
        if( ab[i] - ke[ke.size() - 1] <= delta ) ke.pb(ab[i]);
        else if( res < ke.size() ) {
                res = ke.size();
                swap(ans, ke);
                ke.clear();
            }
    if( ke.size() > res ) res = ke.size(), swap(ans, ke);
    cout << res << endl;
    for(int i = 0; i < res; i++) cout << ans[i] << " ";

	return 0;
}
