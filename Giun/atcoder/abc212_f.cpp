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

cll mxn = 1e5 + 7;
ll n, m, q;
pp(pp(ll, ll), pp(ll, ll)) bus[mxn];
vec(ll) bus_at[mxn];

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE    
    OF();
    #endif
    cin >> n >> m >> q;
    lp(i, 1, m) 
        cin >> bus[i].second.first >> bus[i].second.second >> bus[i].first.first >> bus[i].first.second;
    sort(bus + 1, bus + 1 + m);
    lp(i, 1, m) bus_at[bus[i].second.first].push_back(i);
    
}