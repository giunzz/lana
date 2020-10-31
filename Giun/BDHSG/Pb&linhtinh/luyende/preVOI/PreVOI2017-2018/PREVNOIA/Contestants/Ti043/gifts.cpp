#include <bits/stdc++.h>
using namespace std;
ifstream fin("gifts.inp");
ofstream fo("gifts.out");
#define cin fin
#define cout fo
#define mp make_pair
#define pb push_back
#define fi first
#define se second
int n,k;
const int N=1000007;
long long a[N],sum[N],maxpre[N],maxsuf[N],ans=1e16;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=k;i<=n;i++){
		maxpre[i]=max(maxpre[i-1],sum[i]-sum[i-k]);
	}
	for(int i=n-k+1;i>=1;i--){
		maxsuf[i]=max(maxsuf[i+1],sum[i+k-1]-sum[i-1]);
	}
	for(int l=1;l<=n-k+1;l++){
		int r=l+k-1;
		ans=min(ans,max(maxpre[l-1],maxsuf[r+1]));
	}
	cout<<ans;
}
