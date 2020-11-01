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
#define fn "TEAWORLD"    ///FILE_NAME_HERE
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

const int N=2e3+3;
int x[N],y[N],z[N],r[N];
int sx[N],sy[N],sz[N],se[N];
int a[N];
int dp[MASK(16)][N];
int n,k,m,xs,ys,zs;

bool insize(int l,int r,int x)
{
    return (l  <= x and x <= r);
}

int F(int mask,int cnt)
{
    if(cnt == k)return 0;
    if(~dp[mask][cnt])return dp[mask][cnt];
    int ret=0;
    for(int j=1;j<=n;++j)
        if(!BIT(mask,j - 1) and cnt + a[j] <= k)
    {
        int x = se[j] + F(mask|MASK(j-1),cnt + a[j]);
        maximize(ret,x);
    }
    return dp[mask][cnt] = ret;
}

bool check(int le,int ri,int i)
{
    return ((x[i] - r[i] <= le and le <= x[i] + r[i]) and (ri > x[i] + r[i] or ri < x[i] - r[i]))
                       or (((x[i] - r[i] <= ri and ri <= x[i] + r[i]) and (le > x[i] + r[i] or le < x[i] - r[i])))
                       or ((le > x[i] + r[i] or le < x[i] - r[i]) and ((ri > x[i] + r[i] or ri < x[i] - r[i])));
}

void sub1()
{
    for(int i=1;i<=n;++i)
    {
        int le = xs;
        int ri = sx[i];
        if(le > ri)swap(le,ri);
        int cnt=0;
        for(int j=1;j<=m;++j)
            if(insize(le,ri,x[j] + r[j]) or insize(le,ri,x[j] - r[j]))
                cnt+=check(le,ri,j);
        a[i]=cnt;
    }
    memset(dp,-1,sizeof(dp));
    int ans = F(0,0);
    for(int i=1;i<=n;++i)
        if(a[i] == k)
          maximize(ans,se[i]);
    int c=0;
    for(int i=1;i<=n;++i)
        if(!a[i] and a[i] == k)
          c+=se[i];
    maximize(ans,c);
    cout<<ans;
}

void solve()
{
    cin>>m>>n>>k;
    int cnt=0;
    for(int i=1;i<=m;++i)
    {
        cin>>x[i]>>y[i]>>z[i]>>r[i];
        cnt+=(y[i] == 0 and z[i] == 0);
    }
    for(int i=1;i<=n;++i)
    {
        cin>>sx[i]>>sy[i]>>sz[i]>>se[i];
        cnt+=(sy[i] == 0 and sz[i] == 0);
    }
    cin>>xs>>ys>>zs;
    if(cnt == n + m)sub1();
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
