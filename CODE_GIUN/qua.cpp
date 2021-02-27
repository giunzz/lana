#include<bits/stdc++.h>
using namespace std; 
#define ll long long

int f[(int) 1e6+7] ={0} , n , a[(int) 1e6+7];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++ ) cin >> a[i];
    if(a[1] != a[2] && a[1] != a[3] && f[3] < a[1]) f[3] = a[1];
    if(a[2] != a[1] && a[2] != a[3] && f[3] < a[2]) f[3] = a[2];
    if(a[1] != a[3] && a[2] != a[3] && f[3] < a[3]) f[3] = a[3];
    for (int i = 4 ; i <= n ; i++)
    {
        f[i] = max(f[i-1],max(f[i-3],f[i-2]) );
        if (a[i] != a[i-1] && a[i] != a[i-2] )  f[i] = max(f[i],f[i-3] + a[i]);
        cerr << f[i] << " ";
    }
    cout << f[n];

}