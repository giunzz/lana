#include<bits/stdc++.h>
using namespace std;
#define F1(i,a,b) for(int64_t i=a;i<=b;++i)
#define F2(i,a,b) for(int64_t i=a;i>=b;--i)
typedef long long ll;
int test;
ll a,b,res,resa,resb;
vector<ll> v1,v2;
ll ucln(ll a,ll b)
{
    int x;
    while (b)
    {
        x=a%b;
        a=b;
        b=x;
    }
    return a;
}
void check(ll x,ll y)
{
    int k=ucln(x,y);
    if (res>(x+y)/k)
    {
        res=(x+y)/k;
        resa=x/k;resb=y/k;
    }
}
void sol(ll a,ll b)
{
    resa=a,resb=b;
    res=(a+b)/ucln(a,b);
    v1.clear();v2.clear();
    v1.push_back(a);v2.push_back(b);
    F1(i,2,trunc(sqrt(a)))
     if (a%i==0)
     {
         v1.push_back(i);
         if (i!=a/i) v1.push_back(a/i);
     }
    F1(i,2,trunc(sqrt(b)))
     if (b%i==0)
     {
         v2.push_back(i);
         if (i!=b/i) v2.push_back(b/i);
     }
    if (v1.size()) F1(i,0,v1.size()-1)
    {
        check(v1[i],(a/v1[i])*b);
        check(a/v1[i],v1[i]*b);
    }
    if (v2.size()) F1(i,0,v2.size()-1)
    {
        check(v2[i],(b/v2[i])*a);
        check(b/v2[i],v2[i]*a);
    }
    if (v1.size() && v2.size())
    {
     F1(i,0,v1.size()-1)
      F1(j,0,v2.size()-1)
          check(v1[i]*v2[j],(a*b)/(v1[i]*v2[j]));
    }
    cout<<resa<<' '<<resb<<'\n';
}
int main()
{
    freopen("minsum.inp","r",stdin);
    freopen("minsum.out","w",stdout);
    scanf("%d",&test);
    while (test--)
    {
        scanf("%d%d",&a,&b);
        sol(a,b);
    }
    return 0;
}
