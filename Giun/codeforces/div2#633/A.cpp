#include <bits/stdc++.h>
#define ii int
#define ll long long
#define usn unsigned
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define err(variable) cerr << variable << " "
#define errl(variable) cerr << variable << "\n"
#define loop(variable, valuegan, valuebehonbang) for(long long variable = valuegan; variable <= valuebehonbang; variable++)
#define loopd(variable, valuegan, valuelonhonbang) for(long long variable = valuegan; variable >= valuelonhonbang; variable--)
#define loopdk(variable, valuegan, conditions, thaydoi) for(long long variable = valuegan; conditions; thaydoi) 
#define pp(type) pair<type, type>
#define vec(type) vector<type>
#define vecite(type) vector<type>::iterator
using namespace std;
const string tenfile = "f";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ll a[30], n, t;

void init(){
    a[0] = 1;
    loop(i, 1, 19) a[i] = i * a[i - 1];
}

int main(){
    //init();
    //fi;
    //cerr << a[19];
    scanf("%I64d", &t);
    loop(i, 1, t){
        scanf("%I64d", &n);
        //if (n == 2) printf("%I64d\n", a[2]);
        //else printf("%I64d\n", a[2*n-1]);
        printf("%I64d\n", n);
    }
}