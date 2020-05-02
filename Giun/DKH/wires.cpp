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
cint maxn = 1e5 + 7;
int n, k, a[maxn], sum = 0;

void sol(){
    int l = 1, r = a[1], m, t = 0;
    while (l < r){
        m = (l + r) / 2, t = 0;
        loop(i, 1, n){
            t += a[i] / m;
        }
        //cerr << l << " " <<r << " " << m << " " << t << endl;;
        if (t > k) {
            l = m + 1;
        }
        else if (t < k){
            r = m - 1;
        }
        else break;
    }
    //cerr << r << endl << m << endl << t;
    while (t >= k){
        t = 0, ++m;
        loop(i, 1, n){
            t += a[i] / m;
        }  
    }
    cout << m - 1;
}

int main(){
    opt;
    fin("i.inp");
    fout("o.out");
    cin >> n >> k;
    loop(i, 1, n) cin >> a[i], sum += a[i];
    sort(a + 1, a + 1 + n);
    if (sum < k) cout << 0;
    else if (sum == k) cout << 1;
    else sol();

}