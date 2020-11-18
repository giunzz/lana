#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
// #define Fname "topic"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

ll n;
vec(ll) a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    a.resize(n + 1);
    a[0] = 0;
    lp(i, 1, a.size() - 1){
        cin >> a[i];
        a[i] += a[i - 1];
        if(a[i] > 0){
            cout << '*';
            --a[i];
        }
        else cout << '-';
    }
}