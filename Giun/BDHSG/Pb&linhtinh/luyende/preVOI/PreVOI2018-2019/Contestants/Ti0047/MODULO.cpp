#include <bits/stdc++.h>
#define task "MODULO"
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORL(i,a,b) for(int i=a;i<b;++i)
#define ll long long
#define fi first
#define se second
using namespace std;
ll a,b,n,k,m,p1,p2,cnt;
pair< ll , int > c[1050000];
void input()
{
    cin >> a >> b >> n >> k;
    m=1LL<<n;
    p1=n>>1;
    p2=n-p1;
}
void process()
{
    FORL(state,0,(1<<p1))
    {
        ll r=0;
        FORL(i,0,p1)
            {
                r*=10;
                if(state&(1<<i)) r+=b;
                else r+=a;
                r%=m;
            }

        FORL(i,0,p2)
            {
                r*=10;
                r%=m;
            }
        c[++cnt]= pair< ll , int >( r,state );
    }
    sort(c+1,c+cnt+1);
    FORL(state,0,(1<<p2))
    {
        ll r=0;
        FORL(i,0,p2)
            {
                r*=10;
                if(state&(1<<i)) r+=b;
                else r+=a;
                r%=m;
            }
        r=k-r;
        if(r<0) r+=m;
        int pos=upper_bound(c+1,c+cnt+1,pair< ll , int >( r,0))-c;
        if(c[pos].fi==r)
            {
                FORL(i,0,p1)
                {
                    if(c[pos].se&(1<<i)) cout << b;
                    else cout << a;
                }
                FORL(i,0,p2)
                {
                    if(state&(1<<i)) cout << b;
                    else cout << a;
                }
                return;
            }
    }
    cout << -1;
}
int main()
{
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
    ios::sync_with_stdio(false);cin.tie(NULL);
    input();
    process();
    return 0;
}
