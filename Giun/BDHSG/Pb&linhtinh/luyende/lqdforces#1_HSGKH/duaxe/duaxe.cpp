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

ll n;

void sol(){
    ll vl, pre, dinh, ans = 0;
    bool chieu = 0; // 0 la xuong, 1 la di len
    cin >> pre >> vl;
    dinh = pre;
    if(pre < vl) chieu = 1, ans += vl - pre, dinh = vl;
    pre = vl;
    lp(i, 1, n - 2){
        cin >> vl;
        if(vl > pre){
            if(vl > dinh) ans += vl - pre;
            if(!chieu) chieu = 1;
        }
        if(vl < pre){
            if(chieu) chieu = 0, dinh = pre;
        }
        pre = vl;
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // File("duaxe");
    cin >> n;
    if(n == 1){
        cout << 0;
        return 0;
    }
    sol();
}