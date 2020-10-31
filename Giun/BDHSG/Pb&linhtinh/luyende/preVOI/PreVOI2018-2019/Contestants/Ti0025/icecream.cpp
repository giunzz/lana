#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define FORD(i,j,k) for(int i=j;i>=k;i--)
#define maxn 55
#define pll pair<long long ,long long  >
#define mp make_pair
#define F first
#define S second
#define int long long
using namespace std;
int n, nmax;
int res=0;
int m1,m2,m3;
int dp[50][15][15][15];
int f1[50][15][15][15];
int f2[50][15][15][15];
int f3[50][15][15][15];
void sub1()
{
    dp[0][m1][m2][m3]=1;
    FOR(i,1,n)
    {
        FOR(j,0,10)
        FOR(q,0,10)
        FOR(k,0,10)
        {
        FOR(j1,0,10)
        FOR(q1,0,10)
        FOR(k1,0,10)
        {
           if(j-1==j1&&q==q1&&k==k1) f1[i][j][q][k]+=dp[i-1][j1][q1][k1];
           if(j1-1==j&&q1+1==q&&k1==k) f2[i][j][q][k]+=dp[i-1][j1][q1][k1];
           if(j==j1-3&&q==q1&&k==k1+1) f3[i][j][q][k]+=dp[i-1][j1][q1][k1];
           if(j==j1-1&&q==q1-1&&k==k1+1) f3[i][j][q][k]+=dp[i-1][j1][q1][k1];
//           dp[i][j][q][k]=x+y+z;
        }
         dp[i][j][q][k]=f1[i][j][q][k]+f2[i][j][q][k]+f3[i][j][q][k];
         if(i==n) res+=dp[i][j][q][k];
        }
    }
    cout<<res;
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("icecream.inp","r",stdin);
    freopen("icecream.out","w",stdout);
    cin>>n>>nmax;
    cin>>m1>>m2>>m3;
    sub1();

}
