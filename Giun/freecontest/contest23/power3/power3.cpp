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

ll p3[(int)1e6+7] = {0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // File("power3");
    lp(i, 0, 1e6){
        p3[i] = i*i*i;
    }
    p3[(int)1e6+1] = LLONG_MAX;
    ll qr, tmp;
    cin >> qr;
    while(qr--){
        cin >> tmp;
        ll vt = lower_bound(p3, p3 + 1 + (ll)1e6, tmp) - p3;
        if(p3[vt] == tmp) cout << "YES\n";
        else cout << "NO\n";
    }
}