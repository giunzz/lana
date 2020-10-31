#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int n, m, k;
int a[3007], b[3007], cnt, cur1 = 1, cur2 = 1, idx[2][3007];
vector <int> pos[2][3007];

int main(){
	#ifndef Dat
		freopen("sequence.inp", "r", stdin);
		freopen("sequence.out", "w", stdout);
	#endif
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		pos[0][a[i]].pb(i);
	}
	for(int i = 1; i <= m; i++){
		scanf("%d", &b[i]);
		pos[1][b[i]].pb(i);
	}
	for(int i = 0; i < k; i++){
		int num = 0;
		for(int val = 0; val <= 3000; val++){
			while(idx[0][val] < (int)pos[0][val].size() && pos[0][val][idx[0][val]] < cur1) idx[0][val]++;
			while(idx[1][val] < (int)pos[1][val].size() && pos[1][val][idx[1][val]] < cur2) idx[1][val]++;
			int fa = -1, fb = -1;
			if(idx[0][val] < (int)pos[0][val].size()) fa = pos[0][val][idx[0][val]];
			if(idx[1][val] < (int)pos[1][val].size()) fb = pos[1][val][idx[1][val]];
			//if(i == 0) cout << fa << " " << fb << " " << val << endl;
			bool ok1 = (fa != -1 && n - fa + m - cur2 + 1 >= k - i - 1);
			bool ok2 = (fb != -1 && n - cur1 + 1 + m - fb >= k - i - 1);
			if(!ok1 && !ok2) continue;
			if(!ok1){
				num = val;
				cur2 = fb + 1;
			}
			else if(!ok2){
				num = val;
				cur1 = fa + 1;
			}
			else{
				num = val;
				for(int val2 = 0; val2 <= 3000; val2++){
					while(idx[0][val2] < (int)pos[0][val2].size() && pos[0][val2][idx[0][val2]] < cur1) idx[0][val2]++;
					while(idx[1][val2] < (int)pos[1][val2].size() && pos[1][val2][idx[1][val2]] < cur2) idx[1][val2]++;
					int cnt1 = 0, cnt2 = 0;
					int st1 = idx[0][val2], st2 = idx[1][val2];
					if(st1 == (int)pos[0][val2].size()) st1--;
					if(st2 == (int)pos[1][val2].size()) st2--;
					for(int x = st1; x >= 0; x--){
						if(pos[0][val2][x] < cur1) break;
						if(pos[0][val2][x] <= fa) cnt1++;
					}
					for(int x = st2; x >= 0; x--){
						if(pos[1][val2][x] < cur2) break;
						if(pos[1][val2][x] <= fb) cnt2++;
					}
					if(cnt1 < cnt2){
						cur2 = fb + 1;
						break;
					}
					else if(cnt1 > cnt2 || val2 == 3000){
						cur1 = fa + 1;
						break;
					}
				}
			}
			break;
		}
		printf("%d ", num);
	}
}
