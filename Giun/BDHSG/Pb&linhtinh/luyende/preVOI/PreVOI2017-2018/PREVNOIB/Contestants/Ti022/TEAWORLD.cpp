#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define Name "TEAWORLD"
#define BIT(i,x) ((x >> i) & 1)
#define ON(i,x) (x | (1 << i))
using namespace std;
const int maxM = 2000 + 1;
typedef pair<ll,ll> ii;
const int maxN = 15;
int dd[maxM], m , n , k  , vh , f[maxM][1 << maxN];
ii c[maxM] ,  p[maxN];
template<class T> T Abs(T a) {return (a < 0) ? -a : a;}
/*bool check(int a , int b)
{
    if(c[a].first < min(p[b].first, vh) || c[a].first > max(p[b].first , vh))
	{
        return (c[a].second > min(Abs(c[a].first - vh) , Abs(c[a].first - p[b].first)));
	}
	else
	{
        return (c[a].second < min(Abs(c[a].first - vh) , Abs(c[a].first - p[b].first)));
	}
}*/
int main()
{
	freopen(Name".inp","r",stdin);
	freopen(Name".out","w",stdout);
	/*scanf("%d%d%d",&m,&n,&k);
	int a, b,c,d;
    for(int i = 1 ; i <= m ; ++i)
	{
        scanf("%d%d%d%d",&a,&b,&c,&d);
        c[i] = ii(a,d);
	}
	for(int i = 1 ; i <= n ; ++i)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		p[i] = ii(a,d);
	}
	scanf("%d%d%d",&a,&b,&c);
    vh = a;
    for(int i = 1 ; i <= m ; ++i) for(int j = 1 ; j <= n ; ++j)
		if(check(i,j))
            dd[i] = ON(j - 1 , dd[i]);*/
	printf("0");
    return 0;
}
