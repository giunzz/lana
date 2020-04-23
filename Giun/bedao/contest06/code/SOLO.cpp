#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
int test,k,n,a[10010],p;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("SOLO.INP","r",stdin);
    freopen("SOLO.OUT","w",stdout);
    cin>>test;
    while(test--)
    {
        cin>>n>>k>>p;
        int mi=INT_MAX,ma=INT_MIN;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            mi=min(mi,a[i]);
            ma=max(ma,a[i]);
        }
        if(k%2==1){
            if(p==0)
                cout<<ma<<'\n';
            else
                cout<<mi<<'\n';
        }
        else{
            int Min=INT_MAX,Max=INT_MIN,rmax=INT_MIN,rmin=INT_MAX;
            Min=min(Min,a[2]);
            rmax=max(rmax,Min);
            Max=max(Max,a[2]);
            rmin=min(rmin,Max);
            rmax=max(rmax,a[n-1]);
            rmin=min(rmin,a[n-1]);
            for(int i=2;i<n;i++){
                Min=min(a[i-1],a[i+1]);
                rmax=max(rmax,Min);
                Max=max(a[i-1],a[i+1]);
                rmin=min(rmin,Max);
            }
            if(p==0)
                cout<<rmax<<'\n';
            else
                cout<<rmin<<'\n';
        }
    }
}
