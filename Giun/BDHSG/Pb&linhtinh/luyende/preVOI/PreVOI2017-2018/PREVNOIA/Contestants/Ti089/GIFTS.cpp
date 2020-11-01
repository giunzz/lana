//
//  main.cpp
//  GIFTS.cpp
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
#define maxN 1000001
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
ll n,t;
ll a[maxN];
ll T[maxN];
ll Sum=0;
ll p[maxN];
ll ans;
ll l[maxN*4];
ll r[maxN*4];
ll Val[maxN*4];
void MakeNode(ll id,ll left,ll right)
{
	l[id]=left;
	r[id]=right;
	if(l[id]==r[id])
	{
		Val[id]=p[left];
		return;
	}
	MakeNode(id*2,left,(left+right)/2);
	MakeNode(id*2+1,(left+right)/2+1,right);
	Val[id]=max(Val[id*2],Val[id*2+1]);
}
ll Query(ll id,ll left, ll right)
{
	if(l[id]>right||r[id]<left)
		return -1;
	if(l[id]>=left&&r[id]<=right)
		return Val[id];
	ll p= Query(id*2,left,right);
	ll q= Query(id*2+1,left,right);
	return  max(p,q);
}
void InitTree()
{
	MakeNode(1,1,n-t+1);
}
void Solve()
{
	InitTree();
	ans=oo;
	for(int i=1;i<=n-t+1;++i)
	{
		// Cam chon tu i den i+t-1
		ll T;
		T=-1;
		if(i>t)// Tam van chon duoc o ben phai
			T=max(T,Query(1,1,i-t));
		if(n-t+1>=i+t)
			T=max(T,Query(1,i+t,n-t+1));
		ans=min(ans,T);
	}
	cout<<ans;
}
void Enter()
{
	cin>>n>>t;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=n;++i)
	{
		Sum+=a[i];
		if(i>=t)
		{
			p[i-t+1]=Sum;
			Sum-=a[i-t+1];
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("/Users/quanghuy/Desktop/Input.inp","r", stdin);
	//freopen("/Users/quanghuy/Desktop/Output.out","w", stdout);
	freopen("GIFTS.inp","r",stdin);
	freopen("GIFTS.out","w",stdout);
	Enter();
	Solve();
}
