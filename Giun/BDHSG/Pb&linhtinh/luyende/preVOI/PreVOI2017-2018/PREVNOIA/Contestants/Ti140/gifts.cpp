#include <bits/stdc++.h>
using namespace std;
#define ft(i,x,y) for (int i = x; i <= y; i++)
const int maxn = 1e6+3;
int n,k;
long long a[maxn],s[maxn],ans,res;
long long st[4*maxn];
void Enter()
{
    scanf("%d%d",&n,&k);
    s[0] = 0;
    ft(i,1,n)
    {
        scanf("%lld",&a[i]);
        s[i] = s[i-1] + a[i];
    }
    ft(i,1,n) a[i] = s[i];
    ft(i,k,n) s[i] = s[i] - a[i-k];
}
void Build(int id, int ll, int rr)
{
    if (ll == rr)
    {
        st[id] = s[ll];
        return;
    }
    int mm = (ll + rr)/2;
    Build(id*2,ll,mm);
    Build(id*2+1,mm+1,rr);
    st[id] = max(st[id*2],st[id*2+1]);
}
void Get(int id, int ll, int rr, int u, int v)
{
    if (ll > v || rr < u) return;
    if (u <= ll && rr <= v)
    {
        res = max(res,st[id]);
        return;
    }
    int mm = (ll + rr)/2;
    Get(id*2,ll,mm,u,v);
    Get(id*2+1,mm+1,rr,u,v);
}
void Solve()
{
    Build(1,1,n);
    ans = 1e15;
    ft(i,k,n)
    {
        res = 0;
        if (i - k >= k) Get(1,1,n,k,i-k);
        if (n - i >= k) Get(1,1,n,i+k,n);
        ans = min(ans,res);
    }
    cout<<ans;
}
int main()
{
    freopen("gifts.inp","r",stdin);
    freopen("gifts.out","w",stdout);
    Enter();
    Solve();
}
