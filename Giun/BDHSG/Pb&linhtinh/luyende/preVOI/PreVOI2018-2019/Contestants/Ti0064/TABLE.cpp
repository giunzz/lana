#include<bits/stdc++.h>

using namespace std;

#define X   first
#define Y   second

const int   N   = 301;

typedef unsigned int    uint;
typedef long long       ll;
typedef pair<ll,uint>   ii;

ii  operator + (ii a,ii b)  {
	return  ii(max(a.X,b.X),a.Y * (a.X >= b.X) + b.Y * (b.X >= a.X));
}

int m, n, k;
int a[N][N];
ii  f1[N][N];
ii  f2[N][N];

ll  calc(int l,int u,int r,int d)   {
	for(int i = l ; i <= r ; ++i)
	for(int j = u ; j <= d ; ++j)   {
		f1[i][j] = ii(0,0);
		if (i > l)  f1[i][j] = f1[i][j] + f1[i - 1][j];
		if (j > u)  f1[i][j] = f1[i][j] + f1[i][j - 1];
		f1[i][j].X += a[i][j];
		if (!f1[i][j].Y)    f1[i][j].Y = 1;
	}
	for(int i = r ; i >= l ; --i)
	for(int j = d ; j >= u ; --j)   {
		f2[i][j] = ii(0,0);
		if (i < r)  f2[i][j] = f2[i][j] + f2[i + 1][j];
		if (j < d)  f2[i][j] = f2[i][j] + f2[i][j + 1];
		f2[i][j].X += a[i][j];
		if (!f2[i][j].Y)   f2[i][j].Y = 1;
	}
	ll  ans = f1[r][d].X;
	for(int x = l + u + 1 ; x < r + d ; ++x)    {
		int P = 0;
		for(int y = l ; y <= r ; ++y)   {
			if (x - y < u || x - y > d) continue;
			ii  cur = ii(f1[y][x - y].X + f2[y][x - y].X - a[y][x - y],f1[y][x - y].Y * f2[y][x - y].Y);
			if (cur == f1[r][d])    {
				P = y;
				break;
			}
		}
		if (!P) continue;
		ll  cur = 0;
		for(int y = l ; y <= r ; ++y)   {
			if (x - y < u || x - y > d) continue;
			if (y == P) continue;
			cur = max(cur,f1[y][x - y].X + f2[y][x - y].X - a[y][x - y]);
		}
		ans = min(ans,cur);
	}
	return  ans;
}

int main()  {
	
	freopen("TABLE.inp","r",stdin);
	freopen("TABLE.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	
	for(int i = 1 ; i <= n ; ++i)
	for(int j = 1 ; j <= m ; ++j)
		scanf("%d",&a[i][j]);
	
	while(k--)  {
		int l, u, r, d;
		scanf("%d%d%d%d",&l,&u,&r,&d);
		printf("%lld\n",calc(l,u,r,d));
	}
}
/*
3 4 2
5 2 4 2
3 2 6 8
7 8 9 3
1 1 3 4
1 2 2 4
*/

