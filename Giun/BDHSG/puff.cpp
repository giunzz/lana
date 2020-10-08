#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define Fname "puff"
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
using namespace std;

cll maxn = 1e5 + 7;
ll n, k, a[maxn], resMin = INT_MAX, resMax = INT_MIN;
bool tt[maxn];
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
    cin >> n >> k;
    lp(i, 1, n) cin >> a[i];
    cin >> s;
    lp(i, 0, s.size() - 1) tt[i + 1] = s[i] - '0';
    bool stt = 0;
    lp(i, 1, n) {
        if(tt[i]) resMax = max(resMax, a[i]);
        else resMin = min(resMin, a[i]);
    }
    ll tmp;
    // tt[n + 1] = !tt[n];
    lp(i, 1, n){
        if(tt[i] != stt){
            stt = !stt;
            tmp = (i == n + 1 ? n : i);
            lpd(j,  tmp, tmp - k + 1){
                if(stt == 0){
                    resMax = min(a[i] - 1, resMax);
                }
                else{
                    resMin = max(a[i] + 1, resMin);
                }
            }
        }
    }
    for(ll i = n; tt[i] && i >= n - k + 1; --i) resMax = min(a[i], resMax); 
    cout << resMin << ' ' << resMax;
}   