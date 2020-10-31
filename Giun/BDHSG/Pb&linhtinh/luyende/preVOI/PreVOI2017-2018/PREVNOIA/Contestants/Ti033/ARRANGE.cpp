#include<bits/stdc++.h>
#define llong long long
using namespace std;
int n, a[100005];
int main()
{
    freopen("ARRANGE.inp","r",stdin);
    freopen("ARRANGE.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    llong sm=0;
    for (int i=1; i <= n; i++){
        cin>>a[i];
        sm+=a[i];
    }
    llong X=sm/n;
    llong res=0;
    int tmp=0;
    for (int i=1; i <= n; i++){
        res+=tmp;
        if (a[i] > X)
            tmp+=(a[i]-X), a[i]=X;
        if ((a[i] < X)&&(tmp > 0)){
            if (tmp > X-a[i])
                a[i]=X, tmp-=(X-a[i]);
              else
                a[i]+=tmp, tmp=0;
        }
    }
    tmp=0;
    for (int i=n; i >= 1; i--){
        res+=tmp;
        if (a[i] > X)
            tmp+=(a[i]-X), a[i]=X;
        if ((a[i] < X)&&(tmp > 0)){
            if (tmp > X-a[i])
                a[i]=X, tmp-=(X-a[i]);
              else
                a[i]+=tmp, tmp=0;
        }
    }
    cout<<res;
    return 0;
}
