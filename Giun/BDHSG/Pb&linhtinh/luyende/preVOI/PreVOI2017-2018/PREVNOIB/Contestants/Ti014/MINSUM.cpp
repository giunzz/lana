#include <bits/stdc++.h>
#define ft first
#define sd second
#define mn
#define mod
#define PI 3.14159265
#define MP make_pair
#define PB push_back
#define heap priority_queue
#define Bjerg "MINSUM"
using namespace std;
long t,a,b;
void lam(long x,long y)
{
    long g=__gcd(x,y);
    x/=g;
    y/=g;
    long long mu=1ll*x*y;
    for(long i=10^5;i>=2;--i)
    {
        while(mu%(1ll*i*i)==0)
        {
            mu/=(1ll*i*i);
        }
    }
    for(long k=sqrt(mu);k>=1;--k)
    {
        if(mu%k==0)
        {
            cout << k <<" "<< mu/k <<"\n";
            return ;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(Bjerg".inp","r",stdin);
    freopen(Bjerg".out","w",stdout);
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        lam(a,b);
    }
    return 0;
}
