#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 100;
ll k, fibo[maxn], w;    

void init(){
    fibo[1] = fibo[2] = 1;
    lp(i, 3, 100){
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        if(fibo[i] > 1e15){w = i - 1; return;}
    }
}

ll cnp(ll &val){
    ll r = 1, l = w, ans = 1; 
    while(r <= l){
        ll mid = (l + r) / 2;
        if(fibo[mid] <= val) ans = fibo[mid], r = mid + 1;
        else l = mid - 1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // OF();
    init();
    // lp(i, 1, w) cerr << fibo[i] << '\n';
    ll cs, x, s;
    cin >> cs;
    while(cs--){
        s = 0;
        cin >> x >> k;
        ll cnt = 0;
        lpd(i, x, 1){
            // cerr << cs << ' ';
            cnt = 0;
            ll n = i;
            while(n > 0){
                // cerr << n <<  ' ';
                n -= cnp(n);
                ++cnt;
            }
            if(cnt >= k) s += cnt;
            // else break;
        }
        cout << s << '\n';
    }
    //editor: 
    // dequeue voi i loai nhung end trc begin i lay ket qua
}