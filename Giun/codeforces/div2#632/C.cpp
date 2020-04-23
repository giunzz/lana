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

void fs(int &number)
{ 
    bool negative = false; 
    register int c; 
  
    number = 0; 
    c = getchar(); 
    if (c == ' ') fs(number);
    if (c=='-') 
    { 
        negative = true; 
        c = getchar(); 
    } 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
    if (negative) 
        number *= -1; 
} 

cii maxn = 2e5 + 7;
ll n, a[maxn], ans = 0;
map<ll, ii> mp;

int main(){
    opt;
    //fi;
    a[0] = 0;
    cin >> n;
    loop(i, 1, n) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 0, j = 0; i <= n; ++i){
        ++mp[a[i]];
        while(mp[a[i]] > 1){
            --mp[a[j++]];
        }
        ans += i - j;
    }
    cout << ans;
}