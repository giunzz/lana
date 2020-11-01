//
//  main.cpp
//  TEAWORLD.cpp
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
#define maxN 16
#define maxM 2001
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
ll m,n,k;
struct Poi
{
	ll x,y,z,w;
};
Poi Ball[maxM];
Poi TeaShop[maxN];
Poi PVH;
bool Shop[maxN];
ll cntCheck(0);
ll p[maxM];
ll Ans(-1);

bool Cross(Poi A,Poi B, Poi C)
{
	if(A.x>B.x)
		swap(A,B);

	if(B.x<C.x-C.w||A.x>C.x+C.w)
		return false;
	if(A.x<C.x-C.w&&C.x+C.w<B.x)
		return true;
	if((A.x>=C.x-C.w&&A.x<=C.x+C.w)==(B.x>=C.x-C.w&&B.x<=C.x+C.w))
		return false;
	else
		return true;
}
void Check()
{
	cntCheck++;
	ll cntBall=0;
	ll val=0;
	for(int i=1;i<=n;i++)
		if(Shop[i])
			val+=TeaShop[i].w;
	for(int i=1;i<=n;i++)
	{
		if(Shop[i])
		{
			for(int j=1;j<=m;j++)
			{
				if(p[j]!=cntCheck)
				{
					if(Cross(PVH,TeaShop[i],Ball[j]))
					{
						p[j]=cntCheck;
						cntBall++;
					}
				}
			}
		}
	}
	if(cntBall<=k)
		Ans=max(Ans,val);
}
void Quaylui(ll u,int x)
{
	if(u==n+1)
		return;
	for(int i=x;i<=n;i++)
	{
		Shop[i]=true;
		Check();
		Quaylui(u+1,i+1);
		Shop[i]=false;
	}
}
void Solve()
{
	fill_n(&Shop[0],sizeof(Shop)/sizeof(Shop[0]),false);
	fill_n(&p[0],sizeof(p)/sizeof(p[0]),0);
	Quaylui(1,1);
	cout<<Ans;
}
void Enter()
{
	cin>>m>>n>>k;
	for(int i=1;i<=m;i++)
		cin>>Ball[i].x>>Ball[i].y>>Ball[i].z>>Ball[i].w;
	for(int i=1;i<=n;i++)
		cin>>TeaShop[i].x>>TeaShop[i].y>>TeaShop[i].z>>TeaShop[i].w;
	cin>>PVH.x>>PVH.y>>PVH.z;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("/Users/quanghuy/Desktop/Input.inp","r", stdin);
	//freopen("/Users/quanghuy/Desktop/Output.out","w", stdout);
	freopen("TEAWORLD.inp","r",stdin);
	freopen("TEAWORLD.out","w",stdout);
	Enter();
	Solve();
}
