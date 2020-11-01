#include <bits/stdc++.h>
#define PII pair<int,int>
#define F first
#define S second
#define LL long long
using namespace std;
const int N=(1<<20);

int a,b,n;
LL mod,k;
PII f[N+1];

void sub12()
{
    int n1=n/2,n2=n-n1;
    LL base=(1<<n),k=1;
    for (int i=0;i<n1;i++) k=(k*10)%base;
    for (int i=0;i<(1<<n1);i++)
    {
        LL du=0;
        for (int j=0;j<n1;j++)
        if (((1<<j)&i)==0) du=(du*10+a)%base;
        else du=(du*10+b)%base;
        f[i]=PII(du,i);
    }
    sort(f,f+(1<<n1));
    for (int i=0;i<(1<<n2);i++)
    {
        LL du=0;
        for (int j=0;j<n2;j++)
        if (((1<<j)&i)==0) du=(du*10+a)%base;
        else du=(du*10+b)%base;
        du=(du*k)%base;
        int c=(mod+base-du)%base;
        int x=lower_bound(f,f+(1<<n1),PII(c,0))-f;
        if (f[x].F==c)
        {
            for (int j=0;j<n2;j++)
            if (((1<<j)&i)==0) cout<<a;
            else cout<<b;
            for (int j=0;j<n1;j++)
            if (((1<<j)&f[x].S)==0) cout<<a;
            else cout<<b;
            return;
        }
    }
    cout<<-1;
}
int main()
{
    freopen("modulo.inp","r",stdin);
    freopen("modulo.out","w",stdout);
    ios_base::sync_with_stdio();
    cin.tie(0);cout.tie(0);
    cin>>a>>b>>n>>mod;
    if (n<=40) sub12();
    return 0;
}
