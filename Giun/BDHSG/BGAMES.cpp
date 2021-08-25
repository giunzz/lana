#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "bgames"
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

cll mxn = 3e5 + 7, mxv = 1e6 + 6;
ll n, k, a[mxn], memo[mxv], cnt[mxv] = {0};

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    memset(memo, -1, sizeof memo);
    cin >> n >> k;
    lp(i, 1, n){
        cin >> a[i];
        ++cnt[a[i]];
        a[i] -= k;
    }
    lp(i, 1, n){
        if(a[i] < 0){
            cout << "0 ";
            continue;
        }
        if(memo[a[i]] != -1){
            cout << memo[a[i]] << ' ';
            continue;
        }
        --cnt[a[i] + k];
        memo[a[i]] = 0;
        if(a[i] == 0) lp(j, 1, n){ 
            if(a[j] > a[i]) ++memo[a[i]];
        }
        else
            for(ll j = 1; j * j <= a[i]; ++j) if(a[i] % j == 0){ 
                if(j > k) memo[a[i]] += cnt[j];
                if(j != a[i] / j && a[i] / j > k) memo[a[i]] += cnt[a[i] / j];
            }
        ++cnt[a[i] + k];
        cout << memo[a[i]] << ' ';
    }
}