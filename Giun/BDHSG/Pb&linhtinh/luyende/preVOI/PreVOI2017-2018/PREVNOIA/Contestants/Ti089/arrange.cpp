//
//  main.cpp
//  ARRANGE.cpp
//
//  Created by QuangHuy on 12/2/17.
//  Copyright © 2017 QuangHuy. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <stack>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>

#define ll long long
#define ld long double
#define endl '\n'
#define maxN 100001
#define maxM 1000001
#define oo 1000000000000000001
#define Mod 1000000007
#define pii pair<ll,ll>
#define piii pair<ll,pii>
#define piiii pair<pii,pii>
#define fi first
#define se second
#define sefi se.fi
#define sese se.se
#define fifi fi.fi
#define fise fi.se

using namespace std;
ll n;
ll a[maxN];
ll sums(0);
ll Store2[2001][2001]; // for Sub2
ll Ans[2001][2001];// for Sub2
void Sub1()
{
	ll ans=0;
	ll Store=0;
	ll val =sums/n;
	for(int i=1;i<=n;i++)
	{
		Store+=a[i]-val;
		ans+=abs(Store);
	}
	cout<<ans;
}
void Sub2()
{
	fill_n(&Store2[0][0],sizeof(Store2)/sizeof(Store2[0][0]),oo);
	fill_n(&Ans[0][0],sizeof(Ans)/sizeof(Ans[0][0]),oo);
	Store2[0][0]=0;
	Ans[0][0]=0;
	ll val=sums/n;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			// TH1 cot i ko la max
			if(Store2[i-1][j]!=oo&& Ans[i-1][j]!=oo)
			{
				Store2[i][j]=Store2[i-1][j]+a[i]-val;
				Ans[i][j]=min(Ans[i][j],Ans[i-1][j]+abs(Store2[i][j]));
			}
			// TH2 cot i la max
			if(j>0&&Store2[i-1][j-1]!=oo&& Ans[i-1][j-1]!=oo)
			{
				Store2[i][j]=Store2[i-1][j-1]+a[i]-val-1;
				Ans[i][j]=min(Ans[i][j],Ans[i-1][j-1]+abs(Store2[i][j]));
			}
		}
	}
	cout<<Ans[n][sums-n*val];
}
void Enter()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sums+=a[i];
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("/Users/quanghuy/Desktop/Input.inp","r", stdin);
	//freopen("/Users/quanghuy/Desktop/Output.out","w", stdout);
	freopen("ARRANGE.inp","r",stdin);
	freopen("ARRANGE.out","w",stdout);
	Enter();
	if(sums%n==0)
		Sub1();
	else
	{
		if(n<=2000)
			Sub2();
	}
}
