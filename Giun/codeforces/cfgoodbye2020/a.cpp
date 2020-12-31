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

#define point pp(ll, ll)
#define x first
#define y second

ll area(point a, point b, point c){
    point ab = {b.x - a.x, b.y - a.y}, bc = {c.x - b.x, c.y - b.y};
    return abs(ab.x * bc.y - ab.y * bc.x);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    ll cs;
    cin >> cs;
    point r = {0, 1};
    // cerr << r.x << ' ' << r.y << '\n';
    while(cs--){
        ll n, ans = 0;
        cin >> n;
        vec(pp(ll, ll)) p(n);
        for(point &i : p){
            cin >> i.x;
            i.y = 0;
            // cerr << i.x << ' ' << i.y << '\n';
        }
        unordered_map<ll, ll> d;
        for(point i : p){
            for(point j : p){
                ll tmp = area(r, i, j);
                if(tmp && !d[tmp]++) ++ans;
            }
        }
        cout << ans << '\n';
    }
}