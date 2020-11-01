#include<bits/stdc++.h>
#define maxn 1000001
using namespace std;
int t,n,m,a,b,e[maxn],np,p[maxn],d[maxn][101];
int u[maxn],v[maxn],sl1,sl2,s1,s2;
void ankin()
{
    for(int i=1; i<=maxn; i++) e[i]=i;
    np=0;
    for(int i=2; i<=maxn; i++)
    {
        if(e[i]==i) p[++np]=i;
        int j=1;
        while(j<=np&&p[j]<=e[i]&&p[j]<=maxn/i)
        {
            e[p[j]*i]=p[j];
            j++;
        }
    }
}


int main()
{
    freopen("minsum.inp","r",stdin);
    freopen("minsum.out","w",stdout);
    ios::sync_with_stdio(false);
    ankin();
    cin>>t;
    u[0]=1;
    v[0]=1;
    while(t--)
    {
        sl1=0;
        sl2=0;
        s1=0;
        s2=0;
        cin>>a>>b;
        int f=__gcd(a,b);
        a/=f;
        b/=f;
        int m=a,n=b;
        while(a>1&&s1<np)
        {
            int dem=0;
            int q=p[++s1];
            while(a%q==0)
            {
                a=a/q;
                dem++;
                m/=q;
            }
            if(dem%2==1)u[++sl1]=q;
        }
        //////////////
        while(b>1&&s2<np)
        {
            int dem=0;
            int q=p[++s2];
            while(b%q==0)
            {
                b=b/q;
                dem++;
                n/=q;
            }
            if(dem%2==1)u[++sl1]=q;
        }
        if(m>1)u[++sl1]=m;
        if(n>1)u[++sl1]=n;
        //for(int i=1;i<=sl1;i++)cout<<u[i]<<" ";
        sort(u+1,u+sl1+1);
        int l1=u[sl1];
        int l2=1;
        for(int i=sl1-1; i>=1; i--)
        {
            if(l1<l2)l1*=u[i];
            else if(l1>l2)l2*=u[i];
        }
        cout<<min(l1,l2)<<" "<<max(l1,l2)<<endl;
    }
}
