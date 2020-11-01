#include <bits/stdc++.h>
#define pb push_back
#define ep emplace_back

using namespace std;

int a[3005], b[3005], n, m, k;
vector<int> da[3005], db[3005], use;

void __merge(int a,int b)
{
	vector<int> res;
	int ita=0, itb=0;
	for(int i=1; i<=k; i++)
	{
		if(ita==da[a].size()-1)
		{
			res.pb(db[b][itb]);
			itb++;
			continue;
		}
		else if(itb==db[b].size()-1)
		{
			res.pb(da[a][ita]);
			ita++;
			continue;
		}
		if(da[a][ita]>db[b][itb])
		{
			res.pb(db[b][itb]);
			itb++;
		}
		else
		{
			res.pb(da[a][ita]);
			ita++;
		}
	}
	for(int i=0; i<k; i++)
	{
		if(use[i]<res[i])
		{
			break;
		}
		else if(use[i]>res[i])
		{
			use=res;
			break;
		}
	}
}

signed main()
{
	freopen("SEQUENCE.INP", "r", stdin);
	freopen("SEQUENCE.OUT", "w", stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=k; i++)
	{
		use.pb(3001);
	}
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	for(int i=1; i<=m; i++)
	{
		cin>>b[i];
	}
	for(int i=1; i<=n; i++)
	{
		da[n].pb(a[i]);
	}
	da[n].pb(-1);
	for(int i=1; i<=m; i++)
	{
		db[m].pb(b[i]);
	}
	db[m].pb(-1);
	int taken=max(k-m, 0), takem=max(k-n, 0);
	int takemax=min(k, n);
	for(int i=n-1; i>=taken; i--)
	{
		for(int j=0; j<da[i+1].size()-1; j++)
		{
			if(da[i+1][j]>da[i+1][j+1])
			{
				for(int k=j+1; k<da[i+1].size(); k++)
				{
					da[i].pb(da[i+1][k]);
				}
				break;
			}
			else
			{
				da[i].pb(da[i+1][j]);
			}
		}
	}
	for(int i=m-1; i>=takem; i--)
	{
		for(int j=0; j<db[i+1].size()-1; j++)
		{
			if(db[i+1][j]>db[i+1][j+1])
			{
				for(int k=j+1; k<db[i+1].size(); k++)
				{
					db[i].pb(db[i+1][k]);
				}
				break;
			}
			else
			{
				db[i].pb(db[i+1][j]);
			}
		}
	}
	for(int i=taken; i<=takemax; i++)
	{
		__merge(i, k-i);
	}
	for(int i=0; i<k; i++)
	{
		cout<<use[i]<<" ";
	}
}
