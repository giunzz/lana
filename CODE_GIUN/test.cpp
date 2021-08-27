#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;
const int dx[]={-1,0,1,0};
      int dy[]={0,1,0,-1};
 
int m,n,h[1010][1010],a[1010][1010];
vector < pair<int,int> > p[1000100];
 
void bfs(int x,int y,int val)
{
	queue < pair<int,int> > q;
	h[x][y]=val;
	q.push(make_pair(x,y));
	while (!q.empty())
	{
		x=q.front().first; y=q.front().second;
		q.pop();
		for (int i=0;i<4;i++)
		{
			int xx=x+dx[i],yy=y+dy[i];
			if (!h[xx][yy] && a[xx][yy]<=val)
			{
				h[xx][yy]=val;
				q.push(make_pair(xx,yy));
			}
		}
	}
}
 
int isBorder(int x,int y)
{
	for (int i=0;i<4;i++)
		if (h[x+dx[i]][y+dy[i]]) return 1;
	return 0;
}
 
int main()
{
	freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
	memset(h,-1,sizeof(h));
	cin >> m >> n;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&a[i][j]), p[a[i][j]].push_back(make_pair(i,j)), h[i][j]=0;
	for (int i=1;i<=1000000;i++)
		for (int j=0;j<int(p[i].size());j++)
		{
			int x=p[i][j].first,y=p[i][j].second;
			if (!h[x][y] && isBorder(x,y)) bfs(x,y,a[x][y]);
		}
	for (int i = 1 ; i <= m ; i++)
    {
        for (int j = 1 ; j <= n ; j++) cerr << h[i][j] << " ";
        cerr << endl;
    }
	long long ans=0;
	for (int i=2;i<m;i++)
		for (int j=2;j<n;j++)
			ans+=max(0,h[i][j]-a[i][j]);
	cout << ans << endl;
}