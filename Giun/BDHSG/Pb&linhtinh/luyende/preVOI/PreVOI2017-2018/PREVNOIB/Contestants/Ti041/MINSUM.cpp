using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (c).size()
#define fn "MINSUM"    ///FILE_NAME_HERE
#define rep(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define rrep(c,it) for(__typeof((c).rbegin()) it=(c).rbegin();it!=(c).rend();++it)

template <class T,class U>
void maximize(T &x,U y)
{
    if(x < y)x=y;
}
template <class T,class U>
void minimize(T &x,U y)
{
    if(x > y)x=y;
}
template <class T>
T Abs(T x)
{
    return (x < (T)0 ? -x : x);
}
template <class T,class U,class V>
T addmod(T x,U y,V mod)
{
    return ((x + y)%mod + mod)%mod;
}
template <class T,class U,class V>
T submod(T x,U y,V mod)
{
    return ((x - y)%mod + mod)%mod;
}
template <class T,class U,class V>
T mulmod(T x,U y,V mod)
{
    return (ll)x*y%mod;
}
///---------------------------------------------------------END_TEMPLATE-------------------------------------------------------///

namespace task{

const ll maxVal = 1e9;
int T;

pll bfs(ll a,ll b)
{
    map <pll,bool> ma;
    queue <pll> q;
    q.push(mp(a,b));
    ma[mp(a,b)]=true;
    ll x=a,y=b;
    for(;sz(q);q.pop())
    {
        pll top=q.front();
        a=top.fir,b=top.sec;
        if(x + y > a + b)
            x=a,y=b;
        if(a >= maxVal or b >= maxVal)continue;
        for(ll i=1;i*i <= a;++i)
            if(a % i == 0 and b % i == 0)
        {
            if(!ma[mp(a/i,b/i)])
            {
                q.push(mp(a/i,b/i));
                ma[mp(a/i,b/i)]=true;
            }
            ll g=a/i;
            if(a % g == 0 and b % g == 0)
            {
                if(!ma[mp(a/g,b/g)])
                {
                    ma[mp(a/g,b/g)]=true;
                    q.push(mp(a/g,b/g));
                }
            }
        }
        for(ll i=1;i*i<=a;++i)
            if(a % i == 0)
        {
            if(!ma[mp(a/i,b*i)])
            {
                q.push(mp(a/i,b*i));
                ma[mp(a/i,b*i)]=true;
            }
            ll g=a/i;
            if(!ma[mp(a/g,b*g)])
            {
                ma[mp(a/g,b*g)]=true;
                q.push(mp(a/g,b*g));
            }
        }
        for(ll i=1;i*i<=b;++i)
            if(b % i == 0)
        {
            if(!ma[mp(a*i,b/i)])
            {
                ma[mp(a*i,b/i)]=true;
                q.push(mp(a*i,b/i));
            }
            ll g=b/i;
            if(!ma[mp(a*g,b/g)])
            {
                ma[mp(a*g,b/g)]=true;
                q.push(mp(a*g,b/g));
            }
        }
    }
    return mp(x,y);
}

void sub1(ll a,ll b)
{
    pll ans=bfs(a,b);
    cout<<ans.fir<<' '<<ans.sec<<'\n';
}

void solve()
{
    cin>>T;
    while(T -- )
    {
        ll a,b;
        cin>>a>>b;
        if(a <= 50 and b<=50)
            sub1(a,b);
        else
        {
            ll g = __gcd(a,b);
            cout<<a/g<<' '<<b/g<<'\n';
        }
    }
}}

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}
