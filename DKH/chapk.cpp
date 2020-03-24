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
#define pp pair<long long, long long>
#define vec vector <long long>
#define ii int
#define ll long long
#define cint const int
#define cll const long long
using namespace std;

cll maxn = 27, maxa = 1e6 + 7;
ll n, k, d[maxa] = {0}, tc = 0, a[maxn], ans[maxn] = {-1};

void nhap(){
    int l;
    loop(i, 1, n){
        in(l);
        if (!d[l]) a[++tc] = l;
        ++d[l];
    }
    sort(a + 1, a + 1 + tc);
}

void xuat(){
    loop(i, 1, k){
        out(ans[i]);
    }
    out("\n");
}

void ql(int vt){
    if(vt == k + 1) xuat();
    else loop(i, 1, tc){
        if(ans[vt - 1] <= a[i] && d[a[i]] && ans[vt] != a[i]){
            ans[vt] = a[i], --d[a[i]];
            ql(vt + 1);
            ++d[a[i]];
        }
    }
}

int main(){
    opt;
    cout.tie(0);
    fin("i.inp");
    fout("o.out");
    in(n); in(k);
    nhap();
    ql(1);
}