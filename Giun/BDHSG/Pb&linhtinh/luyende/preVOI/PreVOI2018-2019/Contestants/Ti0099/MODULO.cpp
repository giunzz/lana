#include <bits/stdc++.h>

using namespace std;
    int a,b,n,k,x,d;
    bool kt1;
    long long so;
bool kt(long long sum)
{
   int sum1=sum,luu,stt=0;
   while (sum1>0)
   {
       stt++;
       sum1=sum1/10;
   }
   while (sum>0)
   {
      luu=sum%10;
      if (luu!=a&&luu!=b&&stt>n)
      {
          kt1=true;
          return false;
      }
      if (luu!=a&&luu!=b)
        return false;
      sum=sum/10;
   }
   if (stt>n)
   {
       return false;
       kt1=true;
   }
   else if (stt==n)
     return true;
   else
      return false;
}
int main()
{
    freopen("MODULO.inp","r",stdin);
    freopen("MODULO.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>a>>b;
    cin>>n>>k;
    x=1;
    for (int i=1; i<=n; i++)
    {
        x=x*2;
    }
    kt1=false;
    d=24;
    while (kt1==false||so>=100000000000000000)
    {
      so=x*d+k;
      if (kt(so))
      {
          cout<<so;
          return 0;
      }
      d=d+1;
    }
    cout<<-1;
}
