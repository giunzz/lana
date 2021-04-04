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

ll n, m;
string ma, mi;

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m;
    while(m){
        if(m > 9) m -= 9, ma.push_back('9');
        else ma.push_back(m + '0'), m = 0;
    }
    while(ma.size() < n) ma.push_back('0');
    mi = ma;
    reverse(mi.begin(), mi.end());
    if(mi[0] == '0'){
        mi[0] = '1';
        lp(i, 1, n - 1) if(mi[i] != '0'){--mi[i]; break;}
    }
    cout << mi << ' ' << ma;
}