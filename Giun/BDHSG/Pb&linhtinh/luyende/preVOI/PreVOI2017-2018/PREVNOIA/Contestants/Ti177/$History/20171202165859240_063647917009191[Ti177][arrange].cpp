#include <bits/stdc++.h>
#define nmax 500007

using namespace std;

long long n,a[nmax],sum=0;

void sub1()
{
    long long yc=sum/n,ans=0,x=1;
    for (long i=1; i<=n; i++)
      if (a[i]>yc)
       {
           while (a[i]>yc)
           {
               while (a[x]>=yc) x++;
               if (x>n) break;
               long cho=a[i]-yc;
               long nhan=yc-a[x];
               if (cho>nhan)
               {
                   ans+=abs(x-i)*(yc-a[x]);
                   a[i]-=(yc-a[x]);
                   a[x]=yc;
               }
               else
                if (nhan==cho)
                {
                     ans+=abs(x-i)*cho;
                     a[x]=yc;
                     a[i]=yc;
                }
                else
                {
                    ans+=abs(x-i)*(a[i]-yc);
                    a[x]+=(a[i]-yc);
                    a[i]=yc;
                }
           }
           if (x>n) break;
           //for (long k=1; k<=n; k++) cout << a[k] << " " ;cout << endl;
       }
    cout << ans;
}

void sub2()
{
    long long yc=sum/n,ans=0,x=1,catr=yc+1,cad=yc;

    for (long i=1; i<=n; i++)
      if (a[i]>yc)
       {
           while (a[i]>yc)
           {
               while (a[x]>=yc) x++;
               if (x>n) break;
               long cho=a[i]-yc;
               long nhan=yc-a[x];
               if (cho>nhan)
               {
                   ans+=abs(x-i)*(yc-a[x]);
                   a[i]-=(yc-a[x]);
                   a[x]=yc;
               }
               else
                if (nhan==cho)
                {
                     ans+=abs(x-i)*cho;
                     a[x]=yc;
                     a[i]=yc;
                }
                else
                {
                    ans+=abs(x-i)*(a[i]-yc);
                    a[x]+=(a[i]-yc);
                    a[i]=yc;
                }
           }
           if (x>n) break;
       }
    bool ok=true;
    //for (long k=1; k<=n; k++) cout << a[k] << " " ;cout << endl;

    for (long k=1; k<=n; k++)
       if (a[k]>catr)
       {
          ok=false;
          break;
       }
    if (ok)
    {
        cout << ans;
        return;
    }
    long long dem1=0,vtd=999999,vtc=-1;
    for (long long i=1; i<=n; i++)
      if (a[i]>yc)
      {
          dem1+=(a[i]-yc);
          vtd=min(i,vtd);
          vtc=max(i,vtc);
      }
    x=vtd-dem1/2;
    if (vtd+dem1/2>n)
    {
        x=n-dem1+1;
    }

    yc=catr;
    for (long i=1; i<=n; i++)
      if (a[i]>catr)
       {
           while (a[i]>yc)
           {
               while (a[x]>=yc) x++;
               if (x>n) break;
               long cho=a[i]-yc;
               long nhan=yc-a[x];
               if (cho>nhan)
               {
                   ans+=abs(x-i)*(yc-a[x]);
                   a[i]-=(yc-a[x]);
                   a[x]=yc;
               }
               else
                if (nhan==cho)
                {
                     ans+=abs(x-i)*cho;
                     a[x]=yc;
                     a[i]=yc;
                }
                else
                {
                    ans+=abs(x-i)*(a[i]-yc);
                    a[x]+=(a[i]-yc);
                    a[i]=yc;
                }
           }
           if (x>n) break;
       }

    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("arrange.inp","r",stdin);
    freopen("arrange.out","w",stdout);
    //scanf("%lld",&n);
    cin >> n;
    for (long i=1; i<=n; i++)
    {
        //scanf("%lld",&a[i]);
        cin >> a[i];
        sum+=a[i];
    }
    if (sum%n==0)
    {
        sub1();
        return 0;
    }
    sub2();
}
