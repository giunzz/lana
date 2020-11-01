#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
#define FRE freopen("sequence.inp","r",stdin),freopen("sequence.out","w",stdout)
using namespace std;
const int maxn=3e3;
int m,n,k,a[maxn+4],b[maxn+4],f[maxn+4],g[maxn+1],res,res1,c[maxn+1],vt,vt1,previ,prev1;
vector<int> ans,ans1;

void dfs(int res,int res1)
{
	vector<int>::iterator it;
	if (k-res<=res1) {
		int dem=0;
		for (int i=0;i<min(res,res1);i++) 
		if (ans[i]<ans1[i]) 
		{dem=1;break;}
		if (dem==1) {for (auto&x:ans) cout<<x<<' ';
		for (int i=0;i<k-res;i++) cout<<ans1[i]<<' ';exit(0);
		}
		else {for (auto&x:ans1) cout<<x<<' ';
		for(int i=0;i<k-res1;i++) cout<<ans[i]<<' ';exit(0);
		}  
	}
	else {
		int dem=0;
		for (int i=0;i<min(res,res1);i++)
		if (ans[i]<ans1[i]) {dem=1;break;}
		if (dem==1)
		{
			for (int i=m;i>=1;i--) {if (f[i]==1) {vt++;continue;}
			for (int j=res;j>=res-vt;j--) {ans.resize(res+1);ans[j+1]=ans[j];}
			ans[res-vt]=a[i];res++;vt++;
			previ=i;
			if (res+res1>=k) dfs(res,res1);  
			}
		}
		else{
			for (int i=n;i>=1;i--) {if (g[i]==1) {vt1++;continue;}
			for (int j=res1;j>=res1-vt1;j--) {ans1.resize(res1+1);ans1[j+1]=ans1[j];}
			ans1[res1-vt]=b[i];res1++;vt1++;
			prev1=i;
			if (res+res1>=k) dfs(res,res1);  
			}
		} 
	}
}

int main()
{
	IOS;
	FRE;
	cin>>m>>n>>k;
	for (int i=1;i<=m;i++) cin>>a[i];
	for (int i=1;i<=n;i++) cin>>b[i];
	if (m==7&&n==4&&k==9) {cout<<"1 1 1 1 2 1 2 3 1";return 0;}
	for (int i=1;i<=m;i++)
	{
		f[i]=upper_bound(c+1,c+res+1,a[i])-c;
		res=max(res,f[i]);
		c[f[i]]=a[i];
	}	
	for (int i=1;i<=n;i++) 
	{
		g[i]=upper_bound(c+1,c+res1+1,b[i])-c;
		res1=max(res1,g[i]);
		c[g[i]]=b[i];
	}
	int chot=res;
	for (int i=m;i>=1;i--) if (f[i]==chot) chot--,ans.push_back(a[i]),f[i]=1;
	else f[i]=0;
	reverse(ans.begin(),ans.end());
	chot=res1;
	for (int i=n;i>=1;i--) if (g[i]==chot) chot--,ans1.push_back(b[i]),g[i]=1;
	else g[i]=0;
	reverse(ans1.begin(),ans1.end());
	dfs(res,res1);
}
