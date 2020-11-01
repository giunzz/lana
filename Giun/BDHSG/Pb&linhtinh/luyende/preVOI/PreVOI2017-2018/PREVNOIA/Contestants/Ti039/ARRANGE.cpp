#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
int n,a[100005],m,cnt1,cnt2;
long long res[100005],f[2005][2005];
void Enter()
{
    cin >> n;
    for (int i=1;i<=n;i++) {cin >> a[i];res[i]=res[i-1]+a[i];}
    m=res[n]/n;
    cnt2=res[n]-(res[n]/n)*n;
    cnt1=n-cnt2;
}
void Solve1()
{
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<=min(cnt1,i);j++)
        {
            f[i][j]=1e18;
            if (i-1>=j)
            {
                long long cnt11=res[i-1];
                long long cnt22=(long long)j*m+(long long)(i-1-j)*(m+1);
                f[i][j]=f[i-1][j]+abs(a[i]-cnt22+cnt11-m-1);
            }
            if (j>=1)
            {
                long long cnt11=res[i-1];
                long long cnt22=(long long)(j-1)*m+(long long)(i-j)*(m+1);
                f[i][j]=min(f[i][j],f[i-1][j-1]+abs(a[i]-cnt22+cnt11-m));
            }
        }
    }
    cout << f[n][cnt1];
}
void Solve2()
{
    int cnt=0;
    long long kq=0;
    for (int i=1;i<=n;i++)
    {
        if (n-i+1==cnt1-cnt)
        {
            a[i+1]+=(a[i]-m);
            cnt++;
            kq+=abs((a[i]-m));
            a[i]=m;
        }
        else
        {
            if (a[i]>m||cnt==cnt1)
            {
                a[i+1]+=(a[i]-m-1);
                kq+=abs((a[i]-m-1));
                a[i]=m+1;
            }
            else
            {
                a[i+1]+=(a[i]-m);
                cnt++;
                kq+=abs((a[i]-m));
                a[i]=m;
            }
        }
    }
    cout << kq;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("ARRANGE.INP","r",stdin);
    freopen("ARRANGE.OUT","w",stdout);
    Enter();
    if (n<=2000) Solve1();
    else Solve2();
}
