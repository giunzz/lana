#include <bits/stdc++.h>

using namespace std;
const long N=6003;
long a[N],b[N],c[N];
long n,m,k;
long A[N],B[N];
long ans[N];
void nhap()
{
    cin>>n>>m>>k;
    for(long i=1;i<=n;++i)
        cin>>a[i];
    for(long j=1;j<=m;++j)
        cin>>b[j];
}
void xuly(long x,long y)
{
    long n1=0;
    x=n-x;
    for(long i=1;i<=n;++i)
    {
        while(x>0&&n1>0&&a[i]<A[n1])
        {
            n1--;
            x--;
        }
        A[++n1]=a[i];
    }
    long m1=0;
    y=m-y;
    for(long i=1;i<=m;++i)
    {
        while(y>0&&m1>0&&b[i]<B[m1])
        {
            m1--;
            y--;
        }
        B[++m1]=b[i];
    }
    long pos1=1,pos2=1;
    for(long i=1;i<=k;++i)
    {
        if(pos1>n1)
        {
            c[i]=B[pos2];
            pos2++;
            continue;
        }
        if(pos2>m1)
        {
            c[i]=A[pos1];
            pos1++;
            continue;
        }
        if(A[pos1]<=B[pos2])
        {
            c[i]=A[pos1];
            pos1++;
            continue;
        }
        if(B[pos2]<A[pos1])
        {
            c[i]=B[pos2];
            pos2++;
            continue;
        }
    }
    bool ok=true;
    for(long i=1;i<=k;++i)
    {
        if(ans[i]<c[i])
        {
            ok=false;
            break;
        }
        if(ans[i]>c[i])
        {
            ok=true ;
            break;
        }
    }
    if(ok)
    for(long i=1;i<=k;++i)
    {
        ans[i]=c[i];
    }
}
void lam()
{
    for(long i=1;i<=k;++i)ans[i]=1e9;
    for(long i=1;i<=n;++i)
    {
        if(i>k||k-i>m)continue;
        xuly(i,k-i);
    }
    for(long i=1;i<=k;++i)
        cout<<ans[i]<<" ";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("sequence.inp","r",stdin);
    freopen("sequence.out","w",stdout);
    nhap();
    lam();
    return 0;
}
