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
cll maxn = 1e3 + 7;
ll n, m, v[maxn], s[maxn], t[maxn], tc[maxn];

int main(){
    opt;
    fin("i.inp");
    fout("o.out");
    cin >> n >> m;
    loop(i, 1, n) {
        cin >> v[i] >> s[i];
        t[i] = v[i] + s[i];
        tc[i] = v[i] / 2 + s[i];
    }
    sort(t + 1, t + 1 + n);
    ll c = 0, d = 0, ans = 0, tt = 0, sm = 0;
    for (int i = 1; i <= n; i++){
        c = 0, d = 0, tt = tc[i], sm = v[i] + s[i];
        for (int j = 1; j <= n + 1 && tt <= m; j++){
            //cerr << 1 << endl;
            if ((v[j] + s[j]) == sm && c == 0){
                c = 1; 
                //cerr << i << " " << j << endl;
                continue;
            }
            //cerr << i << " " << j << " " << tt << endl;
            ++d;
            ans = max(ans, d);
            tt += t[j];
        }
    }
    cout << ans;
}