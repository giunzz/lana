#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
int  n, m , k ,  f[(int) 1e5+7] , a[(int) 1e5+7];
vector<string> x ;
string s , s1; 
map < int , int > mp;
map <string , int> mp1; 
int sluong , t;
int main()
{
	giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
	cin >> n >> k >> m ;
	for (int i = 1; i <= n ; i++)
	{
		cin >> s;
		x.push_back(s);
	}
    for (int i = 1 ; i <= n ; i++) cin >> a[i] ;
	for (int i = 1 ; i <= k ; i++)
	{
		cin >> sluong;
		int mi = INT_MAX;
		for (int j = 1 ; j <= sluong ; j++ )
		{
			cin >> t;
			mi = min(a[t] ,mi);
			mp[t] = i;
		}
		f[i] = mi;
	}
	for (int i = 0 ; i < (int) x.size() ; i++) mp1[x[i]] = f[mp[i+1]];
	long long  ans = 0;
	for (int i = 1 ; i <= m ; i++)
	{
		cin >> s;
		ans += mp1[s];
	}
	cout << ans; 
}
