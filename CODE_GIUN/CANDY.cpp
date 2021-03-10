#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n , sum = 0 ;
vector<ll> a;
vector<vector<ll>> f;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("candy.inp","r",stdin);
    freopen("candy.out","w",stdout);
    cin >> n ; 
    a.resize(n + 3);
    for (int i = 1 ; i <= n ; i++) cin >> a[i] , sum += a[i];
    f.assign(n + 3, vector<ll>(sum / 2 + 3, 0));
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= sum/2 ; j++)
        {
            if (a[i] > j) f[i][j] = f[i-1][j];
            else f[i][j] = max(f[i-1][j],f[i-1][j-a[i]]+a[i]);
        }
    }
    cout << abs ((sum-f[n][sum/2]) - f[n][sum/2]);
}