#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
#define FRE freopen("liondance.inp","r",stdin),freopen("liondance.out","w",stdout)
using namespace std;
const int maxn=4000;
const int maxm=1e9+1;
int n,m,l[maxn+4],r[maxn+4],ans[maxn+4][maxn+4],chotl[maxn+4],chotr[maxn+4];
vector<int> res,co[maxn+1];

int main()
{
	IOS;
	FRE;
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>l[i];
	for (int i=1;i<=n;i++) cin>>r[i];
	ans[0][n]=0;ans[n][0]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (l[i]==r[j]) ans[i][j]=ans[i-1][j-1]+1;
			else ans[i][j]=max(ans[i][j-1],ans[i-1][j]);
		}
	}
	int dem=ans[n][n];
	cout<<dem<<"\n";
	for (int i=1;i<=dem;i++) chotl[i]=maxm,chotr[i]=maxm;
	for (int i=n;i>=1;i--)
	for (int j=n;j>=1;j--) {
		int q=ans[i][j];
	if (l[i]==r[j]) if ( q==dem||(i<chotl[q+1] && j<chotr[q+1]) ) 
	co[q].push_back(l[i]);
	if (i<chotl[q]) chotl[q]=i;
	if (j<chotr[q]) chotr[q]=j;
	}
	for (int i=1;i<=dem;i++) {
		int o=0;
		for (auto&x:co[i]) if (x>o) o=x;
	cout<<o<<' ';}
	return 0;
}
