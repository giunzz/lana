#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-3;
const double hehe = 1e-6;

struct Point{
	double x;
	double y;
	double z;

	void read(){
		cin >> x >> y >> z;
	}

	double Dist2D(Point &other){
		return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
	}

	double Dist3D(Point &other){
		return sqrt((z - other.z) * (z - other.z) + Dist2D(other) * Dist2D(other));
	}
};

const int N = 2020;

int n, m, k;
Point pvh;
Point a[N];
Point b[N];
double cover[N];
int energy[N];

int bit[1 << 15];
bitset < 2010 > tea[N];
bitset < 2010 > f[1 << 15];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}
	else{
		freopen("teaworld.inp", "r", stdin);
		freopen("teaworld.out", "w", stdout);
	}

	cin >> m >> n >> k;

	for(int i = 1; i <= m; ++i){
		a[i].read();
		cin >> cover[i];
	}

	for(int i = 1; i <= n; ++i){
		b[i].read();
		cin >> energy[i];
	}

	pvh.read();


	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			
			//i = 1;
			//j = 2;
			Point l = pvh, r = b[i], ans = l;

			if(pvh.Dist3D(a[j]) <= cover[j] && b[i].Dist3D(a[j]) <= cover[j]) continue;


			for(int bs = 1; bs <= 60; ++bs){
				Point mid;
				mid.x = (l.x + r.x) / 2;
				mid.y = (l.y + r.y) / 2;
				mid.z = (l.z + r.z) / 2;

				Point magic;
				if(l.x != r.x) magic.x = mid.x + ((l.x - r.x) / abs(l.x - r.x)) * eps;
				else magic.x = l.x;
				
				if(l.y != r.y) magic.y = mid.y + ((l.y - r.y) / abs(l.y - r.y)) * eps;
				else magic.y = l.y;
				
				if(l.z != r.z) magic.z = mid.z + ((l.z - r.z) / abs(l.z - r.z)) * eps;
				else magic.z = l.z;


				if(mid.Dist3D(a[j]) < magic.Dist3D(a[j])){
					l = mid;
				}
				else{
					r = mid;
				}
			}

			if(r.Dist3D(a[j]) <= cover[j] + eps){
				tea[i][j - 1] = 1;
			}
		}
	}	

	int ans = 0;

	for(int i = 0; i < 15; ++i){
		bit[1 << i] = i;
	}

	for(int mask = 1; mask < (1 << n); ++mask){
		int x = mask & (-mask);
		int p = bit[x];

		f[mask] = f[mask ^ x] | tea[p + 1];
		if(f[mask].count() <= k){
			int sum = 0;
			for(int j = 0; j < n; ++j){
				if(mask & (1 << j)){
					sum += energy[j + 1];
				}
			}
			ans = max(ans, sum);
		}
	}

	cout << ans;

	return 0;
}