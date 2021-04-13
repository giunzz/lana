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

// n <= 1e5, m <= 16, k <= m;
cll mxn = 1e5 + 7, mxm = (1 << 16) + 3;
ll n, m, k, cntbit[mxm] = {0}, test = 0, ans = 0;
vec(ll) jump[mxm];

inline void gene(ll pos, bool ok, ll cnt, bitset<17> &num, bitset<17> const &t){
    if(pos == 0){
        if(cnt == k){ 
            // jump[t.to_ullong()].push_back(num.to_ullong());
            ans += cntbit[t.to_ullong()] * cntbit[num.to_ullong()];
            if(t == num) --ans;
        }
    } else{
        ll npos = pos - 1;
        bitset<17> &nnum = num;
        lp(i, 0, 1){
            nnum[npos] = i;
            if(ok){
                if(i < t[npos]){
                    if(cnt < k){
                        gene(npos, 0, cnt + 1, nnum, t);
                    }
                } else if(i == t[npos] && npos + cnt >= k){
                    gene(npos, 1, cnt, nnum, t);
                }
            } else{
                if(i != t[npos]){
                    if(cnt < k){
                        gene(npos, ok, cnt + 1, nnum, t);
                    }
                } else if(npos + cnt >= k){
                    gene(npos, ok, cnt, nnum, t);;
                }
            }
        }
    }
}

void init(){
    lp(i, 0, mxm - 1){
        bitset<17> tmp = 0, tmp1 = i;
        gene(16, 1, 0, tmp, tmp1);
    }
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m >> k;
    lp(i, 1, n){
        string s;
        cin >> s;
        ++cntbit[bitset<17>(s).to_ullong()];
    }
    init();
    cerr << test << ' ' << clock();
    cout << ans;
    // cerr << bitset<6>(18) << '\n';
    // for(ll i : jump[18]) cerr << bitset<6>(i) << '\n';
}