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

#define point pp(ll, ll)
#define segment pp(point, point)

struct event{
    ll x, tt, id;
};

cll mxn = 2e5 + 7;
ll n, ans = 0;
segment a[mxn];
vec(segment) tx, ty;
vec(event) ev;
vec(set<segment>::iterator) where;
set<segment> sweep;

inline bool Oy(segment const &q){
    return q.first.first == q.second.first;
}

inline bool cmp(segment &a, segment &b){
    return a.first.first < b.first.first;
}

inline bool cmp1(event &a, event &b){
    if(a.x == b.x) return a.tt > b.tt;
    return a.x < b.x;
}

bool operator<(segment &a, segment &b){
    return a.first.second < b.first.second;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n){
        segment tmp;
        cin >> tmp.first.first >> tmp.first.second >> tmp.second.first >> tmp.second.second;
        if(tmp.first.first > tmp.second.first || tmp.first.second > tmp.second.second) swap(tmp.first, tmp.second);
        if(Oy(tmp)) ty.push_back(tmp);
        else tx.push_back(tmp);
    }
    lp(i, 0, tx.size() - 1){
        ev.push_back({tx[i].first.first, 1, i});
        ev.push_back({tx[i].second.first, -1, i});
    }   
    sort(ty.begin(), ty.end(), cmp);
    sort(ev.begin(), ev.end(), cmp1);
    where.resize(tx.size());
    ll j = 0;
    while(j < ty.size() && ty[j].first.first < ev[0].x) ++j;
    lp(i, 0, ev.size() - 1){
        if(ev[i].tt == 1){
            set<segment>::iterator it = sweep.lower_bound(tx[ev[i].id]);
            where[ev[i].id] = sweep.insert(it, tx[ev[i].id]);
            ++i;
        }
        set<segment>::iterator it, it1;
        while(j < ty.size() && ty[j].first.first < ev[i + 1].x){
            it = sweep.lower_bound({ty[j].first, ty[j].first});
            it1 = sweep.upper_bound({ty[j].second, ty[j].second});
            ans += distance(it, it1);
            ++j;
        }
        if(ev[i].id == -1) sweep.erase(where[ev[i].id]);
    }
    cout << ans;
}