#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")

struct giun{
	int u , v , w;
};

bool cmp(giun &a , giun &b) {
	return a.w < b.w;
}

int n , x;
vector <giun> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	freopen("chuyen01.inp","r",stdin);
	freopen("chuyen01.out","w",stdout);
	cin >> n;
	vector <vector<int>> adj(n , vector<int> (n));
	for (int i = 0 ; i < n ; i++) 
		for (int j = 0 ; j < n ; j++) 
			cin >> adj[i][j];
	for (int i = 0 ; i < n; i++)
		for (int j = i ; j < n; j ++) {
			if (adj[i][j] != 0) {
				v.push_back({i + 1 , j + 1 , adj[i][j]});
			}	
		}
	sort(v.begin() , v.end() , cmp);
	cout << v.size() << '\n';
	for (int i = 0 ; i < (int) v.size(); i++) 
		cout << v[i].u << " " << v[i].v << " " << v[i].w << '\n';
	return 0;
}