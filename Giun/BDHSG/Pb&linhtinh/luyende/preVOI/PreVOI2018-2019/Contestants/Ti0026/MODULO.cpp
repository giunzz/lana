#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    char c;
    int res,neg=1;
    c=getchar();
    if(c=='-') {neg=-1;c=getchar();}
    res=c-'0';
    for(c=getchar();c>='0' && c<='9';c=getchar()) res=res*10+c-'0';
    return neg*res;
}
void write(int x)
{
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
long long a,b,n;
unsigned long long k,mod=1;
long long ok(unsigned long long i,long long j)
{
    return (i>>(j-1))&1;
}
void out(unsigned long long x,long long l)
{
    long long i;
    for(i=1;i<=l;i++)
    {
        if(ok(x,i)) cout<<a;
        else cout<<b;
    }
}
int main()
{
    #define file "MODULO"
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long j,s,add=1;
    unsigned long long i;
    map<unsigned long long,long long> m;
    cin>>a>>b>>n>>k;
    if(n>=45) {cout<<-1;return 0;}
    for(i=1;i<=n;i++) mod=mod*2;
    for(i=1;i<=n/2;i++) add=(add*10)%mod;
    for(i=0;i<(1<<(n/2));i++)
    {
        s=0;
        for(j=1;j<=n/2;j++)
        {
            if(ok(i,j)) s=(s*10+a)%mod;
            else s=(s*10+b)%mod;
        }
        m[s]=i+1;
    }
    for(i=0;i<(1<<(n-n/2));i++)
    {
        s=0;
        for(j=1;j<=(n-n/2);j++)
        {
            if(ok(i,j)) s=(s*10+a)%mod;
            else s=(s*10+b)%mod;
        }
        s=(s*add)%mod;
        if(m[k-s]!=0)
        {
            out(i,n-n/2);
            out(m[k-s]-1,n/2);
            return 0;
        }
        if(m[mod+k-s]!=0)
        {
            out(i,n-n/2);
            out(m[mod+k-s]-1,n/2);
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
