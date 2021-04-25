#include<bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
#define fii pair<double,ii>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const double inf = 100000005.0;
const double eps = 1e-4;
ll n,m,g[100][100];
double d[100][100],ans;
bool c[100][100],check[100];

priority_queue <fii,vector<fii>,greater<fii> > hp;

void solve(int ori){
	for(int i=1;i <= n;i++){
		check[i] = 1;
	}
	hp.push(mp(0.0,mp(ori,1)));
	bool ok = 0;
	while(!hp.empty()){
		fii p = hp.top();
		hp.pop();
		ll u,speed;
		double time;
		time = p.fi;
		u = p.se.fi;
		speed = p.se.se;
		if(time > d[ori][u]) continue;
		check[u] = 0;
		if(u == ori){
			if(ok){
				break;
			}
			check[u] = 1;
		}
		for(int i=1;i <= n;i++){
			if(check[i] && c[u][i] && abs((g[u][i] * 1.0) / (speed * 1.0) + d[ori][u] - d[ori][i]) > eps){
				d[ori][i] = d[ori][u] + ((g[u][i] * 1.0) / (speed * 1.0));
				hp.push(mp(d[ori][i],mp(i,speed + 1)));
			}
		}
		if(u == ori && !ok){
			ok = 1;
			d[ori][ori] = inf;
		}
	}
	// cout << ori << "\n";
	// for(int i=1;i <= n;i++){
	// 	cout << i << " " << d[ori][i] << "\n";
	// }
	// cout << "\n\n";
	ans = min(ans,d[ori][ori]);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i <= n;i++){
		for(int j=1;j <= n;j++){
			g[i][j] = inf;
			d[i][j] = inf;
		}
		d[i][i] = 0.0;
	}
	for(int i=1;i <= m;i++){
		int x,y;
		cin >> x >> y >> g[x][y];
		c[x][y] = 1;
	}
	ans = inf;
	for(int i=1;i <= n;i++){
		solve(i);
	}
	if(abs(ans - inf) > eps){
		printf("%lf",ans);
		// cout << ans << "\n";
	}
	else{
		cout << "-1\n";
	}
	// cout << (double)inf;
	return 0;
}