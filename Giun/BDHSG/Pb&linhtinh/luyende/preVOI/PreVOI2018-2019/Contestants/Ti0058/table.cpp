#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#define mp make_pair
#define pb push_back
#define fi first
#define se second

long long read(){
	char p;
	while((p = getchar())){
		if(p < '0' || p > '9') continue;
		break;
	}
	long long ret = p - '0';
	while((p = getchar())){
		if(p >= '0' && p <= '9'){
			ret *= 10LL;
			ret += p - '0';
		}
		else break;
	}
	return ret;
}

int n, m, q, sx, sy, fx, fy, mx = 0;
long long a[307][307], f[307][307], ans = 0;
pair <int, int> ip;
vector < pair <int, int> > sv;

void solve(){
	for(int i = sx; i <= fx; i++){
		for(int j = sy; j <= fy; j++){
			f[i][j] = a[i][j];
		}
	}
	f[sx][sy] = a[sx][sy];
	sv.clear();
	for(int i = sx + 1; i <= fx; i++) f[i][sy] += f[i - 1][sy];
	for(int i = sy + 1; i <= fy; i++) f[sx][i] += f[sx][i - 1];
	for(int i = sx + 1; i <= fx; i++){
		for(int j = sy + 1; j <= fy; j++){
			f[i][j] += max(f[i - 1][j], f[i][j - 1]);
		}
	}
	int cx = fx, cy = fy;
	bool fs = true;
	while(cx != sx || cy != sy){
		if(cx == sx){
			if(n >= 100 && cy == sy + 1) sv.pb(mp(cx, cy));
			else sv.pb(mp(cx, cy));
			cy--;
		}
		else if(cy == sy){
			if(n >= 100 && cx == sx + 1) sv.pb(mp(cx, cy));
			else sv.pb(mp(cx, cx));
			cx--;
		}
		else{
			if(f[cx - 1][cy] >= f[cx][cy - 1]) cx--;
			else cy--;
			if((cx != sx || cy != sy) && (n >= 100)){
				if(fs) sv.pb(mp(cx, cy));
				if(mx < a[cx][cy]){
					mx = a[cx][cy];
					ip = mp(cx, cy);
				}
			}
			else if(n < 100) sv.pb(mp(cx, cy));
		}
		fs = false;
	}
	if(n >= 100) sv.pb(ip);
}

long long ok(long long x, long long y){
	if(x == fx && y == fy) return (long long)1e18;
	if(x == sx && y == fy) return (long long)1e18;
	for(int i = sx; i <= fx; i++){
		for(int j = sy; j <= fy; j++){
			f[i][j] = a[i][j];
			if(x == i && y == j) f[i][j] = -1e18;
		}
	}
	f[sx][sy] = a[sx][sy];
	for(int i = sx + 1; i <= fx; i++) f[i][sy] += f[i - 1][sy];
	for(int i = sy + 1; i <= fy; i++) f[sx][i] += f[sx][i - 1];
	for(int i = sx + 1; i <= fx; i++){
		for(int j = sy + 1; j <= fy; j++){
			f[i][j] += max(f[i - 1][j], f[i][j - 1]);
		}
	}
	return f[fx][fy];
}

int main(){
	#ifndef Dat
		freopen("table.inp", "r", stdin);
		freopen("table.out", "w", stdout);
	#endif
	n = read(), m = read(), q = read();
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			a[i][j] = read();
		}
	}
	while(q--){
		sx = read(), sy = read(), fx = read(), fy = read();
		solve();
		ans = 1e18;
		vector < pair <int, int> > cp = sv;
		for(int i = 0; i < (int)cp.size(); i++){
			int x = cp[i].fi, y = cp[i].se;
			ans = min(ans, ok(x, y));
		}
		printf("%lld\n", ans);
	}
}
