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

cll maxDg = 16;
string n;
vec(ll) dgN;
ll f[maxDg + 1][2][2][136][136][136];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    ll cs;
    cin >> cs;
    while(cs--){
        cin >> n;
        reverse(n.begin(), n.end());
        while(n.size() <= maxDg) n = n + '0';
        dgN.clear();
        while(n.size()) dgN.push_back(n.back() - '0'), n.pop_back();
        sol(maxDg, 0, 0, 0, 0, 0);
    }
}