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

cll maxn = 2e5 + 7;
string a, b;
ll p[maxn] = {0};
// unordered_map<string, ll> d;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> a >> b;
    swap(a, b);
    string tmp = '0' + a + b;
    // tmp.resize(a.size(), '*'); 
    // lpd(i, a.size() - 1, 0){
    //     tmp[i] = a[i];
    //     d[tmp] = a.size() - i;
    // }
    // tmp = b;
    // while(tmp.size()){
    //     if(d[tmp]){
    //         cout << (a + b.substr(tmp.size()));
    //         return 0;
    //     }
    //     tmp.pop_back();
    // }
    // cerr << tmp;
    ll k = 0;
    cerr << a << ' ' << b << '\n';
    lp(i, 2, a.size()){
        // ll k = i - 1;
        while(k > 0 && tmp[k + 1] != tmp[i]) k = p[k];
        if(tmp[k + 1] == tmp[i]) ++k;
        p[i] = k;
        // cerr << 1;
    }
    // lp(i, 1, a.size()) cerr << p[i] << ' ';
    lp(i, a.size() + 1, tmp.size() - 1){
        // ll k = i - 1;
        while((k >= a.size() || k >= b.size() || tmp[k + 1] != tmp[i]) && k > 0) k = p[k];
        if(tmp[k + 1] == tmp[i]) ++k;
        p[i] = k;
    }
    // lp(i, 1, tmp.size() - 1) cerr << p[i] << ' ';
    ll res = p[tmp.size() - 1];
    // cerr << res;
    cout << b << a.substr(res);
    // if(res <= a.size()) cout << a + b.substr(res);
    // else cout << tmp.substr(1, res);
}