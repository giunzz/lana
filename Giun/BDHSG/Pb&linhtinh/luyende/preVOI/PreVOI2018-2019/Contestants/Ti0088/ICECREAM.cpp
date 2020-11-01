#include <bits/stdc++.h>
#define maxn 100
using namespace std;
int f[5],a[maxn],kq=0,c[5],n,mmax,k[5];
void check()
{
    for (int i=1;i<=3;i++) f[i]=k[i];
    for (int i=1;i<=n;i++)
    {
        if (a[i]==50)
        {
            f[1]++;
            if (f[1]>mmax) return;
        }
        if (a[i]==2)
        {
            if (f[1]<3&&f[2]==0||f[1]==0&&f[2]>=1) return;
            f[3]++;
            if (f[2]>=1&&f[1]>=1) {f[2]--;f[1]--;}
            else f[1]-=3;
            if (f[3]>mmax) return;
        }
        if (a[i]==1)
        {
            if (f[1]==0) return;
            f[2]++;f[1]--;
            if (f[2]>mmax) return;
        }
    }
    kq++;
}
void hv(int x)
{
    for (int i=1;i<=3;i++)
    {
        a[x]=c[i];
        if (x==n) check();
            else hv(x+1);
    }
}
void nhap()
{
    freopen("ICECREAM.inp","r",stdin);
    freopen("ICECREAM.out","w",stdout);
    cin>>n>>mmax;
    for (int i=1;i<=3;i++)
    {
        cin>>k[i];
    }
    c[1]=50;
    c[2]=1;
    c[3]=2;
}
void xuly()
{
    hv(1);
    cout<<kq;
}
int main()
{
    nhap();
    xuly();
    return 0;
}
