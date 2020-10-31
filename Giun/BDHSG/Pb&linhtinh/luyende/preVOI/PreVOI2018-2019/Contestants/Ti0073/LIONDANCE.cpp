#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<queue>
using namespace std;
#define int long long
#define mn 100005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "liondance"
#define pii pair <int, int>
#define XX first
#define YY second

int n, d, L[4005], R[4005];

bool sub1()
{
	return (n<=20);
}

vector <int> Vec={}, ans={};

void check()
{
	int p1=0;
	for (int i=0; i<Vec.size(); i++)
	{
		if (i>0) if (abs(Vec[i]-Vec[i-1])>d) return;
		p1++;
		while (p1<=n)
		{
			if (R[p1]==Vec[i]) break;
			p1++;
		}
		if (p1==n+1) return;
	}
	
	if (Vec.size()>ans.size()) 
	{
		ans=Vec;
		return;
	}
	else if (Vec.size()<ans.size()) return;
	
	for (int i=0; i<ans.size(); i++)
	{
		if (ans[i]<Vec[i])
		{
			ans=Vec;
			return;
		}
		else if (ans[i]>Vec[i]) return;
	}
}

void brute(int u)
{
	if (u==n) 
	{
		check();
		return;
	}
	
	brute(u+1);
	Vec.push_back(L[u+1]);
	brute(u+1);
	Vec.pop_back();
}

signed main()
{
#ifdef FLN
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>d;
	for (int i=1; i<=n; i++) cin>>L[i];
	for (int i=1; i<=n; i++) cin>>R[i];
	brute(0);
	cout<<ans.size()<<"\n";
	for (int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/

