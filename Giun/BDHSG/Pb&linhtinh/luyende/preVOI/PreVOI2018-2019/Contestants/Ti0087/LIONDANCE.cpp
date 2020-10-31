#include <bits/stdc++.h>
#define int long long
#define MAXN 102
#define MOD 1000000007
#define sz(a) static_cast<long long>(a.size())
#define INF 2000000000000000000
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pp;
int n,delta,a[MAXN],b[MAXN];
vector <int> v[MAXN][MAXN]; int dp[MAXN][MAXN];
int dem=0; vector <int> ans; vector <int> wow;
void Upd(int x1,int x2){
	int i,j,k;
	for (i=0;i<dem;i++){
		if (ans[i]>v[x1][x2][i]) return;
		else if (ans[i]<v[x1][x2][i]){
			ans=v[x1][x2]; return;
		}
	}
}
void solve(){
	int i,j,k,l,val,tm;
	for (i=1;i<=n;i++){
		dp[i][0]=0;
		for (j=1;j<=n;j++){
			//v[i][j]=v[i][j-1];
			if (a[i]==b[j]){
				for (k=1;k<i;k++){
					if (abs(a[i]-a[k])<=delta){
						val=dp[k][j-1];
					if (v[k][val].size()>v[i][j].size()){
						v[i][j]=v[k][val];
					}
					else if (!v[k][val].empty()&&v[k][val].size()==v[i][j].size()){
						for (l=0;l<v[k][val].size();l++){
							if (v[k][val][l]>v[i][j][l]){
								v[i][j]=v[k][val]; break;
							}
							else if (v[k][val][l]<v[i][j][l]) break;
						}
					}
				}
				}
				v[i][j].pb(a[i]); val=dp[i][j-1];
			}
			if (v[i][j].size()>v[i][val].size()) dp[i][j]=j;
			else dp[i][j]=dp[i][j-1];
			tm=v[i][j].size();
			dem=max(dem,tm);
		}
	}
 	cout<<dem<<'\n';
 	for (i=0;i<dem;i++) ans.pb(0);
 	for (i=1;i<=n;i++){
 		for (j=1;j<=n;j++){
 			if (v[i][j].size()==dem) Upd(i,j);
 		}
 	}
 	for (k=0;k<ans.size();k++) cout<<ans[k]<<' ';
}
main(){
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("inp.txt","r",stdin); //freopen("out.txt","w",stdout);
	freopen("LIONDANCE.INP","r",stdin); freopen("LIONDANCE.OUT","w",stdout);
	cin>>n>>delta; int i,j,k;
	for (i=1;i<=n;i++){
		cin>>a[i];
	}
	for (i=1;i<=n;i++){
		cin>>b[i];
	}
	solve();
}
