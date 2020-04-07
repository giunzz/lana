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
#define ll long long
#define cint const int
#define cll const long long
using namespace std;

cint maxn = 3e5 + 7, maxh = 1e6 + 7;
int n, k, h[maxn], cnt[maxh] = {0}, ans[maxh] = {0}, d[maxh] = {0};

void bangk(){
    if (cnt[k] != 0){
        int dem = 0;
        loop(i, 1, n){
            if (h[i] > k) ++dem;
        }
        ans[k] = dem;
    }
}

void honk(){
    int c;
    loop(i, 1, n){
        if (h[i] > k && !d[h[i]]){
            d[h[i]] = 1, c = h[i] - k;
            loopdk(j, 1, j * j <= c, j++){
                if (c % j == 0){
                    if(j > k) ans[h[i]] += cnt[j];
                    if (c / j > k && j > 1) ans[h[i]] += cnt[c / j];
                }
            }
            if (k == 0) ans[h[i]] += cnt[h[i]] - 1;
        }
    }
}

int main(){
    opt;
    fin("bgames.inp");
    fout("bgames.out");
    in(n); in(k);
    loop(i, 1, n){
        in(h[i]);
        ++cnt[h[i]];
    }
    bangk();
    honk();
    loop(i, 1, n){
        out(ans[h[i]]);
    }
}