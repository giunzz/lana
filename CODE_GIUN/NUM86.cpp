#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;
const ll maxn = 1e3 + 7;
ll n , f[maxn][maxn] , p[maxn]  ;

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 0 ; i <= 200 ; i++) 
        for (int j = 0 ; j <= 200 ; j++)f[i][j] = -1;
    f[0][0] = 0;
    p[0] = 1;
    for (int i = 1 ; i <= 200 ; i++) p[i] = p[i-1] * 10 % n;
    queue<pair<ll,ll>> st;
	st.push(make_pair(0,1));
	f[0][1] = 6 % n;
	st.push(make_pair(1,0));
	f[1][0] = 8 % n;

	while (! st.empty()) 
    {
		int x = st.front().first, y = st.front().second;
		st.pop();
		if (f[x][y] == 0) 
        {
			for (int i = 1 ; i <= x ; i++) cout << 8;
			for (int i = 1 ; i <= y ; i++) cout << 6;
			return 0;
		}
		if (x + y == 200) continue;
		if (f[x][y+1] == -1) 
        {
			f[x][y+1] = (f[x][y] * 10 % n + 6) % n;
			st.push(make_pair(x,y+1));
		}
		if (f[x+1][y] == -1) {
			f[x+1][y] = (8 * p[x+y] % n + f[x][y]) % n;
			st.push(make_pair(x+1,y));
		}
	}
    cout << -1;
}
