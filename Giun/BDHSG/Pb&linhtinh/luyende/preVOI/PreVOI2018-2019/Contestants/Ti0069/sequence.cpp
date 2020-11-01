#include <bits/stdc++.h>
using namespace std;

const int N=4005;
const int oo=1e9+7;
int n,m,k,a[N],b[N];
vector<int> res;

bool cmp(vector<int>a,vector<int>b)
{
	if(a.size()==0) return 0;
	if(b.size()==0) return 1;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	return a<b;
}

void slove(int x,int y)
{
	vector<int> up,down;
	int l=1;
	for(int i=1;i<=x;i++)
	{
		int pos=0;
		for(int j=l;j<=n-(x-i);j++) if(a[j]<a[pos]) pos=j;
		l=pos+1;
		up.push_back(a[pos]);
	}
	l=1;
	for(int i=1;i<=y;i++)
	{
		int pos=0;
		for(int j=l;j<=m-(y-i);j++) if(b[j]<b[pos]) pos=j;
		l=pos+1;
		down.push_back(b[pos]);
	}
	reverse(up.begin(),up.end());
	reverse(down.begin(),down.end());
	vector<int> buf;
	for(int i=1;i<=k;i++)
	{
		if(cmp(up,down)) buf.push_back(up.back()),up.pop_back(); else 
		buf.push_back(down.back()),down.pop_back();
	}
	if(res.size()==0 || buf<res) res=buf;
}

int main()
{
	freopen("sequence.inp","r",stdin);
	freopen("sequence.out","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	a[0]=b[0]=oo;
	for(int x=0;x<=k;x++)
	{
		int y=k-x;
		if(x<=n && y<=m) slove(x,y);
	}
	for(int x:res) cout<<x<<" ";
} 