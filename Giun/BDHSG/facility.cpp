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

struct quang{
    ll bg, ed, cs;
};

cll maxn = 1e6 + 7;
ll n, k, f[maxn];
quang a[maxn];

void fastscan(ll &number) 
{ 
    //variable to indicate sign of input number 
    // bool negative = false; 
    register ll c; 
  
    number = 0; 
  
    // extract current character from buffer 
    c = getchar(); 
    // if (c=='-') 
    // { 
    //     // number is negative 
    //     negative = true; 
  
    //     // extract the next character from the buffer 
    //     c = getchar(); 
    // } 
  
    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
  
    // if scanned input has a negative sign, negate the 
    // value of the input number 
    // if (negative) 
    //     number *= -1; 
}

void init(){
    ll s, d, c;
    lp(i, 1, n){
        // cin >> s >> d >> c;
        fastscan(s); fastscan(d); fastscan(c);
        ll end = s + d + k - 1;
        a[i].bg = s;
        a[i].ed = end;
        a[i].cs = c;
    }
}

inline bool cpr(quang &ww, quang &b){
    return ww.ed < b.ed || (ww.ed == b.ed && ww.bg < b.bg);
}

ll cnp(ll const &vl, ll r){
    ll l = 1, ans = -1;
    while(l <= r){
        ll mid = (l + r) / 2;
        if(a[mid].ed < vl) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    return ans;
}

void write(ll x){
    if(x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    // OF();
    // cin >> n >> k;
    fastscan(n); fastscan(k);
    init();
    sort(a + 1, a + 1 + n, cpr);
    f[0] = 0;
    lp(i, 1, n){
        ll pos = cnp(a[i].bg, i - 1);
        if(pos == -1) f[i] = max(a[i].cs, f[i - 1]);
        else f[i] = max(f[i - 1], f[pos] + a[i].cs);
    }
    // cout << f[n];
    // printf("%lld", f[n]);
    write(f[n]);
}