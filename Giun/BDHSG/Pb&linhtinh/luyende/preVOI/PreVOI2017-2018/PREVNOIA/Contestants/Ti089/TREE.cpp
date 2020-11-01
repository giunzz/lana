//
//  main.cpp
//  TREE.cpp
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
#define maxN 5001
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
vector<ll> f[maxN];
ll father[maxN];
ll numChil[maxN];
vector<ll> ans[maxN];
vector<ll> Chil[maxN];
void DFS(ll u)
{
	if(f[u].size()==1)// U == leaf
	{
		ans[u].push_back(abs(a[u]));// so buoc de chuyen a[u] thanh 0
		ans[u].push_back(abs(a[u]-1));// so buoc de chuyen a[u] thanh 1
		numChil[u]=1;
		return;
	}
	for(int i=0;i<f[u].size();i++)
	{
		ll v=f[u][i];
		if(father[v]==0)
		{
			father[v]=u;
			Chil[u].push_back(v);
			DFS(v);
			numChil[u]+=numChil[v];
		}
	}
	if(Chil[u].size()==1)// U co 1 con
	{
		ll v= Chil[u][0];
		for(int i=0;i<=numChil[u];i++)
			ans[u].push_back(abs(a[u]-i)+ans[v][i]);
	}
	if(Chil[u].size()==2)// U co 2 con
	{
		ll v=Chil[u][0];
		ll w=Chil[u][1];
		for(int i=0;i<=numChil[u];i++)
		{
			ll val=oo;
			for(int j=0;j<=numChil[v];j++)
			{
				if(i-j>=0&& i-j<=numChil[w])
					val=min(val,abs(a[u]-i)+ans[v][j]+ans[w][i-j]);
			}
			ans[u].push_back(val);
		}
	}
}
void Solve()
{
	fill_n(&father[0],sizeof(father)/sizeof(father[0]),0);
	fill_n(&numChil[0],sizeof(numChil)/sizeof(numChil[0]),0);
	father[1]=-1;
	DFS(1);
	ll finalans=oo;
	for(int i=0;i<=numChil[1];i++)
		finalans=min(finalans,ans[1][i]);
	cout<<finalans;
	/*
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<"Node "<<i<<" "<<numChil[i]<<endl;
		for(int j=0;j<=numChil[i];j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	*/
}
void Enter()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
	{
		ll u,v;
		cin>>u>>v;
		f[u].push_back(v);
		f[v].push_back(u);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("/Users/quanghuy/Desktop/Input.inp","r", stdin);
	//freopen("/Users/quanghuy/Desktop/Output.out","w", stdout);
	freopen("TREE.inp","r",stdin);
	freopen("TREE.out","w",stdout);
	Enter();
	Solve();
}
