#include <bits/stdc++.h>

using namespace std;
long long s,a,b,n,k,x,am[70],bm[70],t,d[70];
string st;
void Try(int i)
{
    if (i>n)
    {
        if (t%s==k)
        {
            st="";
            for (int j=1;j<=n;j++) st=char(d[j]+48)+st;
        }
        return;
    }
    t+=am[i];d[i]=a;Try(i+1);t-=am[i];
    t+=bm[i];d[i]=b;Try(i+1);t-=bm[i];
}
void solve()
{
     //if (n<=20)
        {
            t=0;st="";Try(1);
            if (st.size()==n) cout<<st;else cout<<-1;
        }
}
int main()
{
    freopen("modulo.inp","r",stdin);
    freopen("modulo.out","w",stdout);
    cin>>a>>b;
    cin>>n>>k;
    s=2<<n-1;
    x=1;
    for (int i=1;i<=n;i++)
        {
            am[i]=(a*x)%s;bm[i]=(b*x)%s;
            x*=10;
        }
    solve();
    return 0;
}
