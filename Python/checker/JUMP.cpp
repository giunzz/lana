#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
const ll mxn = 1e5 + 7;
ll n , x , q, a[mxn], f[mxn] = {0}, d[mxn];

int main()
{
    giuncute;
    freopen("jump.inp","r",stdin);
    freopen("jump.out","w",stdout);
    // cin >> n >> q;
    scanf("%lld %lld", &n, &q);
    // for (int i = 1 ; i <= n ; i++) f[i] = 0;
    for (int i = 1 ; i <= n ; i++) scanf("%lld", &a[i]) ;
    reverse(a + 1, a + n + 1);
    ll top = 0;
    for (int i = 1; i <= n; i++)
    {
        while (top > 0 && a[d[top]] <= a[i]) --top ;
        if(top) f[i] = f[d[top]] + 1;
        d[++top] = i;
    }
    reverse(f + 1, f + n + 1);
    for (int i = 0 ; i < q ; i++){
        scanf("%lld", &x);
        printf("%lld\n", f[x]);
    }
}
