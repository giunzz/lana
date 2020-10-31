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
#define fn "ARRANGE"    ///FILE_NAME_HERE
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

const int N=1e5+5;
const ll inf=1e15;
pll a[N];
int n;
ll s=0,ans=0;

void sub1()
{
    ll c = s/n;
    sort(a+1,a+1+n);
    int r=n;
    for(int i=1;i<=n;++i)
    {
        while(a[r].fir <= c)--r;
        if(a[i].fir < c)
        {
            ans+=Abs(a[r].sec - a[i].sec)*(c - a[i].fir);
            a[r].fir -= (c - a[i].fir);
        }
    }
    cout<<ans;
}

void sub2()
{
    set <pll> st;
    for(int i=1;i<=n;++i)
        st.insert(a[i]);
    while(true)
    {
        pll top=*st.begin();
        pll rtop=*st.rbegin();
        ll c=inf;
        if(Abs(top.fir - rtop.fir) <= 1)break;
        rep(st,it)
          if(it->fir == top.fir)
            minimize(c,Abs(it->sec - rtop.sec));
          else
            break;
        ans+=c;
        st.erase(st.begin());
        st.erase(st.find(rtop));
        ++top.fir,--rtop.fir;
        st.insert(top);
        st.insert(rtop);
    }
    cout<<ans;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i].fir,s+=a[i].fir,a[i].sec=i;
    if(s % n == 0)sub1();
    else if(n <= 2000)sub2();
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
