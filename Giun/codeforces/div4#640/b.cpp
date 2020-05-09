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

ii t;
ll n, k;

int main(){
    opt;
    fi;
    cin >> t;
    while(t--){
        cin >> n >> k;
        if (n % 2 && !(k % 2)) cout << "NO\n";
        else{
            if (n == k) {
                cout << "YES\n";
                loop(i, 1, k) cout << "1 ";
                cout << endl;
            }
            else if(!(n % 2)){
                if (2 * (k - 1) >= n) {cout << "NO\n"; continue;}
                cout << "YES\n";
                loop(i, 1, k - 1) cout << "2 ";
                cout << n - 2 * (k - 1) << endl;
            }
            else{
                if(k - 1 >= n) {cout << "NO\n"; continue;}
                cout << "YES\n";
                loop(i, 1, k - 1) cout << "1 ";
                cout << n - k + 1 << endl;
            }
        }
    }
}