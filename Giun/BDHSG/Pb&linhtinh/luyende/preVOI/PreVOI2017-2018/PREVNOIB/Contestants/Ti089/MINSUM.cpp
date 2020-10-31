//
//  main.cpp
//  MINSUM.cpp
//
//  Created by QuangHuy on 12/3/17.
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
ll a,b;
ll n;
ll AnsA,AnsB;
ll GCD(ll u,ll v)
{
	while(v!=0)
	{
		ll w= u%v;
		u=v;
		v=w;
	}
	return u;
}
void Solve()
{
	ll m=GCD(a,b);
	a/=m;
	b/=m;
	AnsA=1;
	AnsB=1;
	for(int i=2;i<=sqrt(a);i++)
	{
		ll cnt=0;
		while(a%i==0)
		{
			a/=i;
			cnt++;
		}
		if(cnt%2==1)
			AnsA*=i;
	}
	for(int i=2;i<=sqrt(b);i++)
	{
		ll cnt=0;
		while(b%i==0)
		{
			b/=i;
			cnt++;
		}
		if(cnt%2==1)
			AnsB*=i;
	}
	cout<<AnsA*a<<" "<<AnsB*b<<endl;
}
void Enter()
{
	cin>>a>>b;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("/Users/quanghuy/Desktop/Input.inp","r", stdin);
	//freopen("/Users/quanghuy/Desktop/Output.out","w", stdout);
	freopen("MINSUM.inp","r",stdin);
	freopen("MINSUM.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		Enter();
		Solve();
	}
}
