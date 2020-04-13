#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define err(variable) cerr << variable << " "
#define errl(variable) cerr << variable << "\n"
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

cll maxn = 1e5 + 7;
ll t, n, a[maxn], x, ans, lt[64];

int main(){
    opt;
    //fi;
    loop(i, 0, 62) lt[i] = pow(2, i);
    cin >> t;
    while(t--){
        x = 0, ans = INT_MIN;
        cin >> n;
        loop(i, 1, n) {
            cin >> a[i];
            if (a[0] != a[1]) a[0] = a[1];
            while (a[i] < a[i - 1])
                a[i] += lt[x++];
            ans = max(ans, x);
            for(; x >= 0; x--)
                if(a[i] - lt[x] >= a[i - 1]) a[i] -= lt[x];
        }
        cout << ans << "\n";
    }
}