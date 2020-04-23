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

cii maxn = 2e5 + 7;
ii cnt[maxn], t, n, num, ma;
vec(ii) a;

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

vec(int) change(){
    set<int> s(a.begin(), a.end());
    vector<int> b(s.begin(), s.end());
    return b;
}

int main(){
    opt;
    //fi;
    cin >> t;
    while(t--){
        memset(cnt, 0, sizeof(cnt));
        cin >> n;
        ma = INT_MIN;
        loop(i, 0, n - 1){
            cin >> num;
            a.push_back(num);
            ++cnt[a[i]];
            if (cnt[a[i]] > ma) ma = cnt[a[i]];
        }
        a = change();
        if (a.size() - 1 >= ma) cout << ma << endl;
        else if(a.size() == ma) cout << ma - 1 << endl; 
        else cout << a.size() << endl;
        a.clear();
    }
}