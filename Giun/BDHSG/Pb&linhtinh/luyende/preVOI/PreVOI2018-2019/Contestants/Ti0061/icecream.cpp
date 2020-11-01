#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli mod=1e9+9;
lli n, m, m1, m2, m3, M1, M2, M3, dp1[16][11][11][11], f[201][101][101], g[201][101][101], T[201][101][101];

void Sub1()
{
	dp1[0][m1][m2][m3]=1;
	for(int i=1;i<=n;i++)
	{
		for(int x=0;x<=m;x++)
		{
			for(int y=0;y<=m;y++)
			{
				for(int z=0;z<=m;z++)
				{
					if(dp1[i-1][x][y][z])
					{
						dp1[i-1][x][y][z]=dp1[i-1][x][y][z]%mod;
						if(x<m)
						{
							dp1[i][x+1][y][z]+=dp1[i-1][x][y][z];
						}
						if(x&&y<m)
						{
							dp1[i][x-1][y+1][z]+=dp1[i-1][x][y][z];
						}
						if(z<m)
						{
							if(x&&y)
							{
								dp1[i][x-1][y-1][z+1]+=dp1[i-1][x][y][z];
							}
							else
							{
								if(x>=3)
								{
									dp1[i][x-3][y][z+1]+=dp1[i-1][x][y][z];
								}
							}
						}
					}
					
				}
			}
		}
	}
	lli kq=0;
	for(int x=0;x<=m;x++)
	{
		for(int y=0;y<=m;y++)
		{
			for(int z=0;z<=m;z++)
			{
				kq+=dp1[n][x][y][z];
			}
		}
	}
	cout<<kq%mod;
}
void Pre()
{
	if(m1>=3*n)
	{
		M1=m-(m1-3*n);
		m1=3*n;
	}
	else
	{
		M1=m;
	}
	if(M1-m1>=n)
	{
		M1=m1+n;
	}
	if(m2>=n)
	{
		M2=m-(m2-n);
		m2=n;
	}
	else
	{
		M2=m;
	}
	if(M2-m2>=n)
	{
		M2=m2+n;
	}
	if(m3>=n)
	{
		M3=m-(m3-n);
		m3=n;
	}
	else
	{
		M3=m;
	}
	if(M3-m3>=n)
	{
		M3=m3+n;
	}
}
void Sub2()
{
	g[m1][m2][m3]=1;
	for(int i=1;i<=n;i++)
	{
		for(int x=0;x<=M1;x++)
		{
			for(int y=0;y<=M2;y++)
			{
				for(int z=0;z<=M3;z++)
				{
					f[x][y][z]=0;
				}
			}
		}
		for(int x=0;x<=M1;x++)
		{
			for(int y=0;y<=M2;y++)
			{
				for(int z=0;z<=M3;z++)
				{
					if(g[x][y][z])
					{
						g[x][y][z]=g[x][y][z]%mod;
						if(x<M1)
						{
							f[x+1][y][z]+=g[x][y][z];
						}
						if(y<M2&&x)
						{
							f[x-1][y+1][z]+=g[x][y][z];
						}
						if(z<M3)
						{
							if(x&&y)
							{
								f[x-1][y-1][z+1]+=g[x][y][z];
							}
							else
							{
								if(x>=3)
								{
									f[x-3][y][z]+=g[x][y][z];
								}
							}
						}
					}
				}
			}
		}
		swap(f, g);
	}
	lli kq=0;
	for(int x=0;x<=M1;x++)
	{
		for(int y=0;y<=M2;y++)
		{
			for(int z=0;z<=M3;z++)
			{
				kq+=g[x][y][z];
			}
		}
	}
	cout<<kq%mod;
}
int main()
{
	freopen("icecream.inp","r",stdin);
	freopen("icecream.out","w",stdout);
	cin>>n>>m>>m1>>m2>>m3;
	if(n<=15&&m<=10)
	{
		Sub1();
		return 0;
	}
	if(n<=50)
	{
		Pre();
		Sub2();
		return 0;
	}
}
