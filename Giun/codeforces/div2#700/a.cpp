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

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

void sol(){
    string s;
    cin >> s;
    lp(i, 0, s.size() - 1){
        if(i & 1){
            if(s[i] == 'z') s[i] = 'z' - 1;
            else s[i] = 'z';
        }
        else{
            if(s[i] == 'a') s[i] = 'a' + 1;
            else s[i] = 'a';
        }
    }
    cout << s << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    EACHCASE sol();
}