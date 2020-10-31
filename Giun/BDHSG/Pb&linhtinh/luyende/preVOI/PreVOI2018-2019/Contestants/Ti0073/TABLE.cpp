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
#define FLN "table"
#define pii pair <int, int>
#define XX first
#define YY second

int n, m, k;
int A[305][305];
int dp[305][305];

bool sub1()
{
	return (n<=50 && m<=50 && k<=50);
}

int find_ans1(int u, int v, int p, int q)
{
	for (int i=u-1; i<=p; i++) for (int j=v-1; j<=q; j++) dp[i][j]=0;
	int ans=inf;
	for (int i=u; i<=p; i++) for (int j=v; j<=q; j++)
	{
		int t=A[i][j];
		if ((i==u && j==v) || (i==p && j==q)) ;
		else A[i][j]=-1;
		for (int i1=u; i1<=p; i1++) for (int j1=v; j1<=q; j1++) dp[i1][j1]=(A[i1][j1]==-1) ? 0 : max(dp[i1-1][j1], dp[i1][j1-1])+A[i1][j1];
		
		ans=min(ans, dp[p][q]);
		A[i][j]=t;
	}
	return ans;
}

bool sub2()
{
	return (n<=100 && m<=100 && k<=100);
}

pair <pii, pii> Q[305];

signed main()
{
#ifdef FLN
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>m>>n>>k;
	for (int i=1; i<=m; i++) for (int j=1; j<=n; j++) cin>>A[i][j];
	for (int i=1; i<=k; i++) cin>>Q[i].XX.XX>>Q[i].XX.YY>>Q[i].YY.XX>>Q[i].YY.YY;
	
	for (int i=1; i<=k; i++) cout<<find_ans1(Q[i].XX.XX, Q[i].XX.YY, Q[i].YY.XX, Q[i].YY.YY)<<"\n";
	
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/

