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
#define pp(type) pair<type, type>
#define vec(type) vector<type>
#define vecite(type) vector<type>::iterator
using namespace std;
const string tenfile = "LDS";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cii maxn = 1e6 + 7;
int n, a[maxn], d[maxn] = {0}, f[maxn] = {0};

int main(){
    //opt;
    fi;
    scanf("%d", &n);
    loop(i, 1, n) {
        scanf("%d", &a[i]);
        d[a[i]] = i;
    }
    int result = 1;
    for (int i=1; i<=n; i++) {
        f[i] = 0;
        for (int j=i-1; j>0; j--) if (!(a[i] % a[j])) {
            f[i] = max(f[i], f[j]);
        }
        f[i] += 1;
        result = max(result, f[i]);
    }
    printf("%d", result);
}