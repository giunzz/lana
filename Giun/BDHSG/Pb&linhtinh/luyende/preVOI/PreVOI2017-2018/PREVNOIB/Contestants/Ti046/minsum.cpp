#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define test "minsum"
using namespace std;

void home(){
    #ifndef ONLINE_JUDGE
    freopen(test".inp","r",stdin);
    freopen(test".out","w",stdout);
    #endif // ONLINE_JUDGE
}

void in();
void sol();

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    home();
    ll T;
    cin >> T;
    while(T--){
    in();
    sol();
    }
}

ll x,y;
set<pii> s;
vector<ll> a;
vector<ll> b;
queue<pii> q;

vector<ll> ss(ll t){
    vector<ll> res;
    ll d = 2;
    while(d * d <= t){
        if(t % d == 0){
            res.push_back(d);
            while(t%d == 0) t /= d;
        }
        ++d;
    }
    if(t > 1) res.push_back(t);
    return res;
}

void in(){
    s.clear();
    while(!q.empty()) q.pop();
    cin >> x >> y;
    a = ss(x);
    b = ss(y);
}

void add(ll x1,ll x2){
    if(!s.count(mp(x1,x2))){
        if(x1 + x2 <= x*y){
            s.insert(mp(x1,x2));
            q.push(mp(x1,x2));
        }
    }
}

void sub1(){
    s.insert(mp(x,y));
    q.push(mp(x,y));
    ll r1 = x,r2 = y;
    while(!q.empty()){
        pii d = q.front();
        q.pop();
        ll u = d.first;
        ll v = d.second;
        if(r1 + r2 > u + v) r1 = u,r2 = v;
        for(ll i = 0; i < b.size(); ++ i){
            ll t = b[i];
            if(v % t == 0){
                add(u*t,v/t);
                if(u % t == 0)
                    add(u/t,v/t);
            }
            if(u % t == 0)
                add(u/t,v*t);
        }
        for(ll i = 0; i < a.size(); ++i){
            ll t = a[i];
            if(v % t == 0){
                add(u*t,v/t);
                if(u % t == 0)
                    add(u/t,v/t);
            }
            if(u % t == 0)
                add(u/t,v*t);
        }
    }
    cout << r1 << " " << r2 << "\n";
}

void sol(){
    sub1();
}
