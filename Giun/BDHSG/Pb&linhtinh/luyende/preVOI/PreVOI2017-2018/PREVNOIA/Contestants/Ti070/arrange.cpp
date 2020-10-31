#include <bits/stdc++.h>
#define N 1000001
using namespace std;
long n,tb;
long a[1000001];
long long sum,ans;
typedef pair<long,long>ii;
priority_queue<ii>hmin,hmax;
void nhap()
{
    cin>>n;
    for(long i=1;i<=n;++i)
    {
        cin>>a[i];
        sum+=a[i];
    }
    tb=sum/n;
}
void lam()
{
    long pos,res,id;
    for(long i=1;i<=n;++i)
    {
        while(!hmax.empty()&&a[i]<tb)
        {
            pos=hmax.top().first;
            id=hmax.top().second;
            hmax.pop();
            res=min(pos-tb,tb-a[i]);
            a[i]+=res;
            pos-=res;
            a[id]-=res;
            ans=ans+1ll*(i-id)*res;
            if(pos>tb)
                hmax.push(make_pair(pos,id));
        }
        while(!hmin.empty()&&a[i]>tb)
        {
            pos=-hmin.top().first;
            id=hmin.top().second;
            hmin.pop();
            res=min(a[i]-tb,tb-pos);
            a[i]-=res;
            pos+=res;
            a[id]+=res;
            ans=ans+1ll*(i-id)*res;
            if(pos<tb)hmin.push(make_pair(-pos,id));
        }
        if(a[i]>tb)
                hmax.push(make_pair(a[i],i));
        if(a[i]<tb)
            hmin.push(make_pair(-a[i],i));
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("arrange.inp","r",stdin);
    freopen("arrange.out","w",stdout);
    nhap();
    lam();
    if(!hmax.empty())
    {
        tb++;
        while(hmax.size())hmax.pop();
        while(hmin.size())hmin.pop();
        /*for(long i=1;i<=n;++i)
        {
            cout<<a[i]<<" ";
        }*/
        lam();
    }
    cout<<ans;
    return 0;
}
