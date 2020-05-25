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
const string tenfile = "profesor";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

// cll maxn = 1e5 + 7;
// ll n, b[7] = {0}, anssc = -1, anssl = -1, cs, c, sc;
// pp(ll, ll) a[maxn];

// int main(){
//     opt;
//     file;
//     cin >> n;
//     lp(i, 1, n) cin >> a[i].fi >> a[i].se;
//     ll i = 1, j = 1;
//     if(a[1].fi == a[1].se) ++b[a[1].fi];
//     else ++b[a[1].fi], ++b[a[1].se];
//     anssl = 1, anssc = min(b[a[1].fi], b[a[1].se]);
//     while(j++ < n){
//         if(b[a[j].fi] == b[a[j].se]) ++b[a[j].fi];
//         else ++b[a[j].fi], ++b[a[j].se];
//         if(i > j) continue;
//         cs = j - i + 1, c = 0, sc = 10;
//         lp(x, 1, 5) {if (b[x] == cs) c = 1, sc = min(sc, x);}
//         if(c) {
//             if(cs > anssl) {
//                 anssl = cs;
//                 anssc = sc;
//             }
//             if(cs == anssl && sc < anssc) anssc = sc;
//         }
//         else{
//             // if(j == n) {
//             //     c = 0, sc = 10;
//             //     lp(x, 1, 5) {if (b[x] == cs) c = 1; if(b[x] == cs) sc = min(sc, x);}
//             //     if(c) {
//             //         if(anssl < cs) anssl = cs, anssc = sc;
//             //         if(anssl == cs && anssc > sc)  anssc = sc;
//             //     }
//             //     break;
//             // }
//             if(b[a[i].fi] == b[a[i].se]) --b[a[i++].fi];
//             else --b[a[i].fi], --b[a[i++].se];
//         }
//         //cerr << i << " " << j << endl;
//     } 
//     cout << anssl << " " << anssc;
// }

vector <pp(ll, ll)> save[100005] = {};
unordered_set <long> pos;
long n;

int main() {
    opt;
    file;
	cin >> n;
	lp(i, 1, n){
		long a, b;
		cin >> a >> b;
		pos.insert(a);
		pos.insert(b);
		if (save[a].empty()) save[a].push_back({1, i});
		else {
			if (save[a].back().second == i-1) save[a].back().first++, save[a].back().second++;
			else save[a].push_back({1, i});
		}
		if (a != b) {
			if (save[b].empty()) save[b].push_back({1, i});
			else {
				if (save[b].back().second == i-1) save[b].back().first++, save[b].back().second++;
				else save[b].push_back({1, i});
			}
		}
	}
	pp(ll, ll) maxx = {0, 0};
	for (auto id : pos) {
		for (auto i : save[id]) {
			if (maxx.first < i.first) maxx = {i.first, id};
			else if (maxx.first == i.first && maxx.second > id) maxx={i.first, id};
		}
	}
	cout << maxx.first << " " << maxx.second;
}