#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll  a[(int) 1e6+7], n , f[(int) 1e6 + 7] ={0};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ; 
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    f[1] = a[1] , f[2] = a[1] + a[2] , f[3] = max(a[1]+a[3], a[2]+a[3]);
    for (int i = 4 ; i <= n ; i++)
    {
        //f[i] = max(f[i-1]+f[i-2], max((f[i-2]+f[i-3]), f[i-1]+f[i-3]) ) + a[i];
        f[i] = max (f[i-2] + a[i-2] , max(f[i-1], f[i-3] + a[i-1] + a[i])) ;
    }
    for (int i = 1 ; i <= n ; i++) cerr << f[i] << " ";

    cout << f[n];
}
