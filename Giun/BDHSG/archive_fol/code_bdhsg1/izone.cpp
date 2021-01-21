#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define lpdk(a, b, c, d) for(ll a = b; c; d) 
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
using namespace std;
cll MOD = 1e9 + 7;
const string tenfile = "izone";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e3 + 7, maxk = 1e4 + 7;
ll m, n, k, a[maxn][maxn] = {{0}}, f[maxn][maxn] = {{0}}, tmp, dans[maxk] = {0}, crawl[maxk] = {0}, id;
pp(ll, ll) ak[maxk];

// struct ab{
//     ll fi, se;
// }ak[maxk];


void fs(ll &number)
{
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if(c == ' ') fs(number);
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


int main(){
    opt;
    file;
    fs(m); fs(n); fs(k);
    lp(i, 1, m + 1){
        lp(j, 1, n + 1){
            if(i == m+ 1 || j == n + 1){
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
            continue;
            }
            // cin >> a[i][j];
            fs(a[i][j]);
            f[i][j] = a[i][j] + f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
        }
    }
    lp(i, 1, k) {fs(ak[i].fi); ak[i].se = i;}
    sort(ak + 1, ak + 1 + k);
    lp(i, 1, k) crawl[i] = ak[i].fi;
    lp(i, 2, m+1){
        lp(j, 2, n+1){
            tmp = 0;
            if(i < 3 || j < 3){
                if(i < 3 && j >= 3) tmp = f[i][j] - f[i][j - 3] - a[i - 1][j - 1];
                if(i >= 3 && j < 3) tmp = f[i][j] - f[i - 3][j] - a[i - 1][j - 1];
                if (i == 2 && j == 2) tmp = f[i][j] - a[i - 1][ j -1];
            }
            else{
                tmp = f[i][j] - f[i - 3][j] - f[i][j - 3] + f[i - 3][j - 3] - a[i - 1][j - 1];
            }
            //if(i == m && j == n) cerr << tmp;
            id = lower_bound(crawl, crawl + k + 1, tmp) - crawl;
            if(crawl[id] == tmp) dans[ak[id].se] = 1;
        }
    }
    lp(i, 1, k) cout << dans[i] << endl;
}
