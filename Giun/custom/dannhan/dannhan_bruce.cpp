#include <bits/stdc++.h>
#define ll long long
#define For(u,b,c) for(ll u=b;u<=c;u++)
using namespace std;
#define fname "dannhan"
 const ll maxn=1e7+5;
int a[maxn]={0},x;
ll ans=0,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen(fname".inp", "r", stdin);
    freopen(fname".ans", "w", stdout);

    cin>>n;
    For(i,1,n) {cin>>x;
    a[x]++;
    if(a[x]>=2)
        ans++;
    a[x]=1;
    }
  /*  For(i,1,maxn){
      if(a[i]>=2){
        ans+=a[i]-1;
      }
    }*/
    cout<<ans;
    return 0;
}
