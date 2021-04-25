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

map<string, ll> d;
map<pp(string, string), bool> ct;
ll n;

#define ONLINE_JUDGE
int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    string q, w, e, s;
    lp(i, 1, n){
        cin >> q >> w >> e;
        // a += " " ;
        s = q + w;
        if(ct[{s, e}]) continue;
        ct[{s, e}] = 1; 
        d[e]++;
    }
    for(auto i = d.begin(); i != d.end(); i++){
        cout << (*i).first << ' ' << (*i).second << ' ';
        if((*i).second >= 10)  cout << "YES\n";
        else cout << "NO\n";
    }
}