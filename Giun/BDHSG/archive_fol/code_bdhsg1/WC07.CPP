#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
// #define Fname "reinst"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

ll n;
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> s;
    if(count(s.begin(), s.end(), '(') != n/2 || (n & 1)){
        cout << "-1";
        return 0;
    }
    ll p = 0, b = 0, res = 0;
    for(char &c : s){
        p = b;
        b += (c == '(') ? 1 : -1;
        res += (p <= 0) && (b <= 0);
    }
    cout << res;
}