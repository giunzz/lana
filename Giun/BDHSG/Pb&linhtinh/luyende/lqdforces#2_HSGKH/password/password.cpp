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
map<string, ll> cnt;

void init(){
    string tmp;
    map<string, bool> d;
    lp(i, 1, n){
        d.clear();
        cin >> a[i];
        lp(j, 0, a[i].size() - 1) {
            tmp.clear();
            if(j == 0 && )
            lp(k, j, a[i].size() - 1) tmp.push_back(a[j][k]);
            if(!d[tmp]) d[tmp] = 1, ++cnt[tmp];
        } 
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    File("pb");
    cin >> n;

}