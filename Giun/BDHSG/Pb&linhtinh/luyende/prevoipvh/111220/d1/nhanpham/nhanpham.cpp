#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void file(const string file){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen((file + ".inp").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
}

cll maxn = 1e5 + 7;
ll n, k, a[maxn], s[maxn];

// void sub1(){

// }

double f(ll q, ll alp){
    return (1 + q * n + alp) * (q * n + alp) / 2.0 - (q * s[n - 1] + s[alp]) - k;
}

ll sol(ll al){
    double l = 0, r = 1e9;
    lp(i, 1, 100){
        double mid1 = l + (r - l) / 3.0, mid2 = r - (r - l) / 3.0;
        double fmid1 = f(mid1, al), fmid2 = f(mid2, al);
        if(fmid1 < fmid2) r = x2;
        else l = x1;
    }
    
}

int main(){
    file("nhanpham");
    ll sub;
    cin >> sub >> n >> k;
    lp(i, 0, n - 1) cin >> a[i];
    s[0] = a[0];
    lp(i, 1, n - 1) s[i] = s[i - 1] + a[i];
    lp(alp, 0, n - 1)sol(alp);
    if(sub == 1 || sub == 2) sub1();
}