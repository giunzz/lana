#include <bits/stdc++.h>
#define ll long long
#define cll const long long 
#define lp(a, b, c) for (ll a = b; a <= c; a++)
#define lpd(a, b, c) for (ll a = b; a >= c; a--)
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define Fname "eq"
using namespace std;

void File(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

cll Max = 1e6 + 7;
ll f[Max], c[3][Max]  ={{0}};
bool snt[Max] = {0};

void init(){
    fill(f, f + Max, 1);
    snt[0] = snt[1] = 1;
    lp(i, 2, 1e6){
        if(!snt[i]){
            f[i] = i;
            for(ll j = i * 2; j <= 1e6; j += i) snt[j] = 1, f[j] = f[j] * i;
        }
    }
    lp(i, 0, 1e6) c[0][i] = 1;
    lp(i, 1, 1e6){
        lp(j, 1, 2){
            c[j][i] = c[j - 1][i - 1] + c[j][i - 1];
        }
    }
}

vec(ll) tmp;
ll cnt[Max];

int main(){
    File();
    init();
    ll t, a, b, ans;
    cin >> t;
    while(t--){
        tmp.clear();
        ans = 0;
        memset(cnt, 0, sizeof(cnt));
        cin >> a >> b;
        lp(i, a, b){
            if(!cnt[f[i]]++) tmp.push_back(f[i]);
        }
        for(ll i : tmp){
            ans += c[2][cnt[i]];
        }
        cout << ans << ' ';
    }
}