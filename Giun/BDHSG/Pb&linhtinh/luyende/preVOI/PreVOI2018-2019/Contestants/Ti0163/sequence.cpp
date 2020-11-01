/*
  *	Author : Thien
  *	Tre Trau Cop Code
*/

#include <bits/stdc++.h>
#define maxn 3030
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
#define Task "sequence"

using namespace std;

int m, n, k;
int a[maxn], b[maxn];
priority_queue <int, vector <int>, greater <int> > pq;

void subbb() {
    vector <int> res;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if( a[i] < b[j] ) res.pb(a[i]), k--, i++;
            else res.pb(b[j]), b[j] = INT_MAX, k--;
            if( k == 0 ) break;
        }
        if( k == 0 ) break;
    }
    for(int i = 0; i < res.size(); i++) cout << res[i] << " ";
}

main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen(Task".inp", "r", stdin);
	freopen(Task".out", "w", stdout);

    cin >> m >> n >> k;
    for(int i = 1; i <= m; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    subbb();

	return 0;
}
