#include <bits/stdc++.h>
using namespace std;
const long maxn=2e3+5;
long m,n,i,j,k;
long a[maxn],b[maxn],xo[maxn],x[maxn];
void capnhat()
{
    bool ok=0;
    for(long i=1;i<=k;i++)
    if(xo[i]>x[i]) {ok=1;break;}
    else if(xo[i]<x[i]) {ok=0;break;}
    if(ok==1) for(long i=1;i<=k;i++) xo[i]=x[i];
}
void Try1(long i,long h)
{
    for(long j=h;j<=m;j++)
    {
        x[i]=a[j];
        if(i==k) capnhat();
        else Try1(i+1,j+1);
    }
}
void Try2(long i,long h)
{
    for(long j=h;j<=n;j++)
    {
        x[i]=a[j];
        if(i==k) capnhat();
        else Try2(i+1,j+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("sequence.inp","r",stdin);
    freopen("sequence.out","w",stdout);
    cin >> m >> n >> k;
    for(i=1;i<=m;i++)
        cin >> a[i];
    for(j=1;j<=n;j++) cin >> b[i];
    for(i=1;i<=k;i++) xo[i]=1000000009;
    if(m>=k) Try1(1,1);
    if(n>=k) Try2(1,1);
    for(i=1;i<=k;i++) cout << xo[i] << " ";
}
