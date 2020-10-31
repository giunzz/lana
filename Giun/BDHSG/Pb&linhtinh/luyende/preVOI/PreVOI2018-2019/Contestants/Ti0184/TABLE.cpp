#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define II pair<int, int>
#define x first
#define y second
#define mp make_pair
using namespace std;
ll n, m, k, f[305][305], a[305][305], oo = 1e15;
void sub1()
{
	for(int test = 1; test <= k; test ++){
		int st_x, st_y, fi_x, fi_y;
		cin >> st_x >> st_y >> fi_x >> fi_y;
		ll res = oo;
		for(int bl_x = st_x; bl_x <= fi_x; bl_x ++)
			for(int bl_y = st_y; bl_y <= fi_y; bl_y ++){
				if(bl_x == st_x && bl_y == st_y) continue;
				if(bl_x == fi_x && bl_y == fi_y) continue;
				for(int i = st_x - 1; i <= fi_x; i ++)
					for(int j = st_y - 1; j <= fi_y; j ++) f[i][j] = -1e15;
				f[st_x][st_y] = a[st_x][st_y];
				for(int i = st_x; i <= fi_x; i ++)
					for(int j = st_y; j <= fi_y; j ++){
						if(i == st_x && j == st_y) continue;
						if(i == bl_x && j == bl_y) continue;
						f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];
				}
				res = min(res, f[fi_x][fi_y]);
			}
		if(res == oo) cout << a[st_x][st_y] + a[fi_x][fi_y] << '\n';
		else cout << res << '\n';
	}
}
ll f_st[305][305], f_fi[305][305], way_st[305][305], way_fi[305][305];
void sub2()
{
	for(int test = 1; test <= k; test ++){
		int st_x, st_y, fi_x, fi_y;
		cin >> st_x >> st_y >> fi_x >> fi_y;
		for(int i = 0; i <= m + 1; i ++)
			for(int j = 0; j <= n + 1; j ++){
				f_st[i][j] = f_fi[i][j] = -1e15;
				way_st[i][j] = way_fi[i][j] = 0;
			}
		
		f_st[st_x][st_y] = a[st_x][st_y];
		way_st[st_x][st_y] = 1;
		for(int i = st_x; i <= fi_x; i ++)
			for(int j = st_y; j <= fi_y; j ++){
				if(i == st_x && j == st_y) continue;
				if(f_st[i - 1][j] > f_st[i][j - 1]){
					f_st[i][j] = f_st[i - 1][j] + a[i][j];
					way_st[i][j] = way_st[i - 1][j];
				}
				else if(f_st[i][j - 1] > f_st[i - 1][j]){
					f_st[i][j] = f_st[i][j - 1] + a[i][j];
					way_st[i][j] = way_st[i][j - 1];
				}
				else{
					f_st[i][j] = f_st[i][j - 1] + a[i][j]; 
					way_st[i][j] = way_st[i - 1][j] + way_st[i][j - 1]; 
				}
			}

		f_fi[fi_x][fi_y] = a[fi_x][fi_y];
		way_fi[fi_x][fi_y] = 1;
		for(int i = fi_x; i >= st_x; i --)
			for(int j = fi_y; j >= st_y; j --){
				if(i == fi_x && j == fi_y) continue;
				if(f_fi[i][j + 1] > f_fi[i + 1][j]){
					f_fi[i][j] = f_fi[i][j + 1] + a[i][j];
					way_fi[i][j] = way_fi[i][j + 1];
				}
				else if(f_fi[i + 1][j] > f_fi[i][j + 1]){
					f_fi[i][j] = f_fi[i + 1][j] + a[i][j];
					way_fi[i][j] = way_fi[i + 1][j];
				}
				else{
					f_fi[i][j] = f_fi[i][j + 1] + a[i][j];
					way_fi[i][j] = way_fi[i + 1][j] + way_fi[i][j + 1]; 
				}
			}
		ll num_dis = f_st[fi_x][fi_y], num_way = way_st[fi_x][fi_y];
		vector<II> xet;
		for(int i = st_x; i <= fi_x; i ++)
			for(int j = st_y; j <= fi_y; j ++){
				if(i == st_x && j == st_y) continue;
				if(i == fi_x && j == fi_y) continue;
				if(f_st[i][j] + f_fi[i][j] - a[i][j] == num_dis && way_st[i][j] * way_fi[i][j] == num_way)
					xet.pb(mp(i, j));
			}
		if(xet.size() == 0){
			cout << num_dis << '\n';
			continue;
		}
		ll res = 1e15;
		for(auto u : xet){
			ll tmp = 0;
			for(int j = u.y + 1; j <= fi_y; j ++) tmp = max(tmp, f_st[u.x - 1][j] + f_fi[u.x][j]);
			for(int i = u.x + 1; i <= fi_y; i ++) tmp = max(tmp, f_st[i][u.y - 1] + f_fi[i][u.y]);
			res = min(res, tmp);
		}
		cout << res << '\n';
	}
}
int main()
{
	freopen("TABLE.inp", "r", stdin);
	freopen("TABLE.out", "w", stdout);
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> m >> n >> k;
	for(int i = 1; i <= m; i ++)
		for(int j = 1; j <= n; j ++) cin >> a[i][j];
	if(m <= 30 && n <= 30 && k <= 30) sub1();
	else sub2();
}