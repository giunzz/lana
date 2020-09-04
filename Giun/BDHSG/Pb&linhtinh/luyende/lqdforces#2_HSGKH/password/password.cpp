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

cll maxn = 1e4 + 7;
string a[maxn];
ll n;
map<string, ll> d;

void init(){
    lp(i, 1, n){
        cin >> a[i];
        ++d[a[i]];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    File("password");
    cin >> n;
    init();
    ll cnt;
    string tmp;
    map<string, bool> check;
    lp(i, 1, n){
        cnt = 0;
        check.clear();
        lp(j, 0, a[i].size() - 1){
            tmp.clear();
            lp(k, j, a[i].size() - 1){
                tmp.push_back(a[i][k]);
                if(!check[tmp]) cnt += d[tmp], check[tmp] = 1;
            }
        }
        cout << (cnt - 1) << endl;
    }
}