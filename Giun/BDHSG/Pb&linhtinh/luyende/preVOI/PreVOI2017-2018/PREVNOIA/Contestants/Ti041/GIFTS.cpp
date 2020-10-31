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
#define fn "GIFTS"    ///FILE_NAME_HERE
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

const int N=1e6+6;
const ll inf=1e15;
const int lg=20;
ll rmq[N][lg + 2],sum[N],a[N];
int n,k;
ll ans=inf;

ll query(int l,int r)
{
    int x=(int)log2(r - l + 1);
    return max(rmq[l][x],rmq[r - MASK(x) + 1][x]);
}

void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i)
        cin>>sum[i];
    for(int i=1;i<=n;++i)
        sum[i]+=sum[i-1];
    for(int i=1;i<=n-k+1;++i)
        a[i] = sum[i + k - 1] - sum[i - 1];
    for(int i=1;i<=n-k+1;++i)
        rmq[i][0]=a[i];
    for(int j=1;j<=lg;++j)
        for(int i=1;i + MASK(j) - 1<=n-k+1;++i)
          rmq[i][j] = max(rmq[i][j-1],rmq[i + MASK(j-1)][j-1]);
    for(int i=1;i<=n-k+1;++i)
    {
        bool flag1=true,flag2=true;
        ll maxx1=-inf,maxx2=-inf;
        if(i - k >= 1)
        {
            maxx1 = query(1,i - k);
            if(maxx1 > a[i])
                flag1=false;
        }
        if(i + k <= n - k + 1)
        {
            maxx2=query(i + k,n - k + 1);
            if(maxx2 > a[i])
                 flag2 = false;
        }
        if(flag1 and flag2)
            minimize(ans,max(maxx1,maxx2));
    }
    cout<<ans;
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
