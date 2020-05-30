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
const string tenfile = "resort";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ll n, dem[4] = {0}, sang[(ll)1e6 + 7] = {0}, num, ans = 0;

void xs(){
    sang[0] = 1, sang[1] = 1;
    lp(i, 2, 1e6 + 3){
        if(!sang[i]){
            lpdk(j, i + i, j <= 1e6, j += i){
                sang[j] = 1;
            }
        }
    }
}

int main(){
    opt;
    file;
    cin >> n;
    lp(i, 1, n) {cin >> num; ++dem[num];}
    xs();
    // cerr << sang[2] << endl << sang[3] << endl << sang[4];
    ll s = dem[1] + 2 * dem[2];
    lp(i, 0, s){
        if(!sang[i]) ++ans;
        else if(!sang[i + 1]) continue;
        else if(dem[2]) ++i, --dem[2];
    }
    cout << ans;
}
