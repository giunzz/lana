#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e3 + 7;
int m , n , k , a[MAXN] , res = 0;
main(){
    freopen("teaworld.inp","r",stdin);
    freopen("teaworld.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> k;
    int cau = m / n + (m % n != 0);
    cau /= 2;
    if (cau == 0) cau = 1;
    int slg = k / cau;
    for(int i = 1 ; i <= m ; i++){
        int x , y , z , t;
        cin >> x >> y >> z >> t;
    }
    for(int i = 1 ; i <= n ; i++)
        {
            int x , y , z;
            cin >> x >> y >> z >> a[i];
        }
    sort(a + 1 , a + n + 1 , greater<int>());
    for(int i = 1 ; i <= slg ; i++)
        res += a[i];
    cout << res;
    return 0;
}
