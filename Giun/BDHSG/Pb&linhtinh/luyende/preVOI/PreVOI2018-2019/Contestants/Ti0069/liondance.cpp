#include <bits/stdc++.h>
using namespace std;

const int N=4e3+7;
int n,del,l[N],r[N],dp[N][N];
pair<int,int> trace[N][N];

bool fix(vector<int> &buf)
{
	int l=0;
	for(int i=0;i<buf.size();i++)
	{
		bool flag=0;
		for(int j=l+1;j<=n;j++) 
			if(r[j]==buf[i])
			{
				flag=1;
				l=j;
				break;
			}
		if(flag==false) return flag;
	}
	return true;
}

void sub1()
{
	vector<int> res;
	for(int i=0;i<(1<<n);i++)
	{
		vector<int> buf;
		for(int j=0;j<n;j++) if((i>>j)&1) buf.push_back(l[j+1]);
		if(fix(buf))
		{
			if(res.size()==buf.size() && res<buf) res=buf;
			if(res.size()<buf.size()) res=buf;
		}
	}
	cout<<res.size()<<"\n";
	for(int x:res) cout<<x<<" ";
}

void sub2()
{
	l[0]=r[0]=-1;
	for(int i=n;i>=0;i--)
		for(int j=n;j>=0;j--)
			if(l[i]==r[j])
			{
				dp[i][j]=1;
				for(int ii=i+1;ii<=n;ii++)
					for(int jj=j+1;jj<=n;jj++)
						if(l[ii]==r[jj] && (abs(l[i]-l[ii])<=del || l[i]==-1)) 
						{
							if(dp[i][j]<dp[ii][jj]+1)
							{
								dp[i][j]=dp[ii][jj]+1;
								trace[i][j]=make_pair(ii,jj);
							} else 
							if(dp[i][j]==dp[ii][jj]+1 && l[trace[i][j].first]<l[ii]) trace[i][j]=make_pair(ii,jj);
						}
			}
	int u=0,v=0,k=dp[0][0];
	vector<int> res;
	while(k--)
	{
		res.push_back(l[u]);
		int x=u,y=v;
		u=trace[x][y].first;
		v=trace[x][y].second;
	}
	cout<<res.size()-1<<'\n';
	for(int i=1;i<res.size();i++) cout<<res[i]<<" ";
}

int main()
{
	freopen("liondance.inp","r",stdin);
	freopen("liondance.out","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>del;
	for(int i=1;i<=n;i++) cin>>l[i];
	for(int i=1;i<=n;i++) cin>>r[i];
	if(n<=20) sub1(); else sub2();
}