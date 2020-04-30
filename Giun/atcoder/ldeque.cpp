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

cll Max = 3e3 + 3;
ll n, x[Max][Max] = {{0}}, a[Max] = {0}, y[Max][Max] = {{0}}, l;

int main(){
    opt;
    fi;
    cin >> n;
    loop(i, 1, n) cin >> a[i];
    l = n % 2;
    if(l) loop(i, 0, n) x[i][i] = a[i];
    else loop(i, 0, n) y[i][i] = a[i];
    l = (l + 1) % 2;
    loop(i, 1, n - 1){
        loop(j, i + 1, n){
            if(l) x[i][j] =  
        }
    }
}