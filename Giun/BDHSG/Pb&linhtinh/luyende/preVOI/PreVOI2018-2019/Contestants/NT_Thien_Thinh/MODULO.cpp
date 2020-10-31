#include<bits/stdc++.h>
using namespace std;
long long a,b,n,ans=1,x[45],t=2,k;

bool kt()
{
    ans=0;
    for(int i=1;i<=n;i++) {ans*=10;if(x[i]==1) ans+=a;else ans+=b;}
    if(ans%t==k) return true;
    else return false;
    //cout<<ans<<endl;
}


void quaylui(int i)
{
    for(int j=1;j<=2;j++)
    {
        x[i]=j;
        if(i==n) {if(kt()==true) {cout<<ans;exit(0);}}
        else quaylui(i+1);
    }
}


int main()
{
    freopen("MODULO.inp","r",stdin);
    freopen("MODULO.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b;
    cin>>n>>k;
    int i,j;
    for(i=2;i<=n;i++) t*=2;
    if(n<=24) quaylui(1);
    else {cout<<-1;exit(0);}
    cout<<-1;
}
