#include <bits/stdc++.h>
using namespace std;

ifstream fi("ARRANGE.INP");
ofstream fo("ARRANGE.OUT");

int64_t n,k,sum=0,a[100005],S[100005],C[10000005],F[10000005],c[2005][2005],f[2005][2005];

void Sub1()
{
    int64_t res=0,s=0,tmp=sum/n;
    for(int64_t i=1; i<=n; i++)
    {
        s+=a[i]-tmp;
        res+=abs(s);
    }
    fo<<res;
}

void Sub2()
{
    k=sum%n;
    int64_t res=0,tmp=sum/n;
    for(int64_t i=1; i<=n; i++)
    {
        S[i]=S[i-1]+a[i]-tmp;
        res+=abs(S[i]);
    }
    for(int64_t i=n; i>=1; i--)
        for(int64_t j=0; j<=k; j++)
        {
            c[i][j]=c[i+1][j];
            if(S[i]<j)
                c[i][j]++;
        }
    for(int64_t i=0; i<=n; i++)
        for(int64_t j=0; j<=k; j++)
            f[i][j]=1e16;
    f[0][0]=0;
    for(int64_t i=1; i<=n; i++)
        for(int64_t j=0; j<=min(k,i); j++)
        {
            f[i][j]=min(f[i][j],f[i-1][j]);
            if(j>0)
                f[i][j]=min(f[i][j],f[i-1][j-1]+c[i][j]-((n-i+1)-c[i][j]));
        }
    fo<<res+f[n][k];
}

int64_t ID(int64_t i,int64_t j)
{
    return i*(k+1)+j+1;
}

void Sub3()
{
    k=sum%n;
    int64_t res=0,tmp=sum/n;
    for(int64_t i=1; i<=n; i++)
    {
        S[i]=S[i-1]+a[i]-tmp;
        res+=abs(S[i]);
    }
    for(int64_t i=n; i>=1; i--)
        for(int64_t j=0; j<=k; j++)
        {
            C[ID(i,j)]=C[ID(i+1,j)];
            if(S[i]<j)
                C[ID(i,j)]++;
        }
    for(int64_t i=0; i<=n; i++)
        for(int64_t j=0; j<=k; j++)
            F[ID(i,j)]=1e16;
    F[ID(0,0)]=0;
    for(int64_t i=1; i<=n; i++)
        for(int64_t j=0; j<=min(k,i); j++)
        {
            F[ID(i,j)]=min(F[ID(i,j)],F[ID(i-1,j)]);
            if(j>0)
                F[ID(i,j)]=min(F[ID(i,j)],F[ID(i-1,j-1)]+C[ID(i,j)]-((n-i+1)-C[ID(i,j)]));
        }
    fo<<res+F[ID(n,k)];
}

int main()
{
    fi>>n;
    for(int64_t i=1; i<=n; i++)
    {
        fi>>a[i];
        sum+=a[i];
    }
    if(sum%n==0)
        Sub1();
    else
    if(n<=2000)
        Sub2();
    else
        Sub3();
}
