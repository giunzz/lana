#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define II pair<int, int>
#define x first
#define y second
#define mp make_pair
using namespace std;
const int N = 4005;
int n, a[N], b[N], delta;
void sub1()
{
	int maxst = (1 << n) - 1;
	vector<int> res;
	for(int i = 1; i < maxst; i ++){
		vector<int> d;
		for(int j = 0; j < n; j ++)
			if((i >> j) & 1) d.pb(a[j + 1]);
		if(d.size() < res.size()) continue;
		int check = 1, last = 0;
		for(int i = 0; i < d.size(); i ++){
			if(i && abs(d[i - 1] - d[i]) > delta){
				check = 0;
				break;
			} 
			int fi = 0;
			for(int j = last + 1; j <= n; j ++){
				if(b[j] == d[i]){
					fi = j;
					break;
				}
			}
			if(!fi){
				check = 0;
				break;
			}
			last = fi;
		}
		if(!check) continue;
		if(d.size() > res.size()) res = d;
		else if(d > res) res = d;
	}
	cout << res.size() << '\n';
	for(int i : res) cout << i << ' ';
}
int main()
{
	freopen("LIONDANCE.inp", "r", stdin);
	freopen("LIONDANCE.out", "w", stdout);
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> delta;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= n; i ++) cin >> b[i];
	sub1();	
}