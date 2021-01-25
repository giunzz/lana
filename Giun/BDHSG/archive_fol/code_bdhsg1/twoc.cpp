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
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

map<char, ll> mp;
ll n, cnt = -1;
string s;
vec(char) id;

bool ktra(string a){

}

int main(){
    opt;
    file;
    cin >> n;
    cin.ignore();
    cin >> s;
    // lp(i, 0, n - 1) ++mp[s[i]];
    // id.resize(n + 3);
    // lp(i, 'a', 'z'){
    //     if(mp[i]) id[mp[i]].push_back(i);
    // }
    // lpd(i, n + 3, 1){
    //     if(!(id[i].empty())){
    //         string sn;
    //         lp(j, 0, n - 1){
    //             lp(q, 0, id[i].size() - 1) {
    //                 if(id[i] == s[j]) {sn.push_back(s[j]); break;}
    //             }
    //         }
    //         if(ktra(sn)){

    //         }
    //     }
    // }
    lp(i, 0, n - 1) {if(!mp[s[i]]) id.push_back(s[i]); ++mp[s[i]];}
    string sn;
    lp(i, 0, id.size() - 1){
        lp(j, i + 1, id.size() - 1){
            if(abs(mp[id[i]] - mp[id[j]]) <= 1){
                
            }
        }
    }
}
