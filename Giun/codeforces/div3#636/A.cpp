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

cll maxn = 60;
ll a[maxn], b[maxn], t, n;

int main(){
    opt;
    //fi;
    a[1] = 1, b[1] = 1;
    loop(i, 2, 40) a[i] = a[i - 1]*2, b[i] = b[i - 1] + a[i];
    cin >> t;
    while(t--){
        cin >> n;
        loop(i, 2, 40){
            if(!(n % b[i])) {
                cout << n/b[i] <<endl;
                break;
            }
        }
    }
}