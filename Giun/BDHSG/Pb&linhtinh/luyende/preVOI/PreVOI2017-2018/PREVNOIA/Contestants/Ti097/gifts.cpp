#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, k, a[2000005];
ll sum[2000005],l[2000005],r[2000005];
int main(){
	freopen("gifts.inp","r",stdin);
	freopen("gifts.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) 
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		sum[i] = sum[i-1] + a[i];
		if (i >= k)	l[i] = max(l[i-1], sum[i] - sum[i-k]);
	}
	memset(sum,0,sizeof(sum));
	for(int i=n;i>=1;i--){
		sum[i] = sum[i+1] + a[i];
		if (i <= n-k+1) r[i] = max(r[i+1], sum[i] - sum[i+k]); 
	}
	ll ans = (ll)1e18;
	for(int i=1;i<=n-k+1;i++){
		ans= min(ans, max(l[i-1], r[i+k]));
	}
	cout << ans;
}
