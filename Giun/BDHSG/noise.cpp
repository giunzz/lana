#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for (ll a  =b; a <= c; a++)
#define lpd(a, b, c) for (ll a  =b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void File(const string ff){
    freopen((ff + ".inp").c_str(), "r", stdin);
    freopen((ff + ".out").c_str(), "w", stdout);
}

cll maxm = 107;
ll n, m, k, rm[maxn] = {0}, ans = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    File("noise");
    cin >> n >> m >> k;
    ll tmp;
    lp(i, 1, n){
        cin >> tmp;
        ++rm[tmp];
        ans += rm[tmp];

    }
}
