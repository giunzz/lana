#include<bits/stdc++.h>
using namespace std;
int a[(int) 1e5+7], f[(int) 1e5+7]={0},n,k;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    // f[1]= 0 , f[2] = abs(a[2]-a[1]);
    // for (int i = 3 ; i <= n ; i++)
    // {
    //     f[i] = min ( (f[i-1]+abs(a[i]-a[i-1])) , f[i-2]+ abs(a[i]-a[i-2]) ); 
    // }
    f[1]=0;
    for (int i = 2 ; i <= n ; i++)
    {
        f[i] = INT_MAX/2;
    }
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= k ; j++)
        {
            f[i+j] = min(f[i]+abs(a[i]-a[i+j]) , f[i+j]);
        }
    }
    cout << f[n];
}