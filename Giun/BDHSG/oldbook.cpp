#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define Fname "oldbook"
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
using namespace std;

ll n, k;
string s, res, res1;
bool d[200] = {0};

string compress(string x){
    set<char> tmp(x.begin(), x.end());
    string t(tmp.begin(), tmp.end());
    return t;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
    cin >> n >> s >> k;
    string cp = compress(s);
    // cerr << cp;
    // s = "0" + s;
    // if(cp.size() == 2){
    //     cout << cp[1];
    //     lp(i, 2, k) cout << cp[0];
    //     return 0;
    // }
    // for(char &c : s) d[c] = 1;
    // lp(i, 1, k){
    //     if(i > n) res.push_back(cp[1]);

    // }
    // s = "0" + s;
    // string res = "0" + to_string(s[1]), tmp, tmp1, tmp2;
    // lp(i, 2, k){
    //     if(i > n){res.push_back(cp[0]); continue;}
    //     tmp = tmp1 = tmp2 = res;
    //     tmp2.push_back(cp.back());
    //     ll pos = lower_bound(cp.begin(), cp.end(), s[i]) - cp.begin();
    //     if(pos != cp.size() - 1) tmp.push_back(cp[pos + 1]);
    //     pos = lower_bound(cp.begin(), cp.end(), s[i - 1]) - cp.begin();
    //     if(pos != cp.size() - 1) {tmp1.pop_back(); tmp1 += to_string(cp[pos + 1]) + to_string(cp[0]);}
    //     if(tmp1.size() == i) res = tmp1; 
    // }
    if(k > n){
        cout << s;
        lp(i, n + 1, k) cout << cp[0];
    }
    else{
        lp(i, 0, k - 1) res.push_back(s[i]);
        lpd(i, k - 1, 0){
            ll tmp = lower_bound(cp.begin(), cp.end(), s[i]) - cp.begin();
            if(tmp < cp.size() - 1){
                lp(j, 0, i - 1) cout << s[j];
                cout << cp[tmp + 1];
                lp(j, i + 1, k - 1) cout << cp[0];
                return 0;
            }
        }
    }
}