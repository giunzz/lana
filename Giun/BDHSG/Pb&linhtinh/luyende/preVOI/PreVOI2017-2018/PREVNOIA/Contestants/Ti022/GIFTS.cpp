#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define Name "GIFTS"
using namespace std;
const int maxN = 1e6 + 190;
const ll oo = 1e18;
int n , k;
ll a[maxN] , s[maxN] , f[maxN] , g[maxN];
bool check_range(int i , int j)
{
    return (j + k - 1 < i || i + k - 1 < j);
}
ll get(int i)
{
	return (s[i + k - 1] - s[i - 1]);
}
void sub_1()
{
    ll ans =  oo;
    for(int i = 1 ; i <= n - k + 1 ; ++i)
	{
		ll tmp = -1;
        for(int j = 1 ; j <= n - k + 1 ; ++j)
		{
			if(!check_range(i,j)) continue;
			tmp = max(tmp , get(j));
		}
        ans = min(ans , tmp);
	}
	printf("%lld",ans);
	exit(0);
}
void sub_2()
{
    for(int i = 1; i <= n ; ++i)
		f[i] = max(f[i - 1] , get(i));
    for(int i = n - k + 1 ; i >= 1 ; --i)
		g[i] = max(g[i + 1] , get(i));
	ll tmp , ans = oo;
    for(int i = 1 ; i <= n - k + 1;  ++i)
	{
		tmp = 0;
        if(i - k > 0) tmp = max(tmp , f[i - k]);
        if(i + k <= n) tmp = max(tmp , g[i + k]);
        ans = min(ans , tmp);
	}
    printf("%lld",ans);
}
int main()
{
    freopen(Name".inp","r",stdin);
    freopen(Name".out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i = 1; i <= n ; ++i) scanf("%lld",&a[i]);
	for(int i = 1; i <= n ; ++i) s[i] = s[i - 1] + a[i];
	if(n <= 5000 ) sub_1();
    else sub_2();
    return 0;
}
