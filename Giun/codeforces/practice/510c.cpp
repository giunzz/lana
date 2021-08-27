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

cll mxn = 103, mxchar = 300;
ll n, indeg[mxchar] = {0};
string a[mxn];
vec(ll) g[mxchar], topo;
queue<ll> q;

bool comp(string &s, string &t){ // s < t
    bool ok = 0;
    lp(i, 0, min(s.size(), t.size()) - 1){
        if(s[i] != t[i]){
            g[s[i]].push_back(t[i]);
            ++indeg[t[i]];
            return 1;
        }
    }
    return s.size() < t.size();
}

void sort_topo(){
    lp(i, 'a', 'z') if(!indeg[i]){
        q.push(i);
        topo.push_back(i);
    }
    while(q.size()){
        ll u = q.front();
        q.pop();
        for(ll v : g[u]){
            if(!--indeg[v]) q.push(v), topo.push_back(v);
        }
    }
    if(topo.size() < 'z' - 'a' + 1) cout << "Impossible";
    else for(char i : topo) cout << i;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n){
        cin >> a[i];
        lp(j, 1, i - 1) if(!comp(a[j], a[i])){
            cout << "Impossible";
            return 0;
        }
    }
    sort_topo();
}