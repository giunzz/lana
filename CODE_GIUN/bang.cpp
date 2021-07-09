#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll m, n, a[3005][3005], f[3005][3005] ={{0}} ,ma = 0;
using namespace std;
int main()
{
ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("bang.inp","r",stdin);
    freopen("bang.out","w",stdout);
    cin >> m >> n ;
	for (int i = 1 ; i <= m ; i++)
	    for (int j = 1 ; j <= n ; j++) cin >> a[i][j]; // m hang n cot
    for (int i = 1 ; i <= m ; i++) 
    {
        ma = max(ma , a[i][1]);
        f[i][1] = a[i][1];
    }
    for (int j = 2 ; j <= n ; j++)
	{
		for (int i = 1 ; i <= m ; i++) 
        {
            f[i][j] = max(max (f[i+1][j-1],f[i][j-1]) ,f[i-1][j-1]) + a[i][j];
          //  cerr << f[i][j] << " ";
        }
        //cerr << endl;
    }
    for (int i = 1 ; i <= m ; i++) ma = max (ma,f[i][n]);
    cout << ma;
}