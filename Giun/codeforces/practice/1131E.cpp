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

cll mxc = 'z' - 'a' + 1;
ll n, cnt[2][mxc] = {{0}};
string s;

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n){
        cin >> s;
        memset(cnt[1], 0, sizeof cnt[1]);
        ll c1 = 0, c2 = 0, j = 1;
        while(j < s.size()) if(s[j] == s[j - 1]) ++j; else break;
        c1 = cnt[1][s[0] - 'a'] = j;
        if(c1 == s.size()){
            cnt[0][s[0] - 'a'] += (cnt[0][s[0] - 'a'] + 1) * c1;
            lp(j, 0, mxc - 1){
                if(j != s[0] - 'a') cnt[0][j] = (cnt[0][j] != 0);
            }
        } else{
            ll tmp = 0;
            while(j < s.size()){
                if(s[j] == s[j - 1]) ++tmp;
                else cnt[1][s[j - 1] - 'a'] = max(cnt[1][s[j - 1] - 'a'], tmp), tmp = 1;
                ++j;
            }
            c2 = tmp;
            cnt[1][s.back() - 'a'] = max(cnt[1][s.back() - 'a'], c2);
            if(s[0] == s.back() && cnt[0][s[0] - 'a']){
                // cnt[0][s[0] - 'a'] = max({(cnt[0][s[0] - 'a'] != 0) + c1 + c2, })
                cnt[1][s[0] - 'a'] = max(cnt[1][s[0] - 'a'], c1 + c2 + 1);
            }
            if(cnt[0][s[0] - 'a']) cnt[1][s[0] - 'a'] = max(cnt[1][s[0] - 'a'], c1 + 1);
            if(cnt[0][s.back() - 'a']) cnt[1][s.back() - 'a'] = max(cnt[1][s.back() - 'a'], c2 + 1);
            lp(i, 0, mxc - 1) cnt[0][i] = max((cnt[0][i] != 0) * 1LL, cnt[1][i]);
        }
    }
    cout << *max_element(cnt[0], cnt[0] + mxc);
}