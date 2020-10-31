#include <bits/stdc++.h>
#define int long long
#define oo (LLONG_MAX/2)
using namespace std;

int a[1000007],s[1000007],sk[1000007],misk[1000007],mask[1000007];

signed main()
{
	freopen("gifts.inp","r",stdin);
	freopen("gifts.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i],s[i]=s[i-1]+a[i];
	for(int i=1;i<=n-k+1;i++) sk[i]=s[i+k-1]-s[i-1];
	for(int i=n-k+1;i>=1;i--) if(i==(n-k+1)) misk[i]=sk[i]; else misk[i]=max(misk[i+1],sk[i]);
	for(int i=1;i<=n-k+1;i++) if(i==1) mask[i]=sk[i]; else mask[i]=max(mask[i-1],sk[i]);
		int ans=oo;
	for(int i=1;i<=n-k+1;i++)
	{
		int l=max(0ll,i-k),r=min(i+k,n-k+2);
		int an=-oo;
		if(l>0) an=max(an,mask[l]);
		if(r<=n-k+1) an=max(an,misk[r]);
		if(an!=-oo) ans=min(ans,an);
	}
	cout << ans << "\n";
	return 0;
}