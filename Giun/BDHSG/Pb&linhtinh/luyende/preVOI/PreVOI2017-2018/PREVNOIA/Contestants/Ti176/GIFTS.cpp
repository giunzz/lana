#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Nmax=1e6+7;
const int oo=1e13+7;
int n,k,a[Nmax],sum[Nmax];
//int chat(int x,int y)
//{
//    int l=x,r=y;
//    {
//        while (r-l>1)
//        {
//            int mid=(r+l)/2;
//            if (sum[])
//        }
//    }
//}
bool slv(int x)
{
    for (int i=1;i<=x-2;i++)
    {
        if (sum[i]>sum[x]) return false;
    }
    for (int i=x+2;i<=n-k+1;i++)
    {
        if (sum[i]>sum[x]) return false;
    }
    return true;
}
main()
{
    freopen("GIFTS.inp","r",stdin);
    freopen("GIFTS.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n-k+1;i++)
    for (int j=i;j<=i+k-1;j++)
    sum[i]+=a[j];
    //for (int i=1;i<=n-k+1;i++) cout<<sum[i]<<" ";
    int Min=oo;
    for (int i=1;i<=n-k+1;i++)
    {
        if (slv(i)==true&&sum[i]<Min)
            Min=sum[i];
    }
    cout<<Min;
    return 0;
}
