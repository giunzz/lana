#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    ll cs;
    cin >> cs;
    while(cs--){
        ll n, m, ma = 0, mb = 0;
        cin >> n;
        vec(ll) a(n + 1);
        lp(i, 1, n) {cin >> a[i]; a[i] += a[i - 1]; ma = max(a[i], ma);}
        cin >> m;
        vec(ll) b(m + 1);
        lp(i, 1, m) {cin >> b[i]; b[i] += b[i - 1]; mb = max(b[i], mb);}
        cout << ma + mb << '\n';
    }
}