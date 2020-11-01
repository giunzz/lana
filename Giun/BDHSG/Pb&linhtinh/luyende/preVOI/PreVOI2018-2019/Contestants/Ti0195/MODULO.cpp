#include<bits/stdc++.h>
using namespace std;
unsigned long long a,b,n,k,x[64],v[3],p,z,s,t,c;
long long ff(long long y)
{
    p=1;
    for(int i=1;i<=y;i++)
    {
      p*=10;
    }
    return p/10;
}
long long ff1(long long k)
{
    t=1;
    for(int i=1;i<=k;i++)
    {
      t*=2;
    }
    return t;
}
void att(int r)
{
    if(r==n+1)
    {
        s=0;
        z=ff(n);
        for(int i=1;i<=n;i++)
        {
            s+=x[i]*z;
            z/=10;
        }
        if(s%ff1(n)==k)
        {
            c++;
            cout<<s;
        }
        else return;
    }
        for(int j=1;j<=2;j++)
        {
            x[r]=v[j];
            att(r+1);
        }
}
int main()
{
    freopen("MODULO.INP","r",stdin);
    freopen("MODULO.OUT","w",stdout);
    cin>>a>>b>>n>>k;
    v[1]=a;
    v[2]=b;
    if(n<=20)
    {
    att(1);
    if(c==0) cout<<-1;
    }
    else cout<<-1;
}
