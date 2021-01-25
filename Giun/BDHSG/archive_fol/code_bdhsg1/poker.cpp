#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define lpdk(a, b, c, d) for(ll a = b; c; d) 
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
using namespace std;
cll MOD = 1e9 + 7;
const string tenfile = "poker";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

const char chat[] = {'P', 'K', 'H', 'T'};
const string num[] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13"};
map<char, map<string, ll>> cnt;
string s;
ll ok = 0, ans = 0;

int main(){
    opt;
    file;
    cin >> s;
    for(ll i = 0; i < s.length(); i++){
        ++cnt[s[i]][s.substr(i + 1, 2)];
        if(cnt[s[i]][s.substr(i+1, 2)] > 1){ok = 1; break;}
        i += 2;
    }
    if(ok) {cout << -1; return 0;}
    lp(i, 0, 3){
        ans = 0;
        lp(j, 0, 12){
            if(!cnt[chat[i]][num[j]]) ++ans;
        }
        cout << ans << " ";
    }
}
