#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "a"
using namespace std;

inline ll read(){
    ll tmp;
    scanf("%lld", &tmp);
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

cll mxn = 1e5 + 7;
ll n;
string s[mxn], p[mxn], res;

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    scanf("%lld", &n);
    lp(i, 1, n){
        char c;
        lpd(j, read(), 1){
            scanf("%c", &c);
            while(c == ' ') scanf("%c", &c);
            s[i] += c;
        }
    }
    lp(i, 1, n)
        p[read()] = s[i];
    lp(i, 1, n)
        res += p[i];
    lpd(i, read(), 1){
        ll x = read(), y = read();
        swap(res[x - 1], res[y - 1]);
    }
    printf("%s", res.c_str());
}