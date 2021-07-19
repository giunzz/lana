#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "ac1"

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}
#define EACHCASE lpd(cs, read(), 1)

cll mxn = 77;
string a, b, t, res;
vec(ll) ch[30];
bool d[mxn], ok;
ll cnt[30];

void ql(ll pos){
    if(pos == a.size()){
        bool tmp = 1;
        lp(i, 'A', 'Z') if(cnt[i - 'A']){tmp = 0; break;}
        if(tmp) ok = 1;
        return;
    }
    if(cnt[a[pos] - 'A']){
        --cnt[a[pos] - 'A'];
        ql(pos + 1);
        ++cnt[a[pos] - 'A'];
        if(ok) return;
    }
    if(cnt[b[pos] - 'A']){
        --cnt[b[pos] - 'A'];
        ql(pos + 1);
        ++cnt[b[pos] - 'A'];
        if(ok) return;
    }
    ql(pos + 1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
    EACHCASE{
        // memset(d, 0, sizeof d);
        memset(cnt, 0, sizeof cnt);
        // lp(i, 0, 27) ch[i].clear();
        // res.clear();
        ok = 0;
        cin >> a >> b >> t;
        for(char c : t) ++cnt[c - 'A'];
        // lp(i, 0, 26) cerr << cnt[i] << ' ';
        // lp(i, 0, a.size() - 1){
        //     if(cnt[a[i]] && cnt[b[i]] && a[i] != b[i]) d[i] = 1;
        //     if(cnt[a[i]]) ch[a[i] - 'A'].push_back(i);
        //     if(cnt[b[i]] && a[i] != b[i]) ch[a[i]]
        // }
        ql(0);
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
