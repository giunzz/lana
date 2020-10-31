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

int n, ttl=0, A[mn], dp[mn], mi, ma, ANS=0;
vector <int> bet, wor;

main()
{
	freopen("ARRANGE.inp", "r", stdin);
	freopen("ARRANGE.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &A[i]);
		ttl+=A[i];
	}
	
	if (ttl%n==0)
	{
		int cor=ttl/n, owe=0, ans=0;
		owe=cor-A[1];
		ans=abs(owe);
		
		for (int i=2; i<=n; ++i)
		{
			A[i]-=owe;
			A[i-1]=cor;
			owe=cor-A[i];
			ans+=abs(owe);
		}
		
		printf("%d", ans);
	}
	else
	{
		int ans=0, temp;
		mi=ttl/n;
		ma=mi+1;
		for (int i=1; i<n; i++)
		{
			cerr<<"cough";
			if (A[i]<mi)
			{
				temp=mi-A[i];
				A[i]+=temp;
				A[i+1]-=temp;
				ans+=temp;
			}
			else if (A[i]>ma)
			{
				temp=ma-A[i];
				A[i]-=temp;
				A[i+1]+=temp;
				ans+=temp;
			}
		}
	//	cerr<<"\n";
	
		int ptr=n-1;
		while (A[n]>ma)
		{
			if (A[ptr]==mi)
			{
				A[n]--;
				A[ptr]++;
				ans+=(n-ptr);
			}
			ptr--;
		}
		
		ptr=n-1;
		while (A[n]<mi)
		{
			if (A[ptr]==ma)
			{
				A[n]++;
				A[ptr]--;
				ans+=(n-ptr);
			}
			ptr--;
		}
		printf("%d", ans);
	}
}
