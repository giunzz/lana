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
const string tenfile = "giun";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cii maxn = 1e4 + 7;
ii n, d, a[maxn], c[maxn] = {0}, k, ans = 0;

int main(){
    opt;
    fi;
    cin >> n >> d;
    loop(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n);
    loopd(i, n, 1){
        cerr << i ;
        if(c[i]) continue;
        c[i] = 1;
        if(a[i] + a[1] > d || i == 1) ++ans;
        else{
            k = lower_bound(a + 1, a + 1 + i, d - a[i]) - a;
            if (k == i + 1) ++ans;
            else{
                while(c[k]) --k;
                if(!k) ++ans;
                else c[k] = 1, ++ans;
                cerr << 1;
            }
        }
    }
    cout << ans;
}