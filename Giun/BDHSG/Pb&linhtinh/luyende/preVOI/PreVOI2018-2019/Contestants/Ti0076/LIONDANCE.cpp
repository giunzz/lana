#include <bits/stdc++.h>

using namespace std;
int ma,n,n1,m,l[4005],r[4005],x[25],a[25],kq[25];
int kt()
{
    int i=0,t=0;
    for (int j=1;j<=n1;++j)
    {
        ++i;
        while (i<n && l[a[j]]!=r[i]) ++i;
        if (i>n) break;
        if (r[i]==l[a[j]]) ++t;
    }
    if (t==n1) return 1;
    return 2;
}
void Try(int i)
{
    if (i>n)
    {
        n1=0;
        for (int j=1;j<=n;++j)
            if (x[j]==1) a[++n1]=j;
        if (n1>ma)
            if (kt()==1)
        {
            ma=n1;
            for (int j=1;j<=n1;++j) kq[j]=a[j];
        }
        if (n1==ma)
            if (kt()==1)
        {
            int ok=1;
            for (int j=1;j<=n1;++j)
            {
                if (l[kq[j]]<l[a[j]]) {ok=1; break;}
                if (l[kq[j]]>l[a[j]]) {ok=2; break;}
            }
            if (ok==1)
                for (int j=1;j<=n1;++j) kq[j]=a[j];
        }
    }
    else for (int j=0;j<2;++j)
    {
        x[i]=j;
        Try(i+1);
    }
}
int main()
{
    freopen("LIONDANCE.inp","r",stdin);
    freopen("LIONDANCE.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i) scanf("%d",&l[i]);
    for (int i=1;i<=n;++i) scanf("%d",&r[i]);
    if (n<=20)
    {
        Try(1);
        for (int i=1;i<=ma;++i) printf("%d ",l[kq[i]]);
    }

}
