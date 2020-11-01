#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Forc(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
int a,b,n,c[100],A[101],B[101];
long long mod=1,k,temp;
string s;
long long Pow(int a,int n)
{
    if(n==0) return 1%mod;
    if(n==1) return a%mod;
    long long x=Pow(a,n/2)%mod;
    x=(x*x)%mod;
    if(n%2) return (x*a)%mod;
    return x;
}
void duyet(int x)
{
    if(x>n)
    {
        if(temp%mod==k)
        {
            Forc(i,n,1) cout<<c[i];
            exit(0);
        }
        return;
    }
    For(i,0,1)
    {
        if(!i) c[x]=a,temp=(temp+A[x-1])%mod;
        else c[x]=b,temp=(temp+B[x-1])%mod;
        duyet(x+1);
        if(!i) temp=(temp-A[x-1])%mod;
        else temp=(temp-B[x-1])%mod;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    freopen("modulo.inp","r",stdin);
    freopen("modulo.out","w",stdout);
    cin>>a>>b>>n>>k;
    if((a%2==0&&b%2==0&&k%2)||(a%2&&b%2&&k%2==0))
    {
        cout<<-1;
        return 0;
    }
    For(i,1,n) mod=mod*2;
    For(i,0,n-1)
    {
        long long x=Pow(10,i);
        A[i]=(a*x)%mod;
        B[i]=(b*x)%mod;
    }
    duyet(1);
    cout<<-1;
}
