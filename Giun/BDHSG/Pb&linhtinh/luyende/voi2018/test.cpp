#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

vec(pp(ll, ll)) a;

ll cnp(vec(pp(ll, ll)) &q, pp(ll, ll) val){
    ll ans = q.size(), l = 0, r = q.size() - 1;
    while(l <= r){
        ll mid  = (l + r) / 2;
        if(q[mid] >= val){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return ans;
}

map<pp(ll, ll), ll> mp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // OF();
    a.emplace_back(1, 0);
    a.emplace_back(0, 0);
    a.emplace_back(-1, 5);
    a.emplace_back(5, -1);
    a.emplace_back(1, 5);
    a.emplace_back(2, -5);
    a.emplace_back(2, 6);
    a.emplace_back(1, -1);
    sort(a.begin(), a.end());
    ll vt = cnp(a, make_pair(5, 2));
    // cout << vt << '\n';
    // for(auto v : a){
    //     cout << v.first << ' ' << v.second << '\n';
    // }
    mp[pp(ll, ll)(1, 0)] = 3;
    // cerr << mp[pp(ll, ll)(1, 0)] << '\n' << mp[pp(ll, ll)(0, 0)];
    // map<pp(ll, ll), ll>::iterator it = mp.lower_bound(pp(ll, ll)(1, 0));
    // it -> second = 2;
    // mp[pp(ll, ll)(1, 5)] = 1;
    map<pp(ll, ll), ll>::iterator it = mp.lower_bound(pp(ll, ll)(1, 5));
    cout << (it -> first).second;
}