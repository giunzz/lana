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

cll maxn = 107;
ll n, k, f[maxn][maxn] = {{0}}, mid, ans = 0;
pp(ll, ll) point;

pp(ll, ll) checkPoint(pp(ll, ll) p){
    pp(ll, ll) tmp = p;
    if(p.first >= mid and p.second < mid)
        tmp.second = n - p.first + 1, tmp.first = p.second;
    else if(p.first > mid && p.second >= mid)
        tmp.second = mid * 2 - p.second, tmp.first = n - p.first + 1;
    else if(p.first <= mid && p.second > mid)
        tmp.second = p.first, tmp.first = n - p.second + 1; 
    return tmp;
}

void xuly(){
    lp(i, point.first - 1, mid) f[i][point.second - 1] = INT_MAX;
    lp(i, point.second - 1, mid) f[point.first - 1][i] = INT_MAX;
    f[point.first][point.second] = 0;
    lp(i, point.first, mid){
        lp(j, point.second, mid){
            if(i == point.first && j == point.second) continue;
            f[i][j] = min(f[i - 1][j] + 10, min(f[i][j - 1] + 10, f[i - 1][j - 1] + 15));
        }
    }
    ans += f[mid][mid];
}

int main(){
    opt;
    file;
    cin >> n >> k;
    mid = n / 2 + 1;
    lp(i, 1, k){
        cin >> point.fi >> point.se;
        point = checkPoint(point);
        xuly();
    }
    cout << ans;
}
