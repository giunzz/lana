#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define er(variable) cerr << variable << " "
#define erl(variable) cerr << variable << "\n"
#define loop(variable, valuegan, valuebehonbang) for(long long variable = valuegan; variable <= valuebehonbang; variable++)
#define loopd(variable, valuegan, valuelonhonbang) for(long long variable = valuegan; variable >= valuelonhonbang; variable--)
#define loopdk(variable, valuegan, conditions, thaydoi) for(long long variable = valuegan; conditions; thaydoi) 
#define pp(type, type1) pair<type, type1>
#define vec(type) vector<type>
#define vecite(type) vector<type>::iterator
using namespace std;
const string tenfile = "f";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 2e5 + 7;
ll t, n, a[maxn], s, ma;

ll dau(int q){
    if (q < 0) return -1;
    return 1;
}

int main(){
    opt;
    //fi;
    a[0] = 0;
    cin >> t;
    while(t--){
        s = 0, ma = INT_MIN;
        cin >> n;
        loop(i, 1, n){
            cin >> a[i];
            if (i == 1){
                ma = a[i];
                continue;
            }
            if(dau(a[i - 1]) != dau(a[i])){
                s += ma;
                //if (t == 4) cerr << a[i] << " ";
                ma = a[i];
            }
            else ma = max(ma, a[i]);
            //cerr << ma << " " << i << endl;
        }
        cerr << ma;
        s += ma; 
        cout << s << endl;
    }
}