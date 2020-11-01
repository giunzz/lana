#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct edge{
	int v, w;
	edge(int v=0,int w=0): v(v), w(w) {}
};
int n,k;
vector <edge> G[50005];
bool important[50005];
ll val;
ll check(int pos,vector<ll> &lst){
	ll res = 0;
	int pivot0 = 0, pivot1 = (int)lst.size() - 1;
	while(pivot0 < pivot1){
		while(pivot0 == pos) ++pivot0;
		while(pivot1 == pos) -- pivot1;
		res = max(res, lst[pivot0] + lst[pivot1]);
		++pivot0;
		-- pivot1;
	}
	return res;
}
ll dfs(int u,int p){
	vector <ll> lst;
	for(int i=0;i<(int)G[u].size();i++){
		int v = G[u][i].v;
		if (v == p) continue;
		ll tmp = dfs(v,u);
		if (tmp == -1) 	return -1;
		if (tmp != -2) 	lst.push_back(tmp + G[u][i].w);
	}
	if (important[u])	lst.push_back(0);
	
	sort(lst.begin(), lst.end());
	if (lst.empty()) return -2;
	else if (lst.size() == 1){
		if (lst[0] > val)	return -1;
		return lst[0];
	}
	else if (lst.size() % 2 == 1){
		int L = -1, R = (int)lst.size()-1;
		while(L+1 < R){
			int mid = (L+R)/2;
			if (check(mid, lst) <= val) R = mid;
			else L = mid;
		}
		if (check(R, lst) > val) return -1;
		return lst[R];
	}
	else{
		if (check((int)1e9, lst) > val) return -1;
		return -2;
	}
}
int main(){
	freopen("bubbletea.inp","r",stdin);
	freopen("bubbletea.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=k;i++){
		int x;
		scanf("%d",&x);
		important[x] = 1;
	}
	for(int i=1;i<n;i++){
		int x,y,w;
		scanf("%d %d %d",&x,&y,&w);
		G[x].push_back(edge(y,w));
		G[y].push_back(edge(x,w));
	}
	ll L = 0, R = (ll) 1e15;
	
	while(L+1 < R){
		val = (L+R)/2;
		if (dfs(1,1) != -1) R = val;
		else L = val;
	}
	
	printf("%lld",R);
}
/*
8 6
1 4 5 6 7 8
1 2 1
2 3 1
3 4 1
2 5 1
2 6 1
3 7 1
3 8 1
* 
8 6
1 4 5 6 7 8
1 2 1
2 3 10
3 4 1
2 5 6
2 6 6
3 7 6
3 8 6
*/ 
