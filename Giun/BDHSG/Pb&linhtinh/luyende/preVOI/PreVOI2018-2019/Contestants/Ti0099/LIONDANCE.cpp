#include <bits/stdc++.h>

using namespace std;
   int x[50],a[50],b[50],n,k,luu[50],dodai,saved[50];
void check()
{
   int d=0,stt=0;;
   for (int i=1; i<=n; i++)
   {
       if (x[i]==1)
         luu[++d]=a[i];
   }
   int j1=0;
   luu[0]=luu[1];
   for (int i=1; i<=d; i++)
     {
      for (int j=j1+1; j<=n; j++)
        if (luu[i]==b[j])
        {
            stt=stt+1;
            j1=j;
            break;
        }
       if (abs(luu[i]-luu[i-1])>k)
           return;
     }
   if (stt != d)
      return;
   if (d<dodai)
      return;
   if (d>dodai)
   {
     for (int i=1; i<=d; i++)
        saved[i]=luu[i];
   }
   else if (d==dodai)
   {
      bool ktsaved=false, ktluu=false;
     for (int i=1; i<=d; i++)
     {
         if (saved[i]>luu[i])
         {
             ktsaved=true;
             break;
         }
         else if (saved[i]<luu[i])
            {
                ktluu=false;
                break;
            }
     }
     if (ktsaved==true)
     {
         for (int i=1; i<=d; i++)
            luu[i]=saved[i];
     }
     else
        for (int i=1; i<=d; i++)
           saved[i]=luu[i];
   }
   dodai=d;
}
void back1(int i)
{
   if (i>n)
   {
       check();
       return;
   }
   else
   {
       for (int j=0; j<=1; j++)
       {
           x[i]=j;
           back1(i+1);
       }
   }
}
int main()
{
    freopen("LIONDANCE.inp","r",stdin);
    freopen("LIONDANCE.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
        cin>>b[i];
    dodai=-1;
    x[1]=1;
    back1(1);
    cout<<dodai<<'\n';
    for (int i=1; i<=dodai; i++)
        cout<<saved[i]<<' ';

}
