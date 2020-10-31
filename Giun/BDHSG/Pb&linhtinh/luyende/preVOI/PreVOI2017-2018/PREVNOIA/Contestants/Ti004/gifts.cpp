#include <bits/stdc++.h>
using namespace std;
int n,k,cs;
long long a[1000001],b[1000001],d[1000001],f[2][1000002];
long long kq,tong;
void tao_test()
{
    freopen("gifts.inp","w",stdout);
    n=20000;k=2000;
    cout<<n<<" "<<k<<'\n';
    for(int i=1;i<=n;i++)
        cout<<rand()%100<<" ";
}
void nhap()
{
    freopen("gifts.inp","r",stdin);
    freopen("gifts.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=b[i-1]+a[i];
        if(i>=k)
            d[i]=b[i]-b[i-k];
    }
}
void xu_li2()
{
    kq=LLONG_MAX;
    for(int i=k;i<=n;i++)
    {
        tong=0;
        if(i-k+1>k)
            for(int j=k;j<i-k+1;j++)
                if(d[j]>tong)
                    tong=d[j];
        if(i+k<=n)
            for(int j=i+k;j<=n;j++)
                if(d[j]>tong)
                    tong=d[j];
        if(tong<kq)
            kq=tong;
    }
    cout<<kq;
}
void xu_li3()
{
    kq=LLONG_MAX;
    for(int i=k;i<=n;i++)
    {
        f[0][i]=max(f[0][i-1],d[i]);
    }
    for(int i=n;i>=k;i--)
    {
        f[1][i]=max(f[1][i+1],d[i]);
    }
    for(int i=k;i<=n;i++)
    {
        tong=0;
        if(i-k>=k)
        {
            tong=max(tong,f[0][i-k]);
        }
        if(i+k<=n)
            tong=max(tong,f[1][i+k]);
        kq=min(kq,tong);
    }
    cout<<kq;
}
int main()
{
    //tao_test();
    nhap();
    xu_li3();
}
