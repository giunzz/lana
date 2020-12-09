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
const string tenfile = "sodep";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

string n;
vec(ll) a, res[2];

vec(ll) diff(vec(ll) &x, vec(ll) &y){
    vec(ll) tmp(x.size());
    ll car = 0;
    lpd(i, tmp.size() - 1, 0){
        ll num = x[i] - y[i] - car;
        if(num < 0) num += 10, car = 1;
        else car = 0;
        tmp[i] = num;
    }
    return tmp;
}

int main(){
    opt;
    file;
    cin >> n;
    a.push_back(0);
    for(char i : n) a.push_back(i - '0');
    lp(i, 0, 1) res[i].resize(a.size());
    bool ok[2] = {0, 0};
    res[1][1] = res[0][1] = a[1];
    lp(i, 2, a.size() - 1){
        if(ok[1]){
            res[1][i] = !(res[1][i - 1] & 1) + 0;
        }
        if(ok[0]){
            res[0][i] = !(res[0][i - 1] & 1) + 8;
        }
        if(ok[1]) continue;
        ll pre = a[i - 1];
        if((pre & 1) == (a[i] & 1)){
            // prc 0 <
            if(a[i] == 0){
                ll tmp = i;
                lpd(j, i - 1, 2){if(a[j] == 0 || a[j] == 1) tmp = j; else break;}
                if(tmp == 2){
                    res[0][1] = a[1] - 1;
                }
                else{
                    res[0][tmp - 1] = a[tmp - 1] - 2;
                }
                lp(z, tmp, i) res[0][z] = !(res[0][z - 1] & 1) + 8;  
            }
            else{
                res[0][i] = a[i] - 1;
            }
            ok[0] = 1;
            // prc 1 >
            if(a[i] == 9){
                ll tmp = i;
                lpd(j, i - 1, 2){if(a[j] == 8 || a[j] == 9) tmp = j; else break;}
                if(tmp == 2){
                    res[1][1] = (a[1] + 1) % 10;
                    res[1][0] = (a[1] + 1) / 10;
                }
                else{
                    res[1][tmp - 1] = a[tmp - 1] + 2;
                }
                lp(z, tmp, i) res[1][z] = !(res[1][z - 1] & 1) + 0;  
            }
            else{
                res[1][i] = a[i] + 1;
            }
            ok[1] = 1;
        }
        else res[0][i] = res[1][i] = a[i];
    }
    vec(ll) d1 = diff(a, res[0]), d2 = diff(res[1], a);
    ll cs = 2;
    lp(i, 0, d1.size() - 1) 
        if(d1[i] < d2[i]){cs = 0; break;}
        else if(d1[i] > d2[i]){cs = 1; break;}
    if(cs == 2) lp(x, 0, 1){
        ll j = 0;
        while(!res[x][j]) ++j;
        lp(i, j, res[x].size() - 1) cout << res[x][i];
        cout << ' ';
    }
    else{
        ll j = 0;
        while(!res[cs][j]) ++j;
        lp(i, j, res[cs].size() - 1) cout << res[cs][i];
    }
}
