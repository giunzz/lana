#include <bits/stdc++.h>

using namespace std;
#define fname "ICECREAM"
#define For(i, a, b) for(int i = a; i <= b; i++)
#define FOr(i, a, b) for(int i = a; i < b; i++)
#define FOR(i, a, b) for(int i = a; i >= b; i--)
typedef int64_t ll;
const ll base = 1e9+9;
int n, nmax, m1, m2, m50;
ll res;
void Try(const int x){
    if (x > n){
        res ++;
        return;
    }
    if (m50 < nmax){
        m50++;
        Try(x+1);
        m50--;
    }
    if (m50 && m1 <= nmax){
        m1++;
        m50--;
        Try(x+1);
        m1--;
        m50++;
    }
    if (m1 && m50 && m2 <= nmax){
        m2++;
        m1--; m50--;
        Try(x+1);
        m2--;
        m1++; m50++;
        return;
    }
    if (m50 > 2 && m2 <= nmax){
        m2++;
        m50 -= 3;
        Try(x+1);
        m2--;
        m50 += 3;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(fname".inp", "r")){
        freopen (fname".inp", "r", stdin);
        freopen (fname".out", "w", stdout);
    }
    cin >> n >> nmax >> m50 >> m1 >> m2;
    Try(1);
    cout << res;
    return 0;
}
