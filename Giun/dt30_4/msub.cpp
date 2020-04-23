#include <bits/stdc++.h>
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define fin(tenfile) freopen(tenfile, "r", stdin)
#define fout(tenfile) freopen(tenfile, "w", stdout)
#define in(variable) cin >> variable
#define out(variable) cout << variable << " "
#define outl(variable) cout << variable << "\n"
#define err(variable) cerr << variable << " "
#define errl(variable) cerr << variable << "\n"
#define loop(variable, valuegan, valuebehonbang) for(int variable = valuegan; variable <= valuebehonbang; variable++)
#define loopd(variable, valuegan, valuelonhonbang) for(int variable = valuegan; variable >= valuelonhonbang; variable--)
#define loopdk(variable, valuegan, conditions, thaydoi) for(int variable = valuegan; conditions; thaydoi) 
#define pp pair<int, int>
#define vec vector <int>
#define ll long long
#define cint const int
#define cll const long long
using namespace std;
cll maxn = 1e5 + 7;
ll n, a[maxn], m, i = 1, j = 1;

int main(){
    opt;
    fin("i.inp");
    fout("o.out");
    cin >> n >> m;
    loop(i, 1, n) in(a[i]);
    ll s = a[1], d = 0;
    i = 1, j = 1;
    while (j <= n){
        if (s == m){
            s = s - a[i];
            ++d, ++i;
            //cerr << i << " " << j << " " << s << endl;
        }  
        else if (s < m){
            ++j;
            s = s + a[j];
        }
        else if (s > m) {
            s = s - a[i];
            ++i;
        }
        if (j < i) {
            j = i;
            s = a[j];
        }
    }
    cout << d;
    return 0;
}