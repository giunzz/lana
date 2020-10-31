// /*Hoàng Thái Thụy*/ //
#include <bits/stdc++.h>
#define nmax 100005
#define U first
#define V second
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vct;
typedef unsigned long long ull;
int a, b, n ,k;
ull ha;
ull mu(ull u, int z){
    return (z != 0) ? mu(u * (ull)2, z - 1) : u;
}
void backtrack(int z,ull res){
    if(z >= n){
        if(res % ha == k){
            cout << res <<'\n';
            exit(0);
        }
        return;
    }
    backtrack(z + 1,res * 10 + (ull)a);
    backtrack(z + 1,res * 10 + (ull)b);
}
int main(){
    freopen("MODULO.inp","r",stdin);
    freopen("MODULO.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> n >> k;
    ha = mu(1, n);
    backtrack(0, 0);
    cout << -1 << '\n';
}
