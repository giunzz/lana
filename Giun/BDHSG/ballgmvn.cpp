#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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
#pragma GCC optimize("Ofast")

struct pairhash{
    size_t operator()(const pair<ll, ll> &x) const
    {
        return hash<ll>()(x.first) ^ hash<ll>()(x.second);
    }
};

cll maxn = 2e3 + 8;
ll n, pos;
pp(ll, ll) red[maxn], grn[maxn];
unordered_map<pp(ll, ll), ll, pairhash> mp[maxn];

#define x first 
#define y second

int main(){
    opt; 
    file;
    cin >> n;
    lp(i, 1, n)cin >> grn[i].x >> grn[i].y;
    lp(i, 1, n)cin >> red[i].x >> red[i].y;
    lp(i, 1, n){
        lp(j, 1, n){
            pp(ll, ll) vt = {red[j].x - grn[i].x, red[j].y - grn[i].y};
            ll tmp  = __gcd(vt.x, vt.y);
            vt.x /= tmp, vt.y /= tmp;
            if(vt.x < 0) vt.x = -vt.x, vt.y = -vt.y;
            if(pos = mp[i][vt]){
                cout << i << ' ' << (j + n) << ' ' << pos;
                return 0;
            } else if(pos = mp[j + n][vt]){
                cout << i << ' ' << (j + n) << ' ' << pos;
                return 0;
            }
            mp[i][vt] = j + n, mp[j + n][vt] = i;
        }
    }
    cout << -1;
}