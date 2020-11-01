#include <bits/stdc++.h>

using namespace std;

const int N = 50010;

int n, k;
int can[N];
long long f[N];
int depth[N];
int child[N];
int jump[N][17];
vector < int > ver;
vector < pair < int, int > > adj[N];

template < class T > 
struct Fenwick{
	private :
		int N;
		vector < T > bit;

	public :
		Fenwick (int x){
			N = x + 10; 
			bit.resize(N, 0);
		}

		void upd(int i, T val){
			for(; i < N; i += i & -i){
				bit[i] += val;
			}
		}		

		T ask(int i){
			T ans = 0;
			for(; i > 0; i &= i - 1){
				ans += bit[i];
			}
			return ans;
		}
};

/// Build LCA

void dfs(int u, int p = 0){

	depth[u] = depth[p] + 1;
	jump[u][0] = p;
	for(int i = 1; i < 17; ++i){
		jump[u][i] = jump[jump[u][i - 1]][i - 1];
	}


	for(auto x : adj[u]){
		if(x.first == p) continue;
		f[x.first] = f[u] + x.second;
		dfs(x.first, u);
		child[u] += child[x.first];
	}
	child[u]++;
}

int lca(int u, int v){
	if(depth[u] < depth[v]) swap(u, v);
	for(int i = 16; i >= 0; --i){
		if(depth[jump[u][i]] >= depth[v]) u = jump[u][i];
	}
	if(u == v) return u;
	for(int i = 16; i >= 0; --i){
		if(jump[u][i] != jump[v][i]) {
			u = jump[u][i];
			v = jump[v][i];
		}
	}
	return jump[u][0];
}

long long dist(int u, int v){
	int p = lca(u, v);
	return f[u] + f[v] - f[p] - f[p];
}

Fenwick < int > value(N);

int now;
int L[N];
int R[N];

void preDfs(int u, int p = 0){
	L[u] = ++now;
	for(auto x : adj[u]){
		if(x.first == p) continue;
		preDfs(x.first, u);
	}
	R[u] = now;
}

int ancestor(int x, int v){
	if(value.ask(R[x]) - value.ask(L[x] - 1) == v) return x;
	for(int i = 16; i >= 0; --i){
		int p = jump[x][i];
		if(p == 0) continue;

		int val = value.ask(R[p]) - value.ask(L[p] - 1);
		if(val <= v) x = p;
	}

	if(value.ask(R[x]) - value.ask(L[x] - 1) != v || can[x] == 0) return -1;
	return x;
}

struct SegmentTree{
	pair < long long, long long > it[N << 3];

	#define data pair < long long, long long >

	long long mx(long long u, long long v){
		if(u == -1) return v;
		if(v == -1) return u;
		return (f[u] > f[v] ? u : v);
	}

	long long mn(long long u, long long v){
		if(u == -1) return v;
		if(v == -1) return u;
		return (f[u] < f[v] ? u : v);
	}

	data comb(data u, data v){
		u.first = mx(u.first, v.first);
		u.second = mn(u.second, v.second);
		return u;
	}

	void Init(){
		memset(it, -1, sizeof it);
	}

	void remake(int x){
		it[x] = comb(it[x + x], it[x + x + 1]);
	}

	#define mid ((l + r) >> 1)

	void update(int x, int l, int r, int pos, long long val){
		if(l > pos || r < pos) return;
		if(l == r){
			it[x] = make_pair(val, val);
			return;
		}
		update(x + x, l, mid, pos, val);
		update(x + x + 1, mid + 1, r, pos, val);
		remake(x);
	}

	data query(int x, int l, int r, int u, int v){
		if(l >= u && r <= v) return it[x];
		if(l > v || r < u) return make_pair(-1, -1);
		return comb(query(x + x, l, mid, u, v), query(x + x + 1, mid + 1, r, u, v));
	}
}Smt;

int ques(int x){
	return value.ask(R[x]) - value.ask(L[x] - 1);
}

bool check(long long curr){
	Smt.Init();

	set < int > avail;
	set < pair < int, int > > rem;
	for(int x : ver){
		avail.erase(ancestor(x, 2));
		value.upd(L[x], 1);
		int p = ancestor(x, 2);
		if(p != -1) avail.insert(p);
		Smt.update(1, 1, n, L[x], x);
	}

	for(int x : ver){
		if(ques(x) == 1){
			Smt.update(1, 1, n, L[x], x);
			rem.insert(make_pair(L[x], x));
		}
	}


	while(avail.size() || rem.size()){
		if(!avail.empty()){
			int x = *avail.begin();
			avail.erase(x);
			auto p = Smt.query(1, 1, n, L[x], R[x]);

			int c = p.first;
			if(f[c] - f[x] > curr) return false;

			int o = ancestor(x, 4);
			if(o != -1) avail.insert(o);


			value.upd(L[x], -1);
			value.upd(L[c], -1);
			
			rem.erase(make_pair(L[c], c));
			Smt.update(1, 1, n, L[c], -1);
			
			x = jump[x][0];
			while(!can[x] && x != 0){
				x = jump[x][0];
			}
			if(x != 0) {
				rem.insert(make_pair(L[x], x));
				Smt.update(1, 1, n, L[x], x);
			}
		}
		else{
			auto p = *rem.begin();
			rem.erase(p);
			auto x = *rem.begin();
			rem.erase(x);

			int u = p.second, v = x.second, t = lca(u, v);
			auto nw = Smt.query(1, 1, n, L[t], R[t]);
			
			if(dist(nw.first, nw.second) > k) return false;

			value.upd(L[u], -1);
			value.upd(R[v], -1);

			rem.insert(p);
			rem.insert(x);
			rem.erase(make_pair(L[u], u));
			rem.erase(make_pair(L[v], v));


			Smt.update(1, 1, n, L[u], -1);
			Smt.update(1, 1, n, L[v], -1);
			
			if(ancestor(u, 2) != -1) avail.insert(ancestor(u, 2));
			cout << *avail.begin() << "?" << endl;

			t = jump[t][0];
			if(ques(t) == 0){
				while(t != 0 && can[t] == 0) t = jump[t][0];
				if(t != 0){
					Smt.update(1, 1, n, L[t], 1);
					rem.insert(make_pair(L[t], t));
					int d = ancestor(t, 2);
					if(d != -1) avail.insert(d);
				}
			}
		}
	}
	return true;
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}
	else{
		freopen("bubbletea.inp", "r", stdin);
		freopen("bubbletea.out", "w", stdout);
	}

	scanf("%d%d", &n, &k);
	for(int i = 1; i <= k; ++i){
		int x;
		scanf("%d", &x);
		can[x] = 1;
		ver.push_back(x);
	}

	for(int i = 1; i < n; ++i){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);

	}


	dfs(1);
	preDfs(1);

	check(2);
	return 0;

	long long low = 0, high = 1e18, ans = 1e18;
	while(low <= high){
		long long val = (low + high) >> 1;
		if(check(val)){
			ans = val;
			high = val - 1;
		}
		else{
			low = val + 1;
		}
	}

	cout << ans;

	return 0;
}