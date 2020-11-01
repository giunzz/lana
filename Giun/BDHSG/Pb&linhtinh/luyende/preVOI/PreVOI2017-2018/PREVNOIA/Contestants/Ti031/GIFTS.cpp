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

int n, k, A[mn*10];

signed main()
{
	freopen("GIFTS.inp", "r", stdin);
	freopen("GIFTS.out", "w", stdout);
	
//	cerr<<"adios";
	scanf("%d %d", &n, &k);
	for (int i=1; i<=n; ++i) scanf("%d", &A[i]);
	
	vector <pair <int, int> > V;
	
	int ptr=0;
	for (int i=1; i<=k; ++i) ptr+=A[i];
	V.push_back({ptr, 1});
	 
	for (int i=2; i<=n-k+1; ++i)
	{
		ptr-=A[i-1];
		ptr+=A[i+k-1];
		
		V.push_back({ptr, i});
	}
//	for (int i=0; i<V.size(); ++i) cerr<<V[i].first<<" "<<V[i].second<<"\n";
	
	sort(V.begin(), V.end());
	reverse(V.begin(), V.end());
	
//	
	int l=max((int)1, V[0].second-k+1), r=min(V[0].second+k-1, n-k+1);
	
	for (int i=1; i<V.size(); ++i)
	{
		l=max(l, V[i].second-k+1);
		r=min(r, V[i].second+k-1);
		
		if (l>r) 
		{
			printf("%d", V[i].first);
			return 0;
		}
	}
	
	cerr<<"++++";
}
