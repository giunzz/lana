#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(obj1, obj2, obj3) for(ll obj1 = obj2; obj1 <= obj3; obj1++)
#define lpd(obj1, obj2, obj3) for(ll obj1 = obj2; obj1 >= obj3; obj1--)
#define pp(obj1, obj2) pair<obj1, obj2>
#define vec(obj1) vector<obj1>
#define vecite(obj1) vector<obj1>::iterator
#define fi first
#define se second
#define im INT_MIN
#define mp(obj1, obj2) map<obj1, obj2>
#define st(obj) system((obj).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "select";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e4 + 7;
ll n, maS[3] = {im}, m[maxn][5] = {{0}}, f[maxn][9] = {{0}}, tt[] = {0, 1, 2, 4, 5, 8, 9, 10}, ans = im, ma[maxn] = {im};

int main(){
    opt;
    //file;
   // fs(n);
   cin >> n;
    lp(j, 1, 4){
        lp(i,1,n) cin >> m[i][j];
    }
    lp(i, 1, n){
        lp(j, 1, 7){
            ll t = tt[j], v = 4, sum = 0, getS = im;
            while(t){
                if(t&1) sum += m[i][v];
                t = t >> 1; --v;
            }
            //if(j == 6 && i == 3) cerr << sum << endl;
            lp(tr, 1, 7){
                if(!(tt[tr] & tt[j])) getS = max(getS, f[i-1][tr]);
            }
            if(i == 1) getS = 0;
            getS = max(maS[1], getS);
            //lp(k, 1, i - 2) {
            //    getS = max(getS, ma[k]);
            //}
            f[i][j] = max(sum + getS, sum);
            ma[i] = max(f[i][j], ma[i]);
            ans = max(ans, f[i][j]);
            //cerr << getS << " ";
        }
        maS[1] = max(maS[2], maS[1]);
        maS[2] = ma[i];
      // cerr << endl;
       //cout << ma[i] << endl;
    }
    //cerr << f[3][6];
    cout << ans;
}
