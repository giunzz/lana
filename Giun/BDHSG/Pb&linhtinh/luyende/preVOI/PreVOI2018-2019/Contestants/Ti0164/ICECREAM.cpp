// /*Hoàng Thái Thụy*/ //
#include <bits/stdc++.h>
using namespace std;
int N, MMAX, M50, M1, M2, res = 0;
void solve(int a, int b, int c, int z){
//    cout << a << ' ' << b << ' ' << c << ' ' << z << endl;
    if(z >= N) {
        res += 1;
        return;
    }
    if(c + 1 <= MMAX)
        if(b != 0 && a != 0)  solve(a - 1, b - 1, c + 1, z + 1);
        else if(a >= 3)       solve(a - 3, b, c + 1, z + 1);
    if(a != 0 && b + 1 <= MMAX)solve(a - 1, b + 1, c, z + 1);
    if(a + 1 <= MMAX)          solve(a + 1, b, c, z + 1);
//    cout << 1 << endl;
    return;
}
int main(){
    freopen("ICECREAM.inp","r",stdin);
    freopen("ICECREAM.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> MMAX >> M50 >> M1 >> M2;
    solve(M50, M1, M2, 0);
    cout << res << '\n';
}
