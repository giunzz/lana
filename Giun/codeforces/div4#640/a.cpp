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

ii t, i, m;
string s;
vec(ii) ans;

int main(){
    opt;
    //fi;
    cin >> t;
    cin.ignore();
    while(t--){
        m = 1;
        ans.clear();
        getline(cin, s);
        i = s.length() - 1;
        while(i >= 0){
            if(s[i] != '0') ans.push_back((s[i] - '0') * m);
            m *= 10, --i;
        }
        cout << ans.size() << endl;
        loop(i, 0, ans.size() - 1) cout << ans[i] << " ";
        cout << endl;
    }
}