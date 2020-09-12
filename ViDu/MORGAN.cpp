#include<bits/stdc++.h>
using namespace std;
int n , k , a, b , f[(int) 2e7+8] = {0};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("morgan.inp","r",stdin);
    freopen("morgan.out","w",stdout);
    cin >> n >> k >> a >> b;
    for (int i = 2 ; i <= n ; i++)
    {
        f[i] = f[i-1]+a;
        if (i % k == 0 ) f[i] = min(f[i],f[i/k]+b);
    }
    cout << f[n];
}