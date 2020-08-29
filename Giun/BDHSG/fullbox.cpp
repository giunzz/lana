#include <bits/stdc++.h>
using namespace std;

int dn[68], cnt[68], ans[68];
void nhiphan(long long n)
{
	vitri.clear();
	memset(dn ,0, sizeof(dn));
	vector<int> np;
	while(n){
		np.push_back(n&1);
		n >>= 1;
	}
	reverse(np.begin(), np.end());
	for (int i = 0; i < i.size(); i++) {dn[i] = np[i];}
}

const int maxm = 1e5 + 7;
int a[maxm] = {0};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("fullbox.inp","r",stdin);
	freopen("fullbox.out","w",stdout);
	int t;
	cin>>t;
	long long n, m;
	while(t--){
		memset(cnt, 0, sizeof(cnt));
		memset(ans, 0, sizeof(ans));
		cin >> n >> m;
		for(int i = 1; i <= m; i++) cin >> a[i];
		nhiphan(n);
		for(int i = 1; i <= m; i++){
			++cnt[__builtin_ctz(a[i])];
		}
		for(int i = 0; i <= 64; i++){
			if(dn[i]){
				for(j = i; j >= 0; j--){
					if(cnt[j] )
				}
			}
		}
	}
	return 0;
}

