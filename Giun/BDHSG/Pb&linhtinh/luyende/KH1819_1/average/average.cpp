#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
using namespace std;

void file(const string s){
    freopen((s + ".inp").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

cll maxn = 1e5 + 7;
ll n, a[maxn];

double t5(double t){
    t = round(t * 100000) / 100000.0;
    return t;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    file("average");
    cin >> n;
    double s = 0;
    lp(i, 1, n) {
        cin >> a[i];
        s += a[i];
    }
    sort(a + 1, a + 1 + n);
    double c = a[1];
    lp(i, 2, n) c = (c + a[i])/2.0;
    double ans = c * (n * 1.0) - s;
    cout << fixed << setprecision(5) << ans;
}
