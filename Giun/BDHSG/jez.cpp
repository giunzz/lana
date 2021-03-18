#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "f"
using namespace std;

template <typename T> inline void Read(T &x){
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do
    {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
}

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll mxn = 1e6 + 7;
ll r, c, k, cntrow[mxn] = {0};

void cntCell(){
    ll i = 0, j = 0, mi = min(r, c), res, ma = max(r, c);
    pp(ll, ll) x, y;
    
    // xet cheo tang
    if(((mi * (mi + 1)) >> 1) < k){
        k -= ((mi * (mi + 1)) >> 1);
        res = mi;
    } else{
        ll l = 1, r = mi;
        while(l <= r){
            ll mid = (l + r) >> 1;
            if(mid * (mid + 1) / 2 <= k) res = mid, l = mid + 1;
            else r = mid - 1;
        }
        k -= res * (res + 1) / 2;
        // cerr << res;
        if(k){
            ++res, --k;
            ll dimension = 0;
            if(res & 1){
                y = {res - 1, 0}, x = {res - 1 - k, k};
            }
            else {
                x = {0, res - 1}, y = {k, res - 1 - k};
            }
            k = 0;
        } else x = {0, res - 1}, y = {res - 1, 0};
        cerr << x.first << ' ' << x.second << '\n' << y.first << ' ' << y.second;
    }

    // xet cheo bang nhau
    ll tot = mi, num = ma - mi, cheo = min(k / tot, num);
    if(num * tot < k){
        k -= num * tot;
        res += num;
    } else if(k){
        res += cheo, k -= cheo * tot; //ko tru k
        if(k) ++res, --k;
        if(~res & 1){ // chan
            ll last = res - 1;
            x = {(last < c) ? 0 : res - c, (last < c) ? last : c - 1};
            y = {x.first + num - 1, x.second - num + 1}; 
            // cerr << '\t';
        } else{
            ll last = res - 1;
            y = {(last < r) ? last : r - 1, (last < r) ? 0 : res - r};
            x = {y.first - k, y.second + k}; 
        }   
        cerr << x.first << ' ' << x.second << '\n' << y.first << ' ' << y.second << '\n' << k << ' ' << res;
        // cerr << k << ' ' << res << ' ' << cheo;
    }

    --tot;
    //cong thuc tong cua tot -> 1

    //xet cheo giam

}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    // lp(i, 0, 30){
    //     lp(j, 0, 30) cerr << !((i & j)) << ' ';
    //     cerr << endl;
    // }
    cin >> r >> c >> k;
    cntCell();
}