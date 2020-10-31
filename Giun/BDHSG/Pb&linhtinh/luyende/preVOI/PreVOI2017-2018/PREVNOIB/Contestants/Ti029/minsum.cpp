#include<bits/stdc++.h>
#define task "minsum"
#define ll long long
#define ff(i,a,b) for(int i=a; i<=b; ++i)
#define fd(i,a,b) for(int i=a; i>=b; --i)
#define rr(i,a,b) for(int i=a; i<b; ++i)
#define rd(i,a,b) for(int i=a; i>b; --i)
#define pb push_back
#define mp make_pair
using namespace std;

const int maxn=1E4+10;

int x, y, T;

int main()
{
	freopen(task".inp","r",stdin);
	freopen(task".out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&x,&y);
		int d=__gcd(x, y);
		x/=d, y/=d;
		for(int i=2; i*i<=x; ++i)if(x%(i*i)==0)
			while(x%(i*i)==0) x/=i*i;
		for(int i=2; i*i<=y; ++i)if(y%(i*i)==0)
			while(y%(i*i)==0) y/=i*i;
		printf("%d %d\n",x,y);
	}
	return 0;
}
