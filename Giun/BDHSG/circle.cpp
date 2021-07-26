#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "f"
using namespace std;

template <typename T> inline void Read(T &x){
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do
    {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
}

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll mxn = 1e4 + 7;
ll n, cnt[2] =  {0};
pp(pp(ll, ll), ll) a[mxn];

#define x first
#define y second

ll kc(pp(pp(ll, ll), ll) &a){return a.x.x * a.x.x + a.x.y * a.x.y;}

bool cpr(pp(pp(ll, ll), ll) &a, pp(pp(ll, ll), ll) &b){
    return a.x.x * a.x.x + a.x.y * a.x.y <= b.x.x * b.x.x + b.x.y * b.x.y;
}

int main(){
    giuncute();
    cin >> n;
    lp(i, 1, n) a[i] = {{read(), read()}, 0};
    lp(i, n + 1, n * 2) a[i] = {{read(), read()}, 1};
    sort(a + 1, a + 1 + n * 2, cpr);
    lp(i, 1, n * 2){
        if(++cnt[a[i].y] == cnt[!a[i].y] && (i == 2 * n or kc(a[i]) < kc(a[i + 1]))){
            cout << fixed << setprecision(6) << sqrt(kc(a[i]));
            return 0;
        }
    }
}