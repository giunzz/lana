#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
#define mp(a, b) map<a, b>
#define setE(a, b) fill_n(a, sizeof(a)/sizeof(a[0]), b)
#define st(a) system((a).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

string n;
vec(ll) a, res[2];

int main(){
    opt;
    file;
    cin >> n;
    a.push_back(0);
    for(char i : n) a.push_back(i - '0');
    lp(i, 0, 1) res[i].resize(a.size());
    bool ok[2] = {0};
    lp(i, 1, a.size() - 1){
        if(ok[1]){
            res[1][i] = !(res[1][i - 1] & 1) + 0;
            continue;
        }
        if(ok[0]){
            res[0][1] = !(res[0][i - 1] & 1) + 8;
            continue;
        }
        ll pre = a[i - 1];
        if((pre & 1) == (a[i] & 1)){
            // prc 0 <
            if(a[i] == 0){
                ll tmp = i;
                lpd(j, i - 1, 1){if(a[j] == 0 || a[j] == 1) tmp = j; else break;}
                if(tmp == 1){
                    res[0][0] = a[0] - 1;
                    lp(z, 1, i) res[0][z] = !(res[0][z - 1] & 1) + 8;  
                }
                else{
                    res[0][tmp - 1] = a[i] - 2;
                    lp(z, tmp, i) res[0][z] = !(res[0][z - 1] & 1) + 8;
                }
            }
            else{
                
            }
        }
    }
}
