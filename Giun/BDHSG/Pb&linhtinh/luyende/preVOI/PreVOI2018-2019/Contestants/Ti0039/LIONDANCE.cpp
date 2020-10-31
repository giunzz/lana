//TNA
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define nmax 4005
#define oo 1000000007
#define pii pair<int, int>
#define ll long long
#define Task "LIONDANCE"

using namespace std;
int n, delta, a[nmax], b[nmax], tr[nmax], dmax, res = 0, vte, kq[nmax];
vector <int> p[nmax];
map <int, pii> mp;

void tv(int x, int d){
    int t = x, cnt = 0;
    while(t != -1){
        kq[++cnt] = a[t];
        t = tr[t];
    }
}

void DFS(int u, int d){
    if(!sz(p[u]) && res <= d){
        res = d;
        tv(u, d);
    }
    for(int v:p[u]){
        tr[v] = u;
        DFS(v, d + 1);
    }
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n >> delta;
    for (int i = 1;i <= n; i++) cin >> a[i], mp[a[i]].F = 1;
    int cnt = 1;
    for (int i = 1;i <= n; i++){
        cin >> b[i];
        if(mp[b[i]].F > 1) mp[b[i]].S++;
        mp[b[i]].F = ++cnt;
    }
    for (int i = 1;i < n; i++)
        if(mp[a[i]].F > 1)
        for(int j = i + 1;j <= n; j++)
            if((mp[a[j]].F > mp[a[i]].F || mp[a[j]].S < mp[a[i]].S) &&  abs(a[i] - a[j]) <= delta) p[i].PB(j);

    for(int i = 1; i <= n; i++){
        reset(tr); tr[i] = -1; dmax = 0;
        DFS(i, 1);
    }

    cout << res << '\n';
    for(int i = res;i >= 1; i--)
        cout << kq[i] << ' ';
    return 0;
}
