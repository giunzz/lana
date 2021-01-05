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
        ll n, x, sum0 = 0, sum1 = 0, i;
        cin >> n >> x;
        lp(t, 1, n){cin >> i; sum0 += i, sum1 += ceil((double)i/(double)x);}
        sum0 = ceil((double)sum0/(double)x);
        cout << sum0 << ' ' << sum1 << '\n';
    }
}