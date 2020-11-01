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
#define mn 100005
#define mod 1000000009
#define FLN "ICECREAM"
#define pii pair <int, int>
#define XX first
#define YY second

int dprev[305][605][305];

int n, MMAX, M1, M2, M3;

signed main()
{
#ifdef FLN
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>MMAX>>M1>>M2>>M3;
	int Lim2=MMAX, Lim3=MMAX;
	if (M2>300) 
	{
		Lim2-=M2-300;
		M2=300;
	}
	
	Lim3=min(Lim3-M3, (int)300);
	M3=0;
	Lim2=min(Lim2, (int)600);
	int ttl=M1+M2*2+M3*4;
	dprev[0][M2][M3]=1;
	
	int ans=0;
	for (int i=0; i<n; i++)
	{
		ttl++;
		for (int j=0; j<=Lim2; j++) for (int k=0; k<=Lim3; k++) if (dprev[i][j][k]!=0)
		{
			if (ttl-j*2-k*4<=MMAX) dprev[i+1][j][k]=(dprev[i+1][j][k]+dprev[i][j][k])%mod; //50 cents
			if (ttl-(j+1)*2-k*4>=0 && j<Lim2) dprev[i+1][j+1][k]=(dprev[i+1][j+1][k]+dprev[i][j][k])%mod;
			if (j>0 && ttl-(j-1)*2-(k+1)*4>=0 && k<Lim3) dprev[i+1][j-1][k+1]=(dprev[i+1][j-1][k+1]+dprev[i][j][k])%mod;
			else if (ttl-j*2-(k+1)*4>=0 && k<Lim3) dprev[i+1][j][k+1]=(dprev[i+1][j][k+1]+dprev[i][j][k])%mod;
		}
		
	}
	for (int i=0; i<605; i++) for (int j=0; j<305; j++)
	{
		ans=(ans+dprev[n][i][j])%mod;
	}
	cout<<ans;
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/

