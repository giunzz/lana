#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define Name "MINSUM"
#define BIT(i,x) ((x >> i ) & 1)
using namespace std;
const ll oo = 1e18;
template<class T> int chkmin(T &a , const T b) {return (a > b) ? a = b , 1 : 0;}
ll GCD(ll x , ll y)
{
    if(!y) return x;
    ll r = x % y;
    while(1)
	{
        x = y;
        y = r;
        if(!y) break;
        r = x % y;
	}
	return x;
}
ll a ,  b;
void sub_1()
{
	ll x , y , s = 1e18;
    ll t = a * b;
    for(int i = 1 ; i <= t ; ++i) if(!(t % i))
	{
        ll tmp = GCD(i , t / i);
        if(chkmin(s, (i / tmp) + ((t / i) / tmp)))
		{
			x = i / tmp;
			y = (t / i) / tmp;
		}
	}
	printf("%lld %lld\n",x , y);
}
map<int,int> p1;
void sub_2()
{
	p1.clear();
    ll x = sqrt(a);
    for(int i = 2 ; i <= x ; ++i)
	{
		int cnt = 0;
        if(a % i == 0)
		{
			while(a % i == 0) {a /= i;cnt++;}
            if((cnt & 1) && p1.find(i) == p1.end()) p1[i] = 1;
		}
		x = sqrt(a);
	}
	if(a > 1) if(p1.find(a) == p1.end()) p1[a] = 1;
	x = sqrt(b);
    for(int i = 2 ; i <= x ; ++i)
	{
		int cnt = 0;
        if(b % i == 0)
		{
			while(b % i == 0) {b /= i;cnt++;}
			if((cnt & 1)) p1[i]++;
		}
		x = sqrt(b);
	}
    if(b > 1)
	{
		p1[b]++;

    }
    int n = 0;
	vector<pair<int,int> > p2(p1.begin() , p1.end());
	n = p2.size();
    ll y;
    ll ans = oo;
    for(int i = 0 ; i < (1 << n) ; ++i)
	{
        a = b = 1;
		for(int j = 0 ; j < n ; ++j)
		{
			if(p2[j].second > 1) continue;
            if(BIT(j,i)) a *= p2[j].first;
            else b *= p2[j].first;
		}
		if(chkmin(ans , a + b)) {x = a , y = b;}
	}
	printf("%lld %lld\n",x , y);
}

int main()
{
    freopen(Name".inp","r",stdin);
    freopen(Name".out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
        scanf("%lld%lld",&a,&b);
        if(a <= 50 && b <= 50) sub_1();
		else sub_2();
	}
    return 0;
}
