#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;
const ll maxn = 3e3 + 3;
ll n, ans = 0, x[maxn] , y[maxn];

int main()
{
    giuncute;
    freopen("BADIEM.inp","r",stdin);
    freopen("BADIEM.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> x[i] >> y[i];
    for (int i = 1;  i < n - 1 ;i++)
    {
        for (int j = i+1 ; j < n ; j++)
        {
            for (int z = j+1 ; z <= n ; z++)
            { 
                //cerr << x[i] << " " << y[i] << " " << x[j] << " " << y[j] << " " << x[z] << " " << y[z] << endl;
                if ((x[j]-x[i])*(y[z]-y[i]) == (x[z]-x[i])*(y[j]-y[i])) ans++;
            }
        }
    }
    cout << ans;
}