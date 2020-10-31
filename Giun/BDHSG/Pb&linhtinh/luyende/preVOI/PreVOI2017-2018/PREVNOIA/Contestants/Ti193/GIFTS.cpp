#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,k,a[1000001],ans;

void khoitao()
{
    freopen("GIFTS.INP","r",stdin);
    freopen("GIFTS.OUT","w",stdout);
}
void dong()
{
    fclose(stdin);
    fclose(stdout);

}
void nhap()
{
    cin>>n>>k;
    a[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
}
struct ii
{
    int val,pos;
};
ii b[1000001];
bool cmp(ii a,ii b)
{
    return a.val<b.val ;
}
void xuli()
{

    for(int i=k;i<=n;i++)
    {
       b[i].val=a[i]-a[i-k];
       b[i].pos=i;
    }
    sort(b+k+1,b+n+1,cmp);

    int ans=b[n].val;

    for(int i=n-1;i>=n-k;i--)
    {
          bool ok=true;
          for(int j=i+1;j<=n;j++)
    {
        if(b[j].val>b[i].val && abs(b[j].pos-b[i].pos)>=k) ok=false;

    }
     if(ok==true) ans=b[i].val;

    }

    cout<<ans;

}
int main()
{
    khoitao();
    nhap();
    xuli();
    dong();
}
