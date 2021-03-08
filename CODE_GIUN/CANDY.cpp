#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll  a[(int) 1e6+7], n , f[(int) 1e3 + 7][(int) 1e3+7] ={{0}} , sum = 0 ;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("giun.inp","r",stdin);
    //freopen("giun.out","w",stdout);
    cin >> n ; 
    for (int i = 1 ; i <= n ; i++) cin >> a[i] , sum += a[i];
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= sum/2 ; j++)
        {
            if (a[i] > j) f[i][j] = f[i-1][j];
            else f[i][j] = max(f[i-1][j],f[i-1][j-a[i]]+a[i]);
        }
    }
    int i = n , j = sum/2 ;
    vector < int > ans;
    while (i != 0 && j != 0 )
    {
        if (a[i] <= j && f[i][j] == f[i-1][j-a[i]] + a[i])  
        {
            ans.push_back(i);
            j = j-a[i] ;
            i--;
        }
        else i--;
    }
    int d[(int) 1e5+7] ={0};
    cout <<  (sum -f[n][sum/2]) - f[n][sum/2] << endl;
    for (int i = ans.size()-1 ; i >= 0 ; i--) cout << ans[i] << " " , d[ans[i]] = 1;
    cout << endl;
    for (int i = 1 ; i <= n ; i++) 
        if (d[i] == 0) cout << i << " ";
}
// #include <bits/stdc++.h>
// #define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) 
// using namespace std;
// int n,t=0,f[10001],d[10001];
// int main()
// {
//     freopen("CANDY.INP","r",stdin);
// 	freopen("CANDY.OUT","w",stdout);
//     giuncute;
// 	cin>>n;
// 	int a[n+1];
// 	for (int i=1;i<=n;i++) cin>>a[i] , t += a[i];	
// 	t=t/2;
// 	for (int i=1;i<=t;i++)
// 	{
// 		f[i]=INT_MAX;
// 	    for (int j=1;j<=n;j++)
// 	        if (i>=a[j] && j>f[i-a[j]]) 
// 	        {
// 	      	    f[i]=j;
// 	      	    break;
// 		    }
// 	}
// int sum1 = 0 , sum2 = 0 ;
// 	while (f[t] > n) t--;
// 	while (t > 0)
// 	{
// 		d[f[t]]=1;
// 		t=t-a[f[t]];
// 	}
// 	for (int i=1;i<=n;i++)
// 	    if (d[i]==1)  sum1 += a[i];
// 	for (int i=1;i<=n;i++)
// 		if (d[i]!=1)  sum2 += a[i];
//     cout << abs(sum1-sum2);
// }
