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

cll mxn = 2e5 + 7;
set<pp(ll, ll)> bst;
set<pp(ll, ll)>::iterator it;
ll a, b, tot = 0;
pp(ll, ll) q[mxn];
map<ll, map<ll, ll>> mp;

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    EACHCASE{
        char c;
        cin >> c;
        if(c == 'D'){
            cin >> a >> b;
            bst.insert({b, a});
            q[++tot] = {b, a};
            mp[b][a] = tot;
        } else{
            cin >> a;
            it = bst.upper_bound(q[a]);
            if(it == bst.end()) cout << "NE\n";
            else cout << mp[(*it).first][(*it).second] << '\n';
        }
    }
}