#include <bits/stdc++.h>
#define nmax 2*10000007

using namespace std;

long long n,k,a[nmax],f[nmax],bd[nmax],kt[nmax];

bool ktra(long long h)
{
    long long dem=0;
    for (long i=1; i<=n-k+1; i++)
      if (f[i+k-1]-f[i-1]>h)
      {
          ++dem;
          bd[dem]=i;
          kt[dem]=i+k-1;
      }
    if (dem==0 || dem==1) return false;
    for (long i=1; i<=dem; i++)
    {
        long long vt1=upper_bound(bd+1,bd+dem+1,kt[i])-bd;
        long long vt2=lower_bound(kt+1,kt+dem+1,bd[i])-kt-1;
        if (vt1==dem+1 && vt2==0) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("gifts.inp","r",stdin);
    freopen("gifts.out","w",stdout);
    //cin >> n >> k;
    scanf("%lld%lld",&n,&k);
    f[0]=0;
    for (long i=1; i<=n; i++)
    {
        //cin >> a[i];
        scanf("%lld",&a[i]);
        f[i]=f[i-1]+a[i];
    }
    long long l=0,r=-1,ans=0;
    for (long i=1; i<=n-k+1; i++)
       r=max(r,f[i+k-1]-f[i-1]);
    r+=10;
    while (l<=r)
    {
        long long mid=(l+r)/2;
        if (ktra(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    //cout << ans+1;
    ans++;
    printf("%lld",ans);

    /*sort(a+1,a+n+1);
    for (long i=1; i<=n; i++) cout << a[i] << " ";cout <<endl;
    cout << lower_bound(a+1,a+n+1,1)-a-1;*/
}
