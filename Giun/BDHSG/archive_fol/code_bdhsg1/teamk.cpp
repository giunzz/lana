#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define loop(variable, valuegan, valuebehonbang) for(ll variable = valuegan; variable <= valuebehonbang; variable++)
#define loopd(variable, valuegan, valuelonhonbang) for(ll variable = valuegan; variable >= valuelonhonbang; variable--)
#define loopdk(variable, valuegan, conditions, thaydoi) for(ll variable = valuegan; conditions; thaydoi) 
#define pp(type, type1) pair<type, type1>
#define vec(type) vector<type>
#define vecite(type) vector<type>::iterator
#define MOD 1e9 + 7
using namespace std;
const string tenfile = "teamk";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 5e3 + 7;
ll n, k, a[maxn], b[maxn], sp, f[maxn] = {0}, d[maxn] = {0}, ff[maxn] = {0}, vt, ma = -1, t[maxn] = {0}, ans = 0; //fnsp

void dau(){
    loop(i, 1, n){
        ii vt = lower_bound(b + 1, b + 1 + n, a[i]) - b;
        while(d[vt]) ++vt;
        //cerr << vt << " ";
        ff[i] = ((vt - 1) / k) + 1, d[vt] = 1;
    }
    //cerr << endl << ff[1];    
    //cerr << endl;
}

int main(){
    opt;
    fi;
    cin >> n >> k;
    loop(i, 1, n) cin >> a[i], b[i] = a[i];
    sort(b + 1, b + 1 + n);
    sp = n / k;
    dau();
    memset(d, 0, sizeof(d));
    //loop(i, 1, n) cerr << ff[i] << " ";
    loop(i, 1, n){
        loop(j, 0, i - 1) 
        if(ff[i] >= ff[j] && f[i] < f[j] + 1) f[i] = f[j] + 1, t[i] = j; 
    }
    loop(i, 1, n) {
        if (f[i] > ma) ma = f[i], vt = i;
    }
    //cerr << vt << " ";
    while(vt) {d[vt] = 1, vt = t[vt];}// cerr << vt << " ";}
    loop(i, 1, n){
        if (!d[i]) ++ans;
    }
    cout << ans;
}