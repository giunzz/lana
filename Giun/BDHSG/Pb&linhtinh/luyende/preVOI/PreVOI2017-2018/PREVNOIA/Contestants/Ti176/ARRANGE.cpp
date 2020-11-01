#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Nmax=1e5+7;
const int oo=1e13+7;
int n,sum,a[Nmax];
main()
{
    freopen("ARRANGE.inp","r",stdin);
    freopen("ARRANGE.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    sum=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if (sum%n==0)
    {
        int ans=0;
        int w=sum/n;
        sort(a+1,a+n+1);
        for (int i=1;i<=n;i++)
        {
            if (a[i]<w) ans+=w-a[i];
        }
        cout<<ans;
    }
    else
    {
        int x,y,aa,ans=0;
        int l=(sum-n)/n;
        int r=sum/n;
        int Min=oo;
        for (int aa=l;aa<=r;aa++)
        {
            y=(sum-aa*n);
            if (y>n) continue;
            x=n-y;
            //cout<<x<<" "<<y<<" "<<aa<<endl;
            sort(a+1,a+n+1);
            for (int i=1;i<=x;i++)
            {
                if (a[i]<aa)
                    ans+=aa-a[i];
            }
            for (int i=x+1;i<=n;i++)
            {
                if (a[i]<aa+1)
                    ans+=aa+1-a[i];
            }
            Min=min(Min,ans);
        }
        cout<<Min;
    }
    return 0;
}
