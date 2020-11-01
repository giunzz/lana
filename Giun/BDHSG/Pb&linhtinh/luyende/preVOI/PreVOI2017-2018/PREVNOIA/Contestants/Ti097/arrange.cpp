#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, a[100005];
ll tcd[100005];
ll dp[2005][2005];
ll do_sub2(){
	// checked sub 1
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			dp[i][j] = (ll) 1e18;
	dp[0][0] = 0;
	
	int sum = tcd[n]%n;
	int need = tcd[n] / n;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=min(sum, i);j++){
			dp[i][j] = min(dp[i-1][j], j ? dp[i-1][j-1] : dp[i-1][j]) + abs(tcd[i] - 1ll * i * need - j);
		}
	}
	return dp[n][sum];
}
ll f[100005];
ll seg_min[400005], seg_sum[400005];
ll lazy_min[400005], lazy_sum[400005];
void _lazy_min(int id,int l,int r){
	seg_min[id] += lazy_min[id];
	if (l != r)
		lazy_min[2*id] += lazy_min[id],
		lazy_min[2*id+1] += lazy_min[id];
	lazy_min[id] = 0;
}
void seg_min_upd_unit(int id,int l,int r,int pos,ll val){
	_lazy_min(id,l,r);
	if (r < pos || pos < l) return;
	if (l == r){
		seg_min[id] = val;
		return;
	}
	seg_min_upd_unit(2*id,l,(l+r)/2,pos,val);
	seg_min_upd_unit(2*id+1,(l+r)/2+1,r,pos,val);
	seg_min[id] = min(seg_min[2*id], seg_min[2*id+1]);
}
void seg_min_upd_range(int id,int l,int r,int u,int v,int val){
	_lazy_min(id,l,r);
	if (r < u || v < l) return;
	if (u <= l && r <= v){
		lazy_min[id] += val;
		_lazy_min(id,l,r);
		return;
	}
	seg_min_upd_range(2*id,l,(l+r)/2,u,v,val);
	seg_min_upd_range(2*id+1,(l+r)/2+1,r,u,v,val);
	seg_min[id] = min(seg_min[2*id], seg_min[2*id+1]);
}
int seg_min_find_min(int id,int l,int r){
	_lazy_min(id,l,r);
	if (l == r)	return l;
	if (seg_min[2*id] >= seg_min[2*id+1])	return	seg_min_find_min(2*id+1,(l+r)/2+1,r);
	return seg_min_find_min(2*id,l,(l+r)/2);
}
void build_seg_min(int id,int l,int r){
	if (l == r){
		seg_min[id] = f[l] <= 0 ? (ll) 1e12 : f[l];
		return;
	}
	build_seg_min(2*id, l, (l+r)/2);
	build_seg_min(2*id+1, (l+r)/2+1, r);
	seg_min[id] = min(seg_min[2*id], seg_min[2*id+1]);
}
void _lazy_sum(int id,int l,int r){
	seg_sum[id] += lazy_sum[id];
	if (l != r)
		lazy_sum[2*id] += lazy_sum[id],
		lazy_sum[2*id+1] += lazy_sum[id];
	lazy_sum[id] = 0;
}
void seg_sum_upd_range(int id,int l,int r,int u,int v,int val){
	_lazy_sum(id,l,r);
	if (r < u || v < l) return;
	if (u <= l && r <= v){
		lazy_sum[id] += val;
		_lazy_sum(id,l,r);
		return;
	}
	seg_sum_upd_range(2*id,l,(l+r)/2,u,v,val);
	seg_sum_upd_range(2*id+1,(l+r)/2+1,r,u,v,val);
	seg_sum[id] = min(seg_sum[2*id], seg_sum[2*id+1]);
}
void seg_sum_upd_unit(int id,int l,int r,int pos,ll val){
	_lazy_sum(id,l,r);
	if (r < pos || pos < l) return;
	if (l == r){
		seg_sum[id] = val;
		return;
	}
	seg_sum_upd_unit(2*id,l,(l+r)/2,pos,val);
	seg_sum_upd_unit(2*id+1,(l+r)/2+1,r,pos,val);
	seg_sum[id] = min(seg_sum[2*id], seg_sum[2*id+1]);
}
ll seg_sum_get(int id,int l,int r,int u,int v){
	_lazy_sum(id,l,r);
	if (v < l || r < u) return (ll) 1e12;
	if (u <= l && r <= v){
		return seg_sum[id];
	}
	return min(seg_sum_get(2*id,l,(l+r)/2,u,v), seg_sum_get(2*id+1,(l+r)/2+1,r,u,v));
}
int seg_sum_find_min(int id,int l,int r){
	_lazy_sum(id,l,r);
	if (l == r)	return l;
	if (seg_sum[2*id] >= seg_sum[2*id+1])	return	seg_sum_find_min(2*id+1,(l+r)/2+1,r);
	return seg_sum_find_min(2*id,l,(l+r)/2);
}
ll solve(){
	// greedy
	ll need = tcd[n]/n;
	ll sum = tcd[n]% n;
	ll res = 0;
	for(int i=1;i<=n;i++)	f[i] = tcd[i] - need * i, res += abs(f[i]);
	build_seg_min(1,1,n);
	for(int i=1;i<=n;i++)
		if (f[i] > 0)	seg_sum_upd_range(1,1,n,1,i,-1);
		else 			seg_sum_upd_range(1,1,n,1,i, 1);
		
	//cerr << need << ' ' << sum << endl;
	//for(int i=1;i<=n;i++) cerr << f[i] << ' '; cout << endl;
	//for(int i=1;i<=n;i++) cerr << seg_sum_get(1,1,n,i,i) << ' '; cout << endl;
	
	while(sum--){
		//cerr << sum << ' ' << res << endl;
		int where_to_place = seg_sum_find_min(1,1,n);
		//cerr << "k\n";
		res += seg_sum_get(1,1,n,where_to_place, where_to_place);
		
		seg_sum_upd_unit(1,1,n,where_to_place, (ll) 1e12);
		seg_min_upd_range(1,1,n,where_to_place,n,-1);
		
		while(seg_min[1] == 0){
			int where_to_del = seg_min_find_min(1,1,n);
			seg_sum_upd_range(1,1,n,1, where_to_del, 2); // <- check this
			seg_min_upd_unit(1,1,n,where_to_del, (ll) 1e12);
		}
		//for(int i=1;i<=n;i++) cerr << seg_sum_get(1,1,n,i,i) << ' '; cout << endl;
	}
	return res;
}
int main(){
	freopen("arrange.inp","r",stdin);
	freopen("arrange.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),
		tcd[i] = tcd[i-1] + a[i];

	if (n <= 2000) printf("%lld",do_sub2());
	else printf("%lld",solve());
}
/*
8
2 2 2 2 1 9 1 2
5
11 59 14 95 89
3
32 9 59
4
77 10 29 39 
4
6 5 2 6 
*/
