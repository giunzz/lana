#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll m, n, a[1005][1005], f[1005][1005] ={{0}} ,ans = 0;

int main()
{
ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> m ;
	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= m ; j++) cin >> a[i][j];
	}
    for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= m ; j++) 
        {
            f[i][j] = max(f[i-1][j],f[i][j-1]) + a[i][j];
            cerr << f[i][j] << " ";
        }
        cerr << endl;
    }
    cout << f[n][m];
}