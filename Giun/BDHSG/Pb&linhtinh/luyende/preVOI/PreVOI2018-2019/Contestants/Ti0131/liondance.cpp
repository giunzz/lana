#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
typedef pair <long long ,long long > p1;
long long n,m,h;
long long a[4005];
long long b[4005];
long long dp[4005][4005];
p1 cha[4005][4005];
p1 tam;
long long kq;
p1 gt[4005];
void dauvao()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("liondance.inp","r",stdin);
    freopen("liondance.out","w",stdout);
}
void nhap()
{
    cin>>n>>m;
    for (long long i=n;i>=1;i--)
    {
        cin>>a[i];
    }
    for (long long i=n;i>=1;i--)
    {
        cin>>b[i];
    }
    for (long long i=1;i<=n;i++)
    for (long long j=1;j<=n;j++)
    {
        if (a[i]!=b[j]) continue;
        dp[i][j]=1;
        cha[i][j]=mp(0,0);
        for (long long ii=1;ii<i;ii++)
        for (long long jj=1;jj<j;jj++)
        {
            if (dp[ii][jj]==0) continue;
            if (llabs(a[i]-a[ii])<=m)
            {
                if (dp[ii][jj]+1>dp[i][j])
                {
                    dp[i][j]=dp[ii][jj]+1;
                    cha[i][j]=mp(ii,jj);
                }
                else
                {
                    if (dp[ii][jj]+1==dp[i][j] && a[ii]>a[cha[i][j].fi])
                {
                    cha[i][j]=mp(ii,jj);
                }
                }

            }
        }
        if (dp[i][j]>kq)
        {
            kq=dp[i][j];
            tam=mp(i,j);
        }
        else
        {
            if (dp[i][j]==kq && a[tam.fi]<a[i])
            {
                tam=mp(i,j);
            }
        }
    }
    cout<<kq<<"\n";
    while (1)
    {
        if (tam.fi==0 && tam.se==0) break;
        h++;
        gt[h]=tam;
        tam=cha[tam.fi][tam.se];
    }
    for (long long i=1;i<=h;i++) cout<<a[gt[i].fi]<<" ";
}
int main()
{
    dauvao();
    nhap();
    return 0;
}
//cacccccccccccccccccccccccccccccccc
