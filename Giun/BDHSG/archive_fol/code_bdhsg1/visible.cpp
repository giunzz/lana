#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "visible"
using namespace std;

void OF(){
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

ll n;
vec(ll) a, r, l;
string s;
stack<ll> d;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    a.resize(n+2); r.resize(n + 2); l.resize(n + 2); 
    lp(i, 1, n) cin >> a[i];
    a[0] = r[0] = l[0] = 0;
    cin >> s;
    lp(i, 1, n){
        while(d.size() && d.top() < a[i]) d.pop();
        l[i] = d.size();
        ++l[i];
        d.push(a[i]);
    }
    while(d.size()) d.pop();
    a[n + 1] = l[n + 1] = r[n + 1] = 0;
    lpd(i, n, 1){
        while(d.size() && d.top() < a[i]) d.pop();
        r[i] = d.size();
        ++r[i];
        d.push(a[i]);
    }
    lp(i, 1, n){
        if(s[i - 1] == 'L'){
            cout << l[i - 1] << ' ';
        }
        else cout << r[i + 1] << ' ';
    }
}