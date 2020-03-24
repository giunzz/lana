#include <bits/stdc++.h>
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
//opt = optimize 
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
cint maxn = 2e5 + 7;
pp b[1007], a[maxn];
int n;

int main(){
    opt;
    fin("i.inp");
    fout("o.out");
    cin >> n;
    char c;
    loop(i, 1, n){
        cin >> c;
        if (c == 'A'){
            cin >> a[i].first >> a[i].second;
        }
        
    }
}