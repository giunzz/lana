/*huypheu
8 6
1 4 5 6 7 8
1 2 1
2 3 10
3 4 1
2 5 6
2 6 6
3 7 6
3 8 6
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

vector <pair<int,int> > v[500007];
bool okl;
int par[500007],tren[500007];
int tri[500007];
bool ok[500007];
int h[500007];
int p,q;
int len;

void dfs(int node)
{
	for(int i=0;i<v[node].size();i++)
	{
		int k=v[node][i].first;
		if(k!=par[node]) par[k]=node,tren[k]=v[node][i].second,h[k]=h[node]+tren[k],dfs(k);
	}
	return ;
}

void check(int node)
{
	if(okl==0) return ;
	multiset<int> se;
	for(int i=0;i<v[node].size();i++)
	{
		int k=v[node][i].first;
		if(k!=par[node])
		{
			check(k);
			if(okl==0) return ;
			if(tri[k]>-1) se.insert(tri[k]+tren[k]);
		}
	}
	if(!okl) return ;
	if(ok[node]) se.insert(0);
	while(se.size()>1)
	{
		if(*se.rbegin()>len)
		{
			okl=0;
			return ;
		}
		multiset<int>::iterator sub=se.end();
		sub--;
		se.erase(sub);
		int k=len-*sub;
		multiset<int >::iterator it=upper_bound(se.begin(),se.end(),k);
		if(it==se.begin())
		{
			okl=0;
			return ;
		}
		else
		{
			it--;
			se.erase(it);
		}
	}
	if(se.size()==0) tri[node]=-1; else tri[node]=*se.begin();
	return ;
}

signed main()
{
	freopen("bubbletea.inp","r",stdin);
	freopen("bubbletea.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=k;i++) 
	{
		int a;
		cin >> a,ok[a]=1;
	}
	for(int i=1;i<n;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b,c));
		v[b].push_back(make_pair(a,c));
	}
	dfs(1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(h[i]>=ans) p=i,ans=h[i]; 
	}
	q=p;
	for(int i=1;i<=n;i++) par[i]=0,h[i]=0;
	dfs(q);
	ans=0;
	for(int i=1;i<=n;i++)
	{
		if(h[i]>=ans) p=i,ans=h[i];
	}
	int l=0,r=ans;
	while(l<r)
	{
		int mid=(l+r)/2;
		len=mid;
		okl=1;
		check(q);
		if(!okl) l=mid+1; else r=mid;
	}
	cout << l << "\n";
	return 0;
}