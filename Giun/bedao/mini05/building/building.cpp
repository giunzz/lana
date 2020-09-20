#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for (ll a  =b; a <= c; a++)
#define lpd(a, b, c) for (ll a  =b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void File(const string ff){
    freopen((ff + ".inp").c_str(), "r", stdin);
    freopen((ff + ".out").c_str(), "w", stdout);
}

cll maxn = 1e5 + 7;
ll diff[maxn], high[maxn], n, q, F[maxn] = {0};

void upd(ll id, ll vl){
    while(id <= n){
        F[id] = F[id] + vl;
        id = id + (id & -id);
    }
}

ll getS(ll i){
    ll result = 0;
    while (i >= 1){
        result = result + F[i];
        i = i - (i & -i);
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    File("building");
    cin >> n;
    lp(i, 1, n){
        // cerr << 1;
        cin >> high[i];
        if(i == 1) continue;
        diff[i] = abs(high[i] - high[i - 1]);
        upd(i, diff[i]);
    }
    cin >> q;
    ll c, p, x;
    lp(i, 1, q){
        cin >> c >> p >> x;
        if(c == 1){
            // ll tmp = x - high[p];
            high[p] = x;
            upd(p, abs(high[p] - high[p - 1]) - diff[p]);
            diff[p] = abs(high[p] - high[p - 1]);
            if(p != n){
                upd(p + 1, abs(high[p + 1] - high[p]) - diff[p + 1]);
                diff[p+1] = abs(high[p+1] - high[p]);
            }
        }
        else{
            cout << (getS(x) - getS(p)) << endl;
        }
    }
}