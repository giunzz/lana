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

map<string, bool> d;
vec(string) a{"ABSINTH", "TEQUILA", "VODKA", "WHISKEY", "WINE", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE"};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // File("ruou");
    for(string &i : a) d[i] = 1;
    lp(i, 0, 17) d[to_string(i)] = 1;
    ll n, ans = 0;
    string tmp;
    cin >> n;
    while(n--){
        cin >> tmp;
        if(d[tmp]) ++ans;
    }
    cout << ans;
}