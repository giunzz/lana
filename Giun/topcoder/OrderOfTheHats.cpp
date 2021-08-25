#include <bits/stdc++.h>
#include "OrderOfTheHats.h"
#define ll int
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "f"
using namespace std;

/**
 * dp[mask][i] la so phep bien doi it nhat de di qua dc cac dinh trong mask va ket thuc tai i
 * for tung trang thai trong mask vs vi tri se dung trc i nen status[j][i] = 'Y' va status[i][j] = 'N'
*/
void errmask(ll mask, ll n){
    lpd(i, n - 1, 0) cerr << ((mask >> i) & 1);
}

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    OrderOfTheHats test;
    cout << test.minChanged({"YYYYYNNYYYNYNNNNYNNY", "NYNNNYYNNYNYYYNYYYYY", "NNYNNNYYNNNNNNYYYYNY", "YYNYNYYNNYYYNYNNNYYY", "NYYNNYNYNYNNNNYYYNYN", "NNNNNYYNYNNYYYYNYYYN", "YNYNYYNNNYNNNNNYNNYY", "NYYYYNYNYNNYNNYNNNNY", "YYYYNYYNNYYYNNYNNYNY", "YYYYYYNYNYNYNNNNNNYN", "NNYYYYYNNNYNNNYNNNNY", "YYNNNYNYYNYYNYYNYNYN", "NNYNYYNYYNYYNYNYNYYN", "YNYNYYNYNNNYNYNYYNYY", "NNYNNNYYYYYYYYYYYNYY", "YYYYYNYYNYYYYYNNYNNN", "NYYYYYYYYNNNNNYYNNYN", "YNNYNNNYYNYYYNYNYYYY", "YYNNYNYYYNYYNNNYYNNY", "NNYNYNYYYNYYNYNNYNNN"});
    // lp(i, 0, (1 << test.n) - 1){
    //     errmask(i, test.n);
    //     cerr << '\n';
    //     lp(j, 0, test.n - 1) cerr << j << ' ' << dp[i][j] << '\n';
    // }
}
