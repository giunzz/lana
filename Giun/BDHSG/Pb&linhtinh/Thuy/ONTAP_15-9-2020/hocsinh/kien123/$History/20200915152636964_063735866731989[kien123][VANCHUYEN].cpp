#include<iostream>
#include<stdio.h>


using namespace std;
long long a[300005],b[300005],sum=0,c[300005],n,k,f[30005][3005];
int main()
{
    freopen("VANCHUYEN.inp","r",stdin)
    freopen("VANCHUYEN.out","w",stdout)
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        sum+=c[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(a[i]<j)
            {
                f[i][j]=max(f[i-1][j-a[i]]+b[i],f[i-1][j]);
            }
            else f[i][j]=f[i-1][j];
        }
    }
    cout<<f[n][sum];
    return 0;
}
