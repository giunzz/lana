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

struct pairhash {
public:
    size_t operator()(const pair<ll, ll> &x) const
    {
        return hash<ll>()(x.first) ^ hash<ll>()(x.second);
    }
};

cll maxn = 1e3 + 8;
ll n;
pp(ll, ll) red[maxn], grn[maxn], f[maxn][maxn];
unordered_map<pp(ll, ll), pp(ll, ll), pairhash> mp;

#define x first
#define y second

int main(){
    opt;
   // file;
    cin >> n;
    lp(i, 1, n)cin >> grn[i].x >> grn[i].y;
    lp(i, 1, n)cin >> red[i].x >> red[i].y;
    lp(i, 1, n){
        lp(j, 1, n){
            pp(ll, ll) vt = {red[j].x - grn[i].x, red[j].y - grn[i].y};
            ll tmp  = __gcd(vt.x, vt.y);
            vt.x /= tmp, vt.y /= tmp;
            if(vt.x < 0) vt.x = -vt.x, vt.y = -vt.y;
            f[i][j] = vt; 
            mp[vt] = {i, j};
        }
    }
    ll pos;
    lp(i, 1, n){
        lp(j, i + 1, n){
            pp(ll, ll) vt = {grn[j].x - grn[i].x, grn[j].y - grn[i].y};
            ll tmp  = __gcd(vt.x, vt.y);
            vt.x /= tmp, vt.y /= tmp;
            if(vt.x < 0) vt.x = -vt.x, vt.y = -vt.y;
            if((pos = mp[vt].y) && (f[i][pos] == vt)){
                cout << i << ' ' << j << ' ' << (pos + n) << '\n';
                return 0;
            }
        }
    }
    lp(i, 1, n){
        lp(j, i + 1, n){
            pp(ll, ll) vt = {red[j].x - red[i].x, red[j].y - red[i].y};
            ll tmp  = __gcd(vt.x, vt.y);
            vt.x /= tmp, vt.y /= tmp;
            if(vt.x < 0) vt.x = -vt.x, vt.y = -vt.y;
            if((pos = mp[vt].x) && (f[pos][i] == vt)){
                cout << (i + n) << ' ' << (j + n) << ' ' << mp[vt].x;
                return 0;
            }
        }
    }
    cout << -1;
}