#include <bits/stdc++.h>
#define foreinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define forv(a,b) for(auto&a:b)
#define pii pair<int,int>
#define fi first
#define se second
#define int long long
using namespace std;
inline int read()
{
    int x=0; bool ok=false; char c=getchar();
    while(!isdigit(c)) ok=(c=='-'),c=getchar();
    while(isdigit(c)) x=x*10+c-'0',c=getchar();
    if(ok) return -x; return x;
}
const int N=70;
int n,a,b,k;
int x[N];
void check()
{
    int s=0;
    foreinc(i,1,n)
    {
        if(x[i]==0) s=s*10+a;
        else s=s*10+b;
        s%=(1<<n);
    }
    s%=(1<<n);
    if(s==k)
    {
        foreinc(i,1,n) cout<<(x[i]==0?a:b);
        exit(0);
    }
}
void duyet(int i)
{
    if(i==n+1) check();
    else foreinc(j,0,1) x[i]=j,duyet(i+1);
}
main()
{
    freopen("modulo.inp","r",stdin);
    freopen("modulo.out","w",stdout);
    a=read();b=read();
    n=read();k=read();
    if(n<=22)
    {
        duyet(1);
        cout<<-1;
        return 0;
    }
}
