#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ep emplace_back
#define mp make_pair

using namespace std;

int a[505], b[505], cntans=0;
vector<pair<int, int> > adj;
pair<int, int> ans[10005];
vector<int> use;

void check(int i)
{
	stack<int> sad;
	vector<int> res;
	sad.push(a[adj[i].first]);
	while(ans[i].second!=i)
	{
		sad.push(a[adj[ans[i].second].first]);
		i=ans[i].second;
	}
	while(sad.size())
	{
		res.pb(sad.top());
		sad.pop();
	}
	for(int i=0; i<cntans; i++)
	{
		if(use[i]>res[i])
		{
			break;
		}
		else if(use[i]<res[i])
		{
			use=res;
			break;
		}
	}
}

signed main()
{
	freopen("LIONDANCE.INP", "r", stdin);
	freopen("LIONDANCE.OUT", "w", stdout);
	int n, k;
	cin>>n>>k;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	for(int i=1; i<=n; i++)
	{
		cin>>b[i];
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(a[i]==b[j])
			adj.ep(i, j);
		}
	}
	for(int i=0; i<=adj.size(); i++)
	{
		int ita=adj[i].first, itb=adj[i].second;
		ans[i]=mp(1, i);
		for(int j=i-1; j>=0; j--)
		{
			if(abs(a[ita]-a[adj[j].first])<=k&&adj[j].first<ita&&adj[j].second<itb)
			{
				if(ans[j].first+1>ans[i].first||(ans[j].first+1==ans[i].first&&a[adj[ans[j].second].first]>a[adj[ans[i].second].first]))
				{
					ans[i]=mp(ans[j].first+1, j);
				}
			}
		}
		cntans=max(cntans, ans[i].first);
	}
	for(int i=1; i<=cntans; i++)
	{
		use.pb(-1);
	}
	for(int i=0; i<adj.size(); i++)
	{
		if(ans[i].first==cntans)
		{
			check(i);
		}
	}
	cout<<cntans<<endl;
	for(int i=0; i<use.size(); i++)
	{
		cout<<use[i]<<" ";
	}
}
