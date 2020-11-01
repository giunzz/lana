#include <bits/stdc++.h>
using namespace std;
ifstream fi("Arrange.inp");
ofstream fo("Arrange.out");
long long n,a[100005],sum,kq;
long long f[2005][2005];
void sub1()
{
    long long one=sum/n;
    for (int i=1; i<=n; ++i)
    {
        long long tmp=one-a[i];
        kq+=abs(tmp);
        a[i+1]-=tmp;
    }
    fo<<kq;
}
void sub2()
{
    long long one=sum/n,k=sum%n;
    /*for (int i=1;i<=k;++i)
        for (int j=0;j<=n;++j)
            f[i][j]=1e18;*/
    for (int i=1; i<=n; ++i)
    {
        long long tmp=one-a[i];
        kq+=abs(tmp);
        a[i+1]-=tmp;
    }
    fo<<kq-k*(k+1)/2;
}
int main()
{
    fi>>n;
    for (int i=1; i<=n; ++i)
    {
        fi>>a[i];
        sum+=a[i];
    }
    //sub1();
    if (sum%n==0) sub1();
    else sub2();
}
