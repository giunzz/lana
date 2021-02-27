#include <bits/stdc++.h>
#define ll long long
#define cll const ll
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
int n , k , f[(int)2e5+7] ,MOD = 2111992 , ans = 1;

int main()
{
    giuncute;
    //freopen("giun.inp","r",stdin);
    //freopen("giun.out","w",stdout);
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++) f[i] = 1;
    for (int j = 1 ; j <= n ; j++)
    {
        (f[j] += f[j - 1]) %= MOD;
        if (j-k-1 <= 0 ) continue;
        (f[j] += f[j-k-1]) %= MOD;
    }
    cout << (f[n] + 1) % MOD;
}