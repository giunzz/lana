#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void OF(const string f){
    freopen((f + ".inp").c_str(), "r", stdin);
    freopen((f + ".out").c_str(), "w", stdout);
}

ll n, k, t, stt[256] = {0}, dem = 0;
string s, res;
bool ok = 0;

void compress(){
    set<char> q(s.begin(), s.end());
    string t(q.begin(), q.end());
    s = t;
}

void ql(ll pos){
    if(ok) return;
    if(pos == n){
        vec(ll) cnt(s.size(), 0);
        ll ct = 0;
        for(char c : res){
            ll tt = 0;
            ++cnt[stt[c]];
            lp(i, 0, s.size() - 1) if(cnt[i] & 1) ++tt;
            if(tt < 2) ++ct;
        }
        --ct;
        // if(res == "nvn") cerr << ct;
        ll tmp = 0;
        lp(i, 0, s.size() - 1) if(cnt[i] & 1) ++tmp;
        if(tmp > 1 || ct - 1 < k) return;
        if(++dem == t){
            cout << res;
            ok = 1;
        }
        return;
    }
    lp(i, 0, s.size() - 1){
        res.push_back(s[i]);
        ql(pos + 1);
        res.pop_back();
    }
}

void sub1(){
    if(n == 2){
        if(t == 1) cout << s[0] << s[0];
        else cout << s[1] << s[1];
    }
    else if(n & 1){
        --t;
        vec(ll) b;
        while(t) b.push_back(t & 1), t >>= 1;
        while(b.size() < n) b.push_back(0);
        lpd(i, n - 1, 0) cout << s[b[i]];
    }
    else ql(0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF("qpalin");
    cin >> n >> k >> s >> t;
    compress();
    lp(i, 0, s.size() - 1) stt[s[i]] = i;
    if(s.size() == 2 && k == 0) sub1();
    else if(n <= 10) ql(0);
}