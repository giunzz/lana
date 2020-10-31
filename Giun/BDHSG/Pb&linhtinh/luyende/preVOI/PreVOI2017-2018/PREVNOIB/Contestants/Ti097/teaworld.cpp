#include <bits/stdc++.h>
using namespace std;
//const double eps = 1e-12;
struct point{
	double x,y,z;
	point(double x=0.0, double y=0.0, double z=0.0): x(x), y(y), z(z) {}
};
point gs_pvh, ball[2005], shop[20];
int ball_radius[2005],	shop_energy[20];
int m,n,k;
vector <int> lst[20];
double sqr(double a){
	return a*a;
}
double dis(point a,point b){
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y) + sqr(a.z - b.z));
}
int rember[2005];
int ans, cnt, tmp;
void _back(int pos){
	ans = max(ans, tmp);
	
	if (pos == n+1){
		return;
	}
	
	for(int i=0;i<(int)lst[pos].size();i++){
		cnt += (rember[lst[pos][i]] == 0);
		rember[lst[pos][i]]++;
	}
	tmp += shop_energy[pos];
	if (cnt <= k)	_back(pos+1);
	
	for(int i=0;i<(int)lst[pos].size();i++){
		rember[lst[pos][i]]--;
		cnt -= (rember[lst[pos][i]] == 0);
	}
	tmp -= shop_energy[pos];
	if (cnt <= k) 	_back(pos+1);
}
int main(){
	freopen("teaworld.inp","r",stdin);
	freopen("teaworld.out","w",stdout);
	iostream::sync_with_stdio(0);
	cin >> m >> n >> k;
	for(int i=1;i<=m;i++){
		cin >> ball[i].x >> ball[i].y >> ball[i].z >> ball_radius[i];
	}
	for(int i=1;i<=n;i++){
		cin >> shop[i].x >> shop[i].y >> shop[i].z >> shop_energy[i];
	}
	cin >> gs_pvh.x >> gs_pvh.y >> gs_pvh.z;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if (dis(ball[j], gs_pvh) <= 1.0 * ball_radius[j] && dis(ball[j], shop[i]) > 1.0 * ball_radius[j])
				lst[i].push_back(j);
			else if (dis(ball[j], gs_pvh) > 1.0 * ball_radius[j] && dis(ball[j], shop[i]) <= 1.0 * ball_radius[j])
				lst[i].push_back(j);
			else if (dis(ball[j], gs_pvh) > 1.0 * ball_radius[j] && dis(ball[j], shop[i]) > 1.0 * ball_radius[j]){
				double L = 0, R = 1;
				point t1,t2;
				for(int _time=0;_time<=70;_time++){
					double mid1 = (L+L+R)/3;
					double mid2 = (L+R+R)/3;
					t1 = point(gs_pvh.x*mid1 + shop[i].x*(1.0-mid1), 
							   gs_pvh.y*mid1 + shop[i].y*(1.0-mid1),
							   gs_pvh.z*mid1 + shop[i].z*(1.0-mid1));
					t2 = point(gs_pvh.x*mid2 + shop[i].x*(1.0-mid2), 
							   gs_pvh.y*mid2 + shop[i].y*(1.0-mid2),
							   gs_pvh.z*mid2 + shop[i].z*(1.0-mid2));
					if (dis(ball[j], t1) < dis(ball[j], t2))	R = mid2;
					else L = mid1;
				}
				if (dis(ball[j], t1) <= 1.0 * ball_radius[j])
					lst[i].push_back(j);
			}
		}
	}
	_back(1);
	cout << ans;
}
/*
12 5 4
0 10 0 1
1 5 0 2
1 4 0 2
0 0 0 2
10 0 0 1
3 -1 0 2
5 -1 0 2
10 10 0 15
0 -10 0 1
10 -10 0 1
-10 -10 0 1
10 10 0 1
0 10 0 240
10 0 0 200
10 -2 0 52
-10 0 0 100
1 1 0 2
0 0 0
* 
1 2 0
0 0 0 1
-1 0 0 5
2 0 0 100
1 0 0
*/
