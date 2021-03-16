#include<bits/stdc++.h>
using namespace std;
int x[30],dem=0,sum=0,best=30,n,maxa[30],a[30],s;
void capnhat()
{
    if (sum==s && best>dem) best=dem;
}

void qlui(int i)
{
    for(int j=0;j<=1;j++)
    {
        x[i]=j;
        sum+=x[i]*a[i];
        dem+=j;
        if (i==n) capnhat();
        else if(dem+(s-sum)/maxa[i+1]<best) qlui(i+1);
        sum-=x[i]*a[i];
        dem-=j;
    }
}
int main()
{
    freopen("atm.inp","r",stdin);
    freopen("atm.out","w",stdout);
    cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    maxa[n]=a[n];
    for(int i=n-1;i>=1;i--)maxa[i]=max(a[i],maxa[i+1]);
    //for(int i=1;i<=n;i++)cout<<maxa[i]<<" ";
    //cout<<endl;
    qlui(1);
    if (best==30) cout<<-1;
    else cout<<best;
    return 0;
}
