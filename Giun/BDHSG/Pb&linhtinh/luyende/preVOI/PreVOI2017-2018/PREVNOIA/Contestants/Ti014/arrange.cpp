#include <bits/stdc++.h>
#define ft first
#define sd second
#define maxn 100005
#define mod
#define PI 3.14159265
#define MP make_pair
#define PB push_back
#define heap priority_queue
#define Bjerg "arrange"
using namespace std;
long long sum;
long n,bien,k,a[maxn],trc[maxn],sau[maxn];
typedef pair < long , long > ii;
heap < ii > hmin,hmax;
nhap()
{
    cin >> n;
    for(long i=1;i<=n;++i)
    {
        cin >> a[i];
        sum+=a[i];
    }
    k=sum/n;
    bien=sum%n;
}
void sub1()
{
    if(bien!=0) return ;
    long last=0;
    long long res=0;
    for(long i=1;i<=n;++i)
    {
        if(a[i]==k) continue;
        if(a[i]>k) trc[i]=last,last=i;
    }
    last=n+1;
    for(long i=n;i>=1;--i)
    {
        if(a[i]==k) continue;
        if(a[i]>k) sau[i]=last,last=i;
    }
    for(long i=1;i<=n;++i)
    {
        if(a[i]>=k) continue;
        long ans=k-a[i];
        long t=i;
        while(a[t]<=k && t>0) t--;
        while(ans && t>0)
        {
            if(a[t]-k>=ans)
            {
                a[t]-=ans;
                res+=ans*(i-t);
                ans=0;
            }
            else
            {
                ans-=a[t]-k;
                res+=(a[t]-k)*(i-t);
                a[t]=k;
                t=trc[t];
            }
        }
        t=i;
        while(a[t]<=k && t<=n) t++;
        while(ans && t<=n)
        {
            if(a[t]>=ans+k)
            {
                a[t]-=ans;
                res+=ans*(t-i);
                ans=0;
                a[i]=k;
            }
            else
            {
                ans-=a[t]-k;
                res+=1ll*(a[t]-k)*(t-i);
                a[t]=k;
                t=sau[t];
            }
        }
        a[i]=k;
    }
    cout << res;
    exit(0);
}
void sub2()
{
    long last=0;
    long long res=0;
    for(long i=1;i<=n;++i)
    {
        if(a[i]<k) continue;
        if(a[i]>=k) trc[i]=last,last=i;
    }
    last=n+1;
    for(long i=n;i>=1;--i)
    {
        if(a[i]<k) continue;
        if(a[i]>=k) sau[i]=last,last=i;
    }
    for(long i=1;i<=n;++i)
    {
        if(a[i]>=k) continue;
        long tr=i,sa=i;
        while(tr>0 && a[tr]<=k)tr--;
        while(sa<=n && a[sa]<=k) sa++;
        long ans=k-a[i];
        while(ans >0)
        {
        while(ans && tr>0 )
        {
            if(a[tr]-k>=ans)
            {
                a[tr]-=ans;
                res+=ans*(i-tr);
                ans=0;
            }
            else
            {
                ans-=a[tr]-k;
                res+=(a[tr]-k)*(i-tr);
                a[tr]=k;
                tr=trc[tr];
            }
        }
        while(ans && sa <=n)
        {
            if(a[sa]>=ans+k)
            {
                a[sa]-=ans;
                res+=ans*(sa-i);
                ans=0;
            }
            else
            {
                ans-=a[sa]-k;
                res+=1ll*(a[sa]-k)*(sa-i);
                a[sa]=k;
                sa=sau[sa];
            }
        }
        }
        a[i]=k;
    }
    for(long i=1;i<=n;++i)
    {
        if(a[i]>k+1)
        {
            long t=1;
            while(a[i]>k+1)
            {
                long u=i-t;
                long v=i+t;
                if(u>0 &&a[u]<k+1) a[u]++,a[i]--,res+=t;
                if(v<n+1 && a[v]<k+1) a[v]++,a[i]--,res+=t;
                t++;
            }
        }
    }
    cout << res;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(Bjerg".inp","r",stdin);
    freopen(Bjerg".out","w",stdout);
    nhap();
    sub1();
    sub2();
    return 0;
}
