#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll m, n, a[1005][1005], b[1005][1005]= {{0}} ,ans = 0;

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
	for (int i = 1 ; i <= m ; i++) b[i][1] = a[i][1];
    for (int j = 2 ; j <= n ; j++)
	{
		for (int i = 1 ; i <= m ; i++) 
        {
            b[i][j] = max(max(b[i-1][j-1], b[i][j-1]),b[i+1][j-1]) + a[i][j];
            ans = max(ans,b[i][j]);
        //    cerr << b[i][j] << " ";
        }
      //  cerr << endl;
	}
    /*cerr << endl;
	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= m ; j++)
		{ 
			cerr << b[i][j] << " ";
		}
		cerr << endl;
	}*/
    cout << ans;
	

}