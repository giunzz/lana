#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll m, n;
string a[3005][3005];
string f[3005][3005];
using namespace std;
int main()
{
ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n;
	for (int i = 1 ; i <= n ; i++)
	    for (int j = 1 ; j <= n ; j++) cin >> a[i][j]; 
    for (int i = 0 ; i <= n ; i++) f[0][i] = "";
    for (int j = 0  ; j <= n ; j++) f[j][0] = "";
    for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= n ; j++) 
        {
            if (i == 1 && j == 1) f[i][j] = f[i][j];
            else if (i == 1) f[i][j] = f[i][j-1];
            else if (j == 1) f[i][j] = f[i - 1][j];
            else f[i][j] = min(f[i - 1][j],f[i][j-1]);
            f[i][j] += a[i][j];
            cerr << f[i][j] << " ";
        }
        cerr << endl;
    }
    cout << f[n][n];
}