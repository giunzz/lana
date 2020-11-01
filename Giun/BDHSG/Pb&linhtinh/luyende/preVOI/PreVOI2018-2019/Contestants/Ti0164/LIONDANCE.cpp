#include <bits/stdc++.h>
#define nmax 4003
using namespace std;
typedef vector <int> vtc;

int m , L[nmax], R[nmax], del;
vtc solve(int a, int b, vtc z){
    if(a > m || b > m) return z;
    if(L[a] == R[b] && L[a] - z[z.size() - 1] <= del){
        return solve(a + 1, b + 1, z);
    }
    else{
        return solve(a, b + 1, z);
        return solve(a + 1, b, z);
    }
}
int main(){
    freopen("LIONDANCE.inp","r",stdin);
    freopen("LIONDANCE.out","w",stdout);
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin >> m >> del;
    vtc a;
    for( int i = 1; i <= m; i++) cin >> L[i];
    for( int i = 1; i <= m; i++) cin >> R[i];
    cout << solve(1, 1, a).size() << '\n';
}
