#include <bits/stdc++.h>
using namespace std;
int n,m,k;
long long a[100001],b[100001],c[100001];
long long kq,tong;
void nhap()
{
    freopen("arrange.inp","r",stdin);
    freopen("arrange.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        tong+=a[i];
    }
    k=tong%n;
    m=tong/n;
    if(k>n/2)
        m++;
}
void xu_li()
{
    for(int i=1;i<=n;i++)
    {
        if(a[i]>m)
            b[i]=a[i]-m;
        if(a[i]<m-1)
            b[i]=a[i]-m;
    }
    tong=0;
    for(int i=1;i<=n;i++)
        kq=max(kq,b[i]);
    for(int i=1;i<=n;i++)
    {
        if(b[i]<0)
        {
            if(b[i+1]>0)
            {
                if(abs(b[i+1])>abs(b[i]))
                {
                    b[i+1]=b[i+1]-abs(b[i]);
                    b[i]=0;
                }
                else
                {
                    b[i]=b[i]+b[i+1];
                    b[i+1]=0;
                }
            }
            if(b[i-1]>0)
            {
                if(abs(b[i-1])>abs(b[i]))
                {
                    b[i-1]=b[i-1]-abs(b[i]);
                    b[i]=0;
                }
                else
                {
                    b[i]=b[i]+b[i-1];
                    b[i-1]=0;
                }
            }

        }
    }
    for(int i=1;i<=n;i++)
    {
        kq+=abs(b[i]);
    }
    cout<<kq;
}
int main()
{
    nhap();
    xu_li();
}
