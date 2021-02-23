#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "2array"
using namespace std;

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 1e6 + 7, mx = 1e6;
ll n, m, sang[maxn] = {0};
vec(ll) uoc[2], snt;
unordered_map<ll, ll> cntU[2];

void init(){
    sang[0] = sang[1] = 1;
    lp(i, 2, mx){
        if(!sang[i]){
            sang[i] = -1;
            if(i <= 1e4) snt.push_back(i);
            for(ll j = i * i; j <= mx; j += i) sang[j] = i;
        }
    }
}

void process(vec(ll) &uoc, ll tot, unordered_map<ll, ll> &cnt){
    lp(i, 1, tot){
        ll num = read(), j = 0;
        while(num != 1){
            if(num > mx){
                while(j < snt.size() && (num % snt[j])) ++j;
                if(j == snt.size()){
                    if(!cnt[num]++) uoc.push_back(num);
                    num /= num;
                }
                else
                    while(!(num % snt[j])) {if(!cnt[snt[j]]++) uoc.push_back(snt[j]); num /= snt[j];}
            }
            else{
                if(sang[num] == -1){if(!cnt[num]++) uoc.push_back(num); num /= num;}
                else{
                        ll tmp = sang[num];
                        if(!cnt[tmp]) uoc.push_back(tmp);
                        while(!(num % tmp)){
                        num /= tmp, ++cnt[tmp];
                    }
                }
            }
        }
    }
}

void sol(){
    cin >> n >> m;
    lp(i, 0, 1) uoc[i].clear(), cntU[i].clear();
    process(uoc[0], n, cntU[0]);
    process(uoc[1], m, cntU[1]);
    bool ans = 1;
    lp(stt, 0, 1) for(ll i : uoc[stt]) if(cntU[1][i] != cntU[0][i]) ans = 0;
    if(ans) cout << "1\n";
    else cout << "0\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    init();
    EACHCASE sol();
}