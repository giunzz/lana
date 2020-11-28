#include <bits/stdc++.h>
#define ll int
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void file(const string file){
    freopen((file + ".inp").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
}

vec(ll) a;
vec(bool) d;
ll n;

int main(){
    // file("dnprevoia");
    cin >> n >> n;
    a.resize(n + 1), d.resize(n + 1);
    lp(i, 1, n) d[i] = 0;
    lp(i, 1, n){
        cin >> a[i];
        if(a[i] != -1) d[a[i]] = 1;
    }
    ll j = 1;
    lp(i, 1, n){
        if(a[i] != -1) cout << a[i] << ' ';
        else{
            while(d[j]) ++j; d[j] = 1;
            cout << j << ' ';
        }
    }
}