#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "diferen"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 3e5 + 7;
ll n, a[maxn] = {0}, l[maxn], r[maxn];

ll gmin(){
    ll ans = 0;
    vector<ll> deque;
    deque.push_back(0);
    lp(i, 1, n){
        while(deque.size() > 1 && a[deque.back()] >= a[i]) deque.pop_back();
        l[i] = deque.back() + 1;
        deque.push_back(i);
    }
    deque.clear();
    deque.push_back(n + 1);
    lpd(i, n, 1){
        while(deque.size() > 1 && a[deque.back()] > a[i]) deque.pop_back();
        r[i] = deque.back() - 1;
        deque.push_back(i);
    }
    lp(i, 1, n)
        ans += (i - l[i] + 1) * (r[i] - i + 1) * a[i];
    return ans;
}

ll gmax(){
    ll ans = 0;
    vector<ll> deque;
    deque.push_back(0);
    lp(i, 1, n){
        while(deque.size() > 1 && a[deque.back()] <= a[i]) deque.pop_back();
        l[i] = deque.back() + 1;
        deque.push_back(i);
    }
    deque.clear();
    deque.push_back(n + 1);
    lpd(i, n, 1){
        while(deque.size() > 1 && a[deque.back()] < a[i]) deque.pop_back();
        r[i] = deque.back() - 1;
        deque.push_back(i);
    }
    lp(i, 1, n)
        ans += (i - l[i] + 1) * (r[i] - i + 1) * a[i];
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    lp(i, 1, n) cin >> a[i];
    ll ans = gmax() - gmin();
    cout << ans;
}