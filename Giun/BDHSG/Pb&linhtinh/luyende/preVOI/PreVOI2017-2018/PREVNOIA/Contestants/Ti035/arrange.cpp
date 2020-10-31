#include<bits/stdc++.h>
using namespace std;
#define F1(i,a,b) for(int i=a;i<=b;++i)
#define F2(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;
const int maxn=1e5+10;
int n;
ll a[maxn],res=0,sub=0;
void sub1()
{
    ll x=sub/n;
    F1(i,1,n-1)
    {
      a[i+1]+=(a[i]-x);
      res+=abs(a[i]-x);
    }
    cout<<res;
}
int main()
{
    freopen("arrange.inp","r",stdin);
    freopen("arrange.out","w",stdout);
    scanf("%d",&n);
    F1(i,1,n)
    {
        scanf("%lld",&a[i]);
        sub+=a[i];
    }
    sub1();
    return 0;
}
