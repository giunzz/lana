#include <bits/stdc++.h>
#define forr(i,a,b) for( int i=(a);i<=(b);++i)
#define ford(i,a,b) for( int i=(a);i>=(b);--i)
#define f first
#define s second
#define ll long long
#define pii pair<int,int>
#define task "MINSUM"

using namespace std;

const long long mod=1e9+7;
ll ans,ans1,ans2 ;
int getint()
{
   int ww = 0; char cc = getchar();
   while (cc > '9' || cc < '0') cc = getchar();
   while (cc >= '0' && cc <= '9') { ww = ww * 10 + cc - '0'; cc = getchar(); }
   return ww;
}

ll getll()
{
   ll ww = 0; char cc = getchar();
   while (cc > '9' || cc < '0') cc = getchar();
   while (cc >= '0' && cc <= '9') { ww = ww * 10 + cc - '0'; cc = getchar(); }
   return ww;
}

int getbit(int bit,int id)
{
    return bit>>id&1;
}

void input()
{
    int test;
    test=getint();
    while (test--)
    {
        ll u,v;
        u=getll();
        v=getll();
        ll z=__gcd(u,v);
        u/=z;
        v/=z;
        ans=u+v;
        ans1=u;
        ans2=v;
        ll u1=u;
        ll v1=v;
        ll u2=u;
        ll v2=v;
        forr(i,2,sqrt(u1))
        if (u1%i==0)
        {
            while (u1%i==0)
            {
                u1/=i;
                v1*=i;
                ll z1=__gcd(u1,v1);
                if (ans>u1/z1+v1/z1)
                {
                    ans=u1/z1+v1/z1;
                    ans1=u1/z1;
                    ans2=v1/z1;
                }
            }
        }
        forr(i,2,sqrt(v2))
        if (v2%i==0)
        {
            while (v2%i==0)
            {
                v2/=i;
                u2*=i;
                ll z2=__gcd(u2,v2);
                if (ans>u2/z2+v2/z2)
                {
                    ans=u2/z2+v2/z2;
                    ans1=u2/z2;
                    ans2=v2/z2;
                }
            }
        }
        cout<< ans1 << " " << ans2 << endl;
    }
}

void output()
{

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen( task".inp" , "r" , stdin );
    freopen( task".out" , "w" , stdout );
    input();
    output();
    return 0;
}
