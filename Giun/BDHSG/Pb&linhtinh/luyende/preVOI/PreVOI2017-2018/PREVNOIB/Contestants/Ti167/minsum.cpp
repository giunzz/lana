#include<bits/stdc++.h>
using namespace std;
int t;
int A,B;
const int nmax=1e6+1;
int d[nmax],a[nmax],era[nmax],top=0;
int cnt,g[nmax];
int x[nmax],b[2],r[2];

void sangnt()
{
    d[1]=1;
    top=0;
    for (int i=2;i*i<nmax;i++) if (d[i]==0)
    {
        int j=i*i;
        a[++top]=i;
        era[i]=top;
        while (j<nmax)
        {
            d[j]=1;
            era[j]=top;
            j+=i;
        }
    }
}
void pt(int x)
{
    while (x>1)
    {
        int gt=a[era[x]];
        int dem=0;
        while (x%gt==0)
        {
            dem++;
            x/=gt;
        }
        if (dem%2==1) g[++cnt]=gt;
    }
}
void Try(int i)
{
    for (int j=0;j<=1;j++)
    {
        x[i]=j;
        b[j]*=g[i];
        if (i==cnt)
        {
            if (r[0]+r[1]>b[0]+b[1])
            {
                r[0]=b[0];
                r[1]=b[1];
            }
        }
        else if (i<cnt) Try(i+1);
        b[j]/=g[i];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("minsum.inp","r",stdin);
    freopen("minsum.out","w",stdout);
    cin>>t;
    sangnt();
    while (t)
    {
        cin>>A>>B;
        int k=__gcd(A,B);
        A/=k; B/=k;
        cnt=0;
        pt(A); pt(B);
        b[0]=b[1]=1;
        r[0]=r[1]=nmax;
        Try(1);
        cout<<r[0]<<' '<<r[1]<<'\n';
        t--;
    }
    return 0;
}

