#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const long long oo = 1e18;
int n;
int a[maxn];
long long s=0;
long long res;
bool kt()
{

    for(int i=1;i<=n;i++) s+=a[i];
    if(s%n==0) return 1;
    return 0;
}
void sub1()
{
    int k=s/n;
    int j=1;
    for(int i=1;i<=n;i++)
        if(a[i]<k)
    {
        while(a[i]<k)
        {

            while(a[j]<=k) j++;
            int x=k-a[i];
            int y=a[j]-k;
            if(x<=y)
            {
                a[i]=k;
                a[j]=a[j]-x;
                res+=abs(i-j)*x;
            }else
            {
                a[i]=a[i]+y;
                a[j]=k;
                res+=abs(i-j)*y;
            }
        }



    }
    cout<<res;
}
void sub2()
{
    //cout<<s;
    int k=s/n;
    int u,v;
    for(int i=1;i<=n;i++)
        if(a[i]<k)
        {
           // cout<<i<<' ';
            u=i-1;
            v=i+1;
            while(a[i]<k)
            {

                while(u>=1&&a[u]<=k) u--;
                while(v<=n&&a[v]<=k) v++;
                if(i-u<=v-i)
                {

                    int x=k-a[i];
                    int y=a[u]-k;
                    if(x<=y)
                    {
                        a[i]=k;
                        a[u]=a[u]-x;
                        res+=abs(i-u)*x;
                    }else
                    {
                        a[i]=a[i]+y;
                        a[u]=k;
                        res+=abs(i-u)*y;
                    }
                }else
                {
                    int x=k-a[i];
                    int y=a[v]-k;
                    if(x<=y)
                    {
                        a[i]=k;
                        a[v]=a[v]-x;
                        res+=abs(i-v)*x;
                    }else
                    {
                        a[i]=a[i]+y;
                        a[v]=k;
                        res+=abs(i-v)*y;
                    }
                }
            }
          //  cout<<res<<'\n';



    }

    for(int i=1;i<=n;i++)
        if(a[i]>k)
    {
        int h=((a[i]-k)-1);
        if(h%2==0)
        {
            long long u=h/2;
            res+=u*(u+1);
        }else
        {
            long long u=h/2;
            res+=(u*(u+1)/2+(u+1)*(u+2)/2);
        }
    }
    cout<<res;
}
int main()
{
    freopen("arrange.inp","r",stdin);
    freopen("arrange.out","w",stdout);
   ios_base::sync_with_stdio(0);
   cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(kt()) sub1();
    else sub2();
}
