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
const string tenfile = "f";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cii maxn = 1e5 + 7;
int t, a[maxn], n, tt, l = 1, r = 1;
vec(ii) ans;

int main(){
    //fi;
    scanf("%d", &t);
    loop(i, 1, t){
        scanf("%d", &n);
        loop(i, 1, n) scanf("%d", &a[i]);
        sort(a + 1, a + 1 + n);
        tt = 0, l = 1, r = n;
        while (tt < n){
            if (!(tt % 2)) {
                //printf ("%d ", a[l]);
                ans.push_back(a[l]);
                ++l;
            }
            else {
                //printf ("%d ", a[r]);
                ans.push_back(a[r]);
                --r;
            }
            ++tt;
        }
        loopd(i, ans.size() - 1, 0) printf("%d ", ans[i]);
        ans.clear();
        printf("\n");
    }
}
