#include<bits/stdc++.h>
#define ii pair <int, int >
#define f first
#define s second
using namespace std;
const int N=5e4+4;
int res,n,k,t[N],d[N];
vector <ii > ds[N];
bool vis[N];
queue <int > q;

void read()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("bubbletea.inp","r",stdin);
	freopen("bubbletea.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=k;++i) cin>>t[i];
	for (int i=1;i<=n;++i)
	{
		int x,y,z;
		cin>>x>>y>>z;
		ds[x].push_back(ii(y,z));
		ds[y].push_back(ii(x,z));
	}
}

void solve()
{
	res=2e9;
	sort(t+1,t+1+k);
	do
	{
		/*for (int i=1;i<=k;++i) cerr<<t[i]<<' ';
		cerr<<'\n';*/
		int tmp=0;
		for (int i=1;i<=n;i+=2)
		{
			memset(vis,false,sizeof(vis));
			memset(d,0,sizeof(d));
			q.push(t[i]);
			vis[t[i]]=true;
			while (!q.empty())
			{
				int u=q.front();
				if (u==t[i+1]) break;
				q.pop();
				for (int i=0;i<ds[u].size();++i)
				{
					int v=ds[u][i].f;
					if (vis[v]) continue;
					vis[v]=true;
					d[v]=d[u]+ds[u][i].s;
					q.push(v);
				}
			}
			while (!q.empty()) q.pop();
			tmp=max(tmp,d[t[i+1]]);
			//cerr<<tmp<<'\n';
		}
		res=min(res,tmp);
	} while (next_permutation(t+1,t+1+k));
	cout<<res;
}

int main()
{
	read();
	if (k<=10) solve();
		else cout<<-1;
}