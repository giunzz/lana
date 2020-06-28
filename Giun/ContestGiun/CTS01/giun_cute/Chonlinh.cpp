#include <bits/stdc++.h>
using namespace std;
int n , t , k[1000008];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin)
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> k[i];
    f[1] = 0;
    for (int i <= 2 ; i <= 500000000 ; i++)
    {
        if ( (int) log2(i) == 2) f[i] = log2(i);
        else f[i] = max ( (f[i-1] + f[i-(i-1)]) , f[i/2+1] + f[]
    }
}

