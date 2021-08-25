#include<stdio.h>
#include<algorithm>
#include<cmath>
#define ll long long
const ll oo = 1e18;
const ll maxn = 1e6 + 7;
const ll N = 2e5 + 7;
#pragma GCC optimize("Ofast")
using namespace std;
ll n , m , a[N] , cnt[maxn] = {0} , ans[maxn] , cur = 0 ;
ll block;

struct giun
{
    ll l , r , vt;
} q[maxn];

bool cmp(giun &A, giun &B)
{
    if (A.l / block != B.l / block) 
        return A.l / block < B.l / block;
    return A.r < B.r;
}
void up( const ll &x , const ll &val)
{
    cur -= 1LL * cnt[x] * cnt[x] * x;
    cnt[x] += val;
    cur += 1LL * cnt[x] * cnt[x] *x;
}
int main()
{
    scanf("%lld%lld", &n, &m);
    block = sqrt(n);
    for (int i = 1 ; i <= n ; i++) scanf("%lld",&a[i]);
    for (int i = 1 ; i <= m ; i++) scanf("%lld%lld", &q[i].l, &q[i].r), q[i].vt = i;
    sort (q + 1 , q + 1 + m , cmp);
    for (int i = q[1].l ; i <= q[1].r ; i++) up(a[i] , 1);
    ans[q[1].vt] = cur;
    for (int i = 2 ; i <= m ; i++)
    {
        ll l1 = q[i-1].l , l2 = q[i].l;
        ll r1 = q[i-1].r , r2 = q[i].r;
        if (l2 > l1)
            for (int j = l1 ; j < l2 ; j++) up(a[j] , -1);
        else         
            for (int j = l1 - 1 ; j >= l2 ; j--) up(a[j] , 1);
        if (r2 > r1)
            for (int j = r1 + 1 ; j <= r2 ; j++) up(a[j] , 1);
        else         
            for (int j = r1  ; j > r2 ; j--) up(a[j] , -1);
        ans[q[i].vt] = cur;
    }
    for (int i = 1 ; i <= m ; i++) printf("%lld\n" , ans[i]);
}