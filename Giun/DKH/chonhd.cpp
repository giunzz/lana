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
using namespace std;
const string tenfile = "chonhd";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e3 + 7;
ll n, f[maxn], vt[maxn] = {0}, tv[maxn] = {0}, ans = -1, vtans;
pp(ii, ii) a[maxn], b[maxn];
vec(ii) vttv;

bool sortext(const pp(ii, ii) &a, const pp(ii, ii) &b){
    return (a.second < b.second);
}

int main(){
    opt;
    fi;
    cin >> n;
    loop(i, 1, n) {cin >> a[i].first >> a[i].second; b[i].first = a[i].first, b[i].second = a[i].second;}
    sort(a + 1, a + 1 + n, sortext);
    f[0] = 0;
    loop(j, 1, n){
        loop(i, 1, n){
            if (!vt[i] && a[i].first == b[j].first && a[i].second == b[j].second){
                vt[i] = j;
                break;
            }
        }
    }
    a[0].first = 0, a[0].second = 0;
    loop(i, 1, n){
        ll t = -1;
        for(int j = 0; a[j].second <= a[i].first; j++)
            if(f[j] > t) tv[i] = j, t = f[j];
        f[i] = t + 1;
        ans = max(ans, f[i]);
    }
    cout << ans << "\n";
    loopd(i, n, 1)
        if(f[i] == ans) {vtans = i; break;}
    while(vtans){
        vttv.push_back(vtans);
        vtans = tv[vtans];
    }   
    loopd(i, vttv.size() - 1, 0) cout << vt[vttv[i]] << " ";
}
