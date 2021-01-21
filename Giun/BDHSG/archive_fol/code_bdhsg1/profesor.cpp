#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define lpdk(a, b, c, d) for(ll a = b; c; d) 
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
using namespace std;
cll MOD = 1e9 + 7;
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

vec(pp(ll, ll)) save[100005] = {};
unordered_set <ll> dd;
ll n;

int main() {
    opt;
    file;
	cin >> n;
	lp(i, 1, n){
		ll a, b;
		cin >> a >> b;
		dd.insert(a);
		dd.insert(b);
		if (save[a].empty()) save[a].push_back({1, i});
		else {
			if (save[a].back().se == i-1) save[a].back().fi++, save[a].back().se++;
			else save[a].push_back({1, i});
		}
		if (a != b){
			if (save[b].empty()) save[b].push_back({1, i});
			else {
				if (save[b].back().se == i-1) save[b].back().fi++, save[b].back().se++;
				else save[b].push_back({1, i});
			}
		}
	}
	pp(ll, ll) maxx = {0, 0};
	for (auto id : dd) {
		for (pp(ll, ll) i : save[id]) {
			if (maxx.fi < i.fi) maxx = {i.fi, id};
			else if (maxx.fi == i.fi && maxx.se > id) maxx={i.fi, id};
		}
	}
	cout << maxx.fi << " " << maxx.se;
}