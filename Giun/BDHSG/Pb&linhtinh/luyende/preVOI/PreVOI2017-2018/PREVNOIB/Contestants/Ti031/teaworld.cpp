#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
#define int long long
#define inf 9223372036854775799
#define mn 100005

int b[2200], t[2200];
int *block=b+1100, *tea=t+1100;

int m, n, k, xs;
int ball[2005];

main()
{
	freopen("teaworld.inp", "r", stdin);
	freopen("teaworld.out", "w", stdout);
	
	cin>>m>>n>>k;
	int x, y, z, r;
	
	for (int i=-1099; i<=1099; i++)
	{
		block[i]=0;
		tea[i]=0;
	}
	for (int i=1; i<=m; i++)
	{
		cin>>x>>y>>z>>r;
		block[x-r]=i;
		block[x+r]=i;
	}
	
	for (int i=1; i<=n; i++)
	{
		cin>>x>>y>>z>>r;
		tea[x]=r;
	}
	
	cin>>xs;
	
	int l=-500, E=0, rmv=0;
	r=xs;
	for (int i=1; i<=m; i++) ball[i]=0;
	
	for (int i=l; i<=r; i++)
	{
		if (block[i]>0) 
		{
			if (ball[block[i]]==0) rmv++;
			ball[block[i]]++;
		}
		E+=tea[i];
	}
	
	int ans=0;
	
	while (l<=xs)
	{
		if (block[l]==block[r] && block[l]>0) rmv--;
		if (rmv>k)
		{
			ball[block[l]]--;
			if (ball[block[l]]==0) rmv--;
			E-=tea[l];
			l++;
		}
		else
		{
			if (block[l]==block[r] && block[l]>0) rmv++;
			ans=max(ans, E);
			r++;
			if (block[r]>0) 
			{
				if (ball[block[r]]==0) rmv++;
				ball[block[r]]++;
			}
			E+=tea[r];
		}
	}
	
	cout<<ans;
}
