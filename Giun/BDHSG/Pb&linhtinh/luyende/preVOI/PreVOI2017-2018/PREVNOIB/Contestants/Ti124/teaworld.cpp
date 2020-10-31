#include<bits/stdc++.h>
using namespace std;

const int N = 2006;
const int M = 16;
const int inf = 1e9 + 7;

typedef pair<int, int > pii;

int m, n, k;
pii ball[N];
pii tea[M];
map<int , int > MP;
int gs;
vector<int > BB;
int res = 0;

main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("teaworld.inp", "r", stdin);
	freopen("teaworld.out", "w", stdout);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++){
		int x, y, z, r;
		cin >> x >> y >> z >> r;
		MP[x + r] = i; MP[x - r] = i;
		ball[i] = make_pair(x, r);
	}
	for (int i = 1; i <= m; i++){
		int x, y, z, e;
		cin >> x >> y >> z >> e;
		tea[i] = make_pair(x, e);
	}
	int x, y, z;
	cin >> x >> y >> z;
	gs = x;
	
	for (int mask = 1; mask < (1 << m); mask++){
		BB.clear();
		int minId = gs, maxId = gs, ene = 0;
		for (int j = 0; j < m; j++)
			if (mask & (1 << j)) {
				minId = min(minId, tea[j + 1].first);
				maxId = max(maxId, tea[j + 1].first);
				ene += tea[j + 1].second;
			}
		int need = 0;
		for (int j = minId; j <= maxId; j++)
			if (MP.count(j)) {
				int x = MP[j];
				if (x > 0){
					int cls = ball[x].first + ball[x].second;
					if (cls < maxId) need++;
					else
						need += (j != minId);
				}
				else{
					int mo = (ball[x].first - ball[x].second );
					if (j > minId && j < maxId) need += ( mo < minId);
					else
					if (j == minId) need += (mo < minId);
				}
			}
		if (need <= k)
			res = max(res, ene);
	}
	cout << res;
}