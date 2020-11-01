#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define u uu[t]
#define v vv[t]
#define p pp[t]
#define q qq[t]
using namespace std;

int m, n, k;
int a[305][305], dp[305][305];
int uu[305], pp[305], vv[305], qq[305];

void subtask1()
{
	for(int t=1; t<=k; t++)
	{
		int ans=1000000000000;
		queue<pair<int, int> > del;
		memset(dp, 0, sizeof(dp));
		for(int i=uu[t]; i<=pp[t]; i++)
		{
			for(int j=vv[t]; j<=qq[t]; j++)
			{
				dp[i][j]=max(dp[i-1][j], dp[i][j-1])+a[i][j];
			}
		}
		int curi=pp[t], curj=qq[t];
		while(curi!=uu[t]&&curj!=vv[t])
		{
			if(dp[curi-1][curj]>dp[curi][curj-1])
			{
				del.push(mp(curi, curj));
				curi--;
			}
			else
			{
				del.push(mp(curi, curj));
				curj--;
			}
		}
		del.pop();
		while(del.size())
		{
			int deli=del.front().first, delj=del.front().second;
			del.pop();
			int temp=a[deli][delj];
			a[deli][delj]=-1000000000000;
			for(int i=uu[t]; i<=pp[t]; i++)
			{
				for(int j=vv[t]; j<=qq[t]; j++)
				{
					dp[i][j]=max(dp[i-1][j], dp[i][j-1])+a[i][j];
				}
			}
			ans=min(dp[pp[t]][qq[t]], ans);
			a[deli][delj]=temp;
		}
		cout<<ans<<endl;
	}
}

signed main()
{
	freopen("TABLE.INP", "r", stdin);
	freopen("TABLE.OUT", "w", stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1; i<=k; i++)
	{
		cin>>uu[i]>>vv[i]>>pp[i]>>qq[i];
	}
	subtask1();
}
