#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define Name "ARRANGE"
using namespace std;
const int maxN = 1e5 + 190;
const ll oo = 1e13;
ll a[maxN] , s1 , k , f[2000 + 190][2000 + 190] , g[2000 + 190][2000 + 190] , base;
int n ;
ll Abs(ll a ) {return ((a < 0 ) ? -a : a);}
void sub_1()
{
	ll tmp = 0;
	ll ans = 0;
    for(int i = 1  ;i <= n ; ++i)
	{
		ans += Abs(tmp);
		tmp += (a[i] - (s1 / n));
	}
    printf("%lld",ans);
    exit(0);
}
void sub_2()
{
    k = (s1 - (s1 / n) * n);
	base = s1 / n;
    for(int i = 1 ; i <= n ; ++i) for(int j = 0 ; j <= k ; ++j) g[i][j] = f[i][j] = oo;
    for(int i = 1;  i <= n ; ++i)
	{
        int t = min(i ,(int) k);
        for(int j = 0 ; j <= t ; ++j)
		{
            if(Abs(f[i][j]) > Abs(f[i-1][j] + (a[i] - base))) f[i][j] = f[i-1][j] + (a[i] - base);
            if(j - 1 >= 0 && (Abs(f[i][j]) > Abs(f[i-1][j-1] + (a[i] - base - 1))) )
				f[i][j] = f[i-1][j-1] + (a[i] - base - 1);
            g[i][j] = min(g[i][j] ,g[i - 1][j] + Abs(f[i-1][j]));
            if(j - 1 >= 0) g[i][j] = min(g[i][j] , g[i - 1][j - 1] + Abs(f[i-1][j-1]));
		}
	}
    printf("%lld",g[n][k]);
}
int main()
{
    freopen(Name".inp","r",stdin);
    freopen(Name".out","w",stdout);
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; ++i) scanf("%lld",&a[i]);
    for(int i = 1 ; i <= n ; ++i) s1 += a[i];
    if(!(s1 % n)) sub_1();
    else sub_2();
    return 0;
}
