#include <bits/stdc++.h>
#define PII pair<int,int>
#define F first
#define S second
#define LL long long
using namespace std;
struct data
{
    int x,y,z,sum;
}d1[101][101][101][101];
const LL base=1e9+9;
int n,mmax,m50,m1,m2,f[101][101][101][101],res=0;
int main()
{
    freopen("icecream.inp","r",stdin);
    freopen("icecream.out","w",stdout);
    ios_base::sync_with_stdio();
    cin.tie(0);cout.tie(0);
    cin>>n>>mmax;
    cin>>m50>>m1>>m2;
    /*f.resize(n+1);d.resize(n+1);
    for (int i=1;i<=n;i++)
    {
        f[i].resize(n+1);
        d[i].resize(n+1);
        for (int j=1;j<=n;j++) f[i][j].resize(n+1),d[i][j].resize(n+1);
    }*/
    f[0][0][0][0]=1;
    d1[0][0][0][0]={m50,m1,m2,m50+m1+m2};
    for (int i=1;i<=n;i++)
    for (int j=0;j<=i;j++)
    for (int k=0;k<=i-j;k++)
    {
        int h=i-j-k;
        for (int d=0;d<=h;d++)
        {
            if (d1[i-1][j-1][k][d].sum+1<=mmax)
            {
                d1[i][j][k][d]=d1[i-1][j-1][k][d];
                d1[i][j][k][d].x++;
                d1[i][j][k][d].sum++;
                f[i][j][k][d]=(f[i][j][k][d]+f[i-1][j-1][k][d])%base;
            }
            if (d1[i-1][j][k-1][d].x>0&&d1[i-1][j][k-1][d].sum+1<=mmax)
            {
                d1[i][j][k][d]=d1[i-1][j][k-1][d];
                d1[i][j][k][d].x--;
                d1[i][j][k][d].y++;
                f[i][j][k][d]=(f[i][j][k][d]+f[i-1][j][k-1][d])%base;
            }
            if (d1[i-1][j][k][d].x>2&&d1[i-1][j][k][d].y==0&&d1[i-1][j][k][d].sum+1<=mmax)
            {
                d1[i][j][k][d]=d1[i-1][j][k][d];
                d1[i][j][k][d].x-=3;
                d1[i][j][k][d].z++;
                d1[i][j][k][d].sum-=2;
                f[i][j][k][d]=(f[i][j][k][d]+f[i-1][j][k][d])%base;
            }
            if (d>0&&d1[i-1][j][k][d-1].x>0&&d1[i-1][j][k][d-1].y>0&&d1[i-1][j][k][d-1].sum+1<=mmax)
            {
                d1[i][j][k][d]=d1[i-1][j][k][d-1];
                d1[i][j][k][d].x--;
                d1[i][j][k][d].y--;
                d1[i][j][k][d].z++;
                d1[i][j][k][d].sum--;
                f[i][j][k][d]=(f[i][j][k][d]+f[i-1][j][k][d-1])%base;
            }
            if (i==n) res=(res+f[i][j][k][d])%base;
        }

    }
    cout<<res;
    return 0;
}
