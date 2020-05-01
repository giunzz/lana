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
const string tenfile = "f";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ll t, n, k, num, d[105];
vec(ll) a;

int main(){
    opt;
   //fi;
    cin >> t;
    while(t--){
        a.clear();
        memset(d, 0, sizeof(d));
        cin >> n >> k;
        loop(i, 1, n) {
            cin >> num;
            if(!d[num]) a.push_back(num), d[num] = 1;
        }
        if (a.size() > k || k > n){
            cout << -1 << "\n";
            continue;
        }
        loop(i, 1, n){
            if (a.size() == k) break;
            if (!d[i]) a.push_back(i), d[i] = 1;
        }
        sort(a.begin(), a.end());
        cout << n * k << "\n";
        loop(i, 1, n){
            loop(i, 0, k - 1) cout << a[i] << " ";
        }
        cout << endl;
    }
}