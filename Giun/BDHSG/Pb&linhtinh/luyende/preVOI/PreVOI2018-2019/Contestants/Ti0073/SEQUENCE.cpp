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
#define FLN "sequence"
#define pii pair <int, int>
#define XX first
#define YY second

int m, n, k;
vector <int> A[3005], B[3005];

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
	A[m].assign(m, 0);
	B[n].assign(n, 0);
	for (int i=0; i<m; i++) cin>>A[m][i];
	for (int j=0; j<n; j++) cin>>B[n][j];
	
	for (int i=m; i>0; i--)
	{
		int r=A[i].size()-1;
		for (int j=0; j<A[i].size(); j++)
		{
			if (j<A[i].size()-1)
			{
				if (A[i][j]>A[i][j+1]) 
				{
					r=j;
					break;
				}
			}
		}
		A[i-1]={};
		for (int j=0; j<A[i].size(); j++) if (j!=r) A[i-1].push_back(A[i][j]);
	}
	for (int i=n; i>0; i--)
	{
		int r=B[i].size()-1;
		for (int j=0; j<B[i].size(); j++)
		{
			if (j<B[i].size()-1)
			{
				if (B[i][j]>B[i][j+1]) 
				{
					r=j;
					break;
				}
			}
		}
		B[i-1]={};
		for (int j=0; j<B[i].size(); j++) if (j!=r) B[i-1].push_back(B[i][j]);
	}
	
	vector <int> ans;
	ans.assign(k, inf);
	for (int i=0; i<=m; i++)
	{
		int j=k-i;
		if (j<0 || j>n) continue;
		vector <int> a=A[i], b=B[j], ret={};
		a.push_back(inf), b.push_back(inf);
		
		int p1=0, p2=0;
		while (p1<a.size()-1 || p2<b.size()-1)
		{
//			cerr<<i<<" "<<j<<" "<<p1<<" "<<p2<<" ";
			if (a[p1]<b[p2])
			{
				ret.push_back(a[p1]);
				p1++;
			}
			else if (a[p1]>b[p2])
			{
				ret.push_back(b[p2]);
				p2++;
			}
			else
			{
				int q=1;
				while (1)
				{
					if (a[p1+q]!=b[p2+q]) break;
					if (a[p1+q]>a[p1]) break;
//					if (a[p1+q]==inf || b[p2+q]==inf) break;
					q++;
				}
			//	cerr<<q<<" ";
				if (a[p1+q]<b[p2+q]) 
				{
					for (int l=0; l<q; l++) ret.push_back(a[p1+l]);
					p1+=q;
				}
				else 
				{
					for (int l=0; l<q; l++) ret.push_back(b[p2+l]);
					p2+=q;
				}
			}
	//		cerr<<"\n";
		}
		for (int ii=0; ii<k; ii++)
		{
			if (ret[ii]<ans[ii]) 
			{
				ans=ret;
				break;
			}
			else if (ret[ii]>ans[ii]) break;
		}
	}
	for (int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/

