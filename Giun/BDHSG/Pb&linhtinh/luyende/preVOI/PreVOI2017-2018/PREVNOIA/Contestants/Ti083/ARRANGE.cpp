#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll res=0,a[1000006],sum=0,n,dd[2];
void sub1()
{
    ll temp=sum/n;
    for (int i=1;i<=n;i++)
    {
        res+=abs(a[i]-temp);a[i+1]+=a[i]-temp;a[i]=temp;
    }
    cout<<res;
}
void sub2()
{
    ll avg=sum/n;
    for (int i=1;i<=n;i++)
    {
        for (int j=i+1;a[i]<avg&&j<=n;j++)
        if (a[j]>avg+1)
        {
            ll temp=min(a[j]-avg-1,avg-a[i]);
            res+=temp*(j-i);//cout<<temp<<' '<<i<<' '<<j<<'\n';
            a[i]+=temp;
            a[j]-=temp;
        }
        if (a[i]>avg+1)
        {res+=a[i]-avg-1;a[i+1]+=a[i]-avg-1;a[i]=avg+1;}
    }
    cout<<a[1]-avg-1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("ARRANGE.INP","r",stdin);
    freopen("ARRANGE.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {cin>>a[i];sum+=a[i];}
    dd[0]=n-(sum%n);
    dd[1]=sum%n;
    //if (dd[0]==n)
    //sub2();
    sub1();
    return 0;

}
