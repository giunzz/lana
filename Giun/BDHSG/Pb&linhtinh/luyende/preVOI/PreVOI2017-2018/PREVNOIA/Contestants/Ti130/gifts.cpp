#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef pair<long long ,long long > p1;
long long n,k,kq;
long long l,r,h;
long long t[1000010];
long long a[1000010];
long long b[1000010];
void khoitao()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("gifts.inp","r",stdin);
    freopen("gifts.out","w",stdout);
}
void nhap()
{
    cin>>n>>k;
    t[0]=0;
    a[0]=0;
    h=0;
    for (long long i=1;i<=n;i++)
    {
        cin>>t[i];
        h=h+t[i];
        a[i]=a[i-1];
        if (i>=k)
        {
            h=h-t[i-k];
            a[i]=max(a[i],h);
        }
    }
    t[n+1]=0;
    b[n+1]=0;
    h=0;
    for (long long i=n;i>=1;i--)
    {
        h=h+t[i];
        b[i]=b[i+1];
        if (n-i+1>=k)
        {
            h=h-t[i+k];
            b[i]=max(b[i],h);
        }
    }
    kq=100000000000000;
    for (long long i=1;i<=n-k+1;i++)
    {
        kq=min(kq,max(a[i-1],b[i+k]));
    }
    cout<<kq;
}
int main()
{
    khoitao();
    nhap();
    return 0;
}
