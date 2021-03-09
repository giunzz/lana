// #include<bits/stdc++.h>
// #define ll long long
// #define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
// #pragma GCC optimize("Ofast")
// ll n , w, a[(int) (1e4+7) ], b[(int) (1e4+7)], l[(int)(1e4+7)][(int) (1e4+7)] ={{0}};

// using namespace std;
// int main()
// {
//     giuncute;
//     freopen("balo2.inp","r",stdin);
//     freopen("balo2.out","w",stdout);
//     cin >> n >> w;
//     for (ll i = 1 ; i <= n ; i++) cin >> a[i]  >> b[i];
//     for (ll i = 1 ; i <= w ; i++)
//         if (i > a[1]) l[1][i] = b[1];
//         else l[1][i] = 0;
//     for (ll i = 1 ; i <= n ; i++)
//     {
//         for (ll j = 1 ; j <= w ; j++)
//         {
//             if (a[i] > j) l[i][j] = l[i-1][j];
//             else l[i][j] = max (l[i - 1][j] , l[i - 1][j - a[i]] + b[i]);
//         }
//     }   
//     ll i = n , j = w , ans = 0;
//     while (i >= 1 && j >=1  )
//     {
//         if (a[i] <= j && l[i][j] == l[i-1][j-a[i]] + b[i])  
//         {
//             ans += a[i];
//             j = j-a[i] ;
//             i--;
//         }
//         else i--;
//     }
//     cout << ans << " " << l[n][w] ;
// }
#include<iostream>
using namespace std;
int n,m,w[1005],v[1005];long long dp[1005][100005];
long long solve(){
    for(int i=0;i<=n;i++)dp[i][0]=0;
    for(int j=0;j<=m;j++)dp[0][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(w[i]>j) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
        }
    }
    //for(int i=m-1;i>=1;i-=1)if(dp[n][i]==dp[n][m])ans=i;
return dp[n][m];
}
int main(){
    freopen("BALO2.inp","r",stdin);
    freopen("BALO2.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>w[i]>>v[i];
    //cout<<ans()<<" "<<solve();
    solve();int kq=m;
    for(int i=m-1;i>=1;i-=1){
        if(dp[n][i]==dp[n][m])kq=i;
        else break;
    }
    cout<<kq<<" "<<solve();
}