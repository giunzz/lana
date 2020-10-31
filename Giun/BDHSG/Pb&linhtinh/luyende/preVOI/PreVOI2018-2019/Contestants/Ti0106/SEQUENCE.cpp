#include <bits/stdc++.h>
#define mn 3005
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORE(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int m,n,k,r[mn][30],q[mn][30],t1=1,t2=1,p;
int a[mn],b[mn];
void rmq()
{
    FOR(i,1,m) r[i][0]=i;
    FOR(i,1,n) q[i][0]=i;
    int t=log2(m);
    FOR(j,1,t)
    FOR(i,1,m)
    {
        if(i+(1<<j)-1>m) break;
        if(a[r[i][j-1]]<=a[r[i+(1<<(j-1))][j-1]]) r[i][j]=r[i][j-1];
        else r[i][j]=r[i+(1<<(j-1))][j-1];
    }
    t=log2(n);
    FOR(j,1,t)
    FOR(i,1,n)
    {
        if(i+(1<<j)-1>n) break;
        if(b[q[i][j-1]]<=b[q[i+(1<<(j-1))][j-1]]) q[i][j]=q[i][j-1];
        else q[i][j]=q[i+(1<<(j-1))][j-1];
    }
}
int getmin1(int i,int j)
{
    int t=log2(j-i+1);
    if (a[r[i][t]]<=a[r[j-(1<<t)+1][t]]) return r[i][t];
    return r[j-(1<<t)+1][t];
}
int getmin2(int i,int j)
{
    int t=log2(j-i+1);
    if (b[q[i][t]]<=b[q[j-(1<<t)+1][t]]) return q[i][t];
    return q[j-(1<<t)+1][t];
}
void nhap()
{
    cin>>m>>n>>k;
    FOR(i,1,m) cin>>a[i];
    FOR(i,1,n) cin>>b[i];
    rmq();
    FOR(i,1,k)
    {
        p=m-t1+1+n-t2+1-(k-i);
        if(t1<=m&&t2<=n)
        {
            if(a[getmin1(t1,min(m,t1+p-1))]<=b[getmin2(t2,min(n,t2+p-1))])
            {
                cout<<a[getmin1(t1,min(m,t1+p-1))]<<" ";
                t1=getmin1(t1,min(m,t1+p-1))+1;
            }
            else
            {
                cout<<b[getmin2(t2,min(n,t2+p-1))]<<" ";
                t2=getmin2(t2,min(n,t2+p-1))+1;
            }
        }
        else
            if(t1>m)
        {
            cout<<b[getmin2(t2,min(n,t2+p-1))]<<" ";
            t2=getmin2(t2,min(n,t2+p-1))+1;
        }
        else
            if(t2>n)
        {
            cout<<a[getmin1(t1,min(m,t1+p-1))]<<" ";
            t1=getmin1(t1,min(m,t1+p-1))+1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("SEQUENCE.inp","r",stdin);
    freopen("SEQUENCE.out","w",stdout);
    nhap();
    return 0;
}
