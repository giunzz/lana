#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
int n,m,m1;
int a[10010];
void khoitao()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("arrange.inp","r",stdin);
    freopen("arrange.out","w",stdout);
}
void sub1()
{
    m=m/n;
    bool ok;
    int kq=0;
    int l,r,h,la,ra,ta,ha;
    queue< int > p1;
    queue< int > p2;
    for (int i=1;i<=n;i++)
    {
        if (a[i]>m) p1.push(i);
        if (a[i]<m) p2.push(i);
    }
    while (p1.size()!=0 && p2.size()!=0)
        {
            l=p1.front();
            r=p2.front();
            la=a[l]-m;
            ra=m-a[r];
            ta=min(la,ra);
            ha=l-r;
            if (ha<0) ha=0-ha;
            kq=kq+ta*ha;
            if (la<ra)
            {
                a[r]=a[r]+la;
                a[l]=m;
                p1.pop();
                continue;
            }
            if (la>ra)
            {
                a[l]=a[l]-ra;
                a[r]=m;
                p2.pop();
                continue;
            }
            if (la==ra)
            {
                a[l]=m;
                a[r]=m;
                p1.pop();
                p2.pop();
            }
        }
        cout<<kq;
}
void sub2()
{
    m=m/n;
    m1=m+1;
    bool ok;
    int kq=0;
    int l,r,h,la,ra,ta,ha;
    queue< int > p1;
    queue< int > p2;
    for (int i=1;i<=n;i++)
    {
        if (a[i]>m+1) p1.push(i);
        if (a[i]<m) p2.push(i);
    }
    while (p1.size()!=0 && p2.size()!=0)
        {
            l=p1.front();
            r=p2.front();
            la=a[l]-m-1;
            ra=m-a[r];
            ta=min(la,ra);
            ha=l-r;
            if (ha<0) ha=0-ha;
            kq=kq+ta*ha;
            if (la<ra)
            {
                a[r]=a[r]+la;
                a[l]=m+1;
                p1.pop();
                continue;
            }
            if (la>ra)
            {
                a[l]=a[l]-ra;
                a[r]=m;
                p2.pop();
                continue;
            }
            if (la==ra)
            {
                a[l]=m+1;
                a[r]=m;
                p1.pop();
                p2.pop();
            }
        }
    cout<<kq;
}
void nhap()
{
    cin>>n;
    m=0;
    for (int i=1;i<=n;i++)
    {cin>>a[i];
    m=m+a[i];
    }
    if (m%n==0)
    {
        sub1();
    }
    else
    {
        sub2();
    }

}
int main()
{
    khoitao();
    nhap();
    return 0;
}
