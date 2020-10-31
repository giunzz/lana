//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <stdio.h>
#include <map>
#include <set>
#include <vector>
#include <string.h>
#include <cmath>
#include <climits>
#include <queue>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
#define mk make_pair
const int N = 100015;
const int oo = 1e9 + 15;
int n, k, m, tmp, as, s, t;
ll res;
int b[N], rr[N], kt[N], d[7015];
ll a[7015][7015];
int sx[7015], sy[7015], vt[7015];
vector <ii> g[N];

void cal(int x)
{
    ll ss = 0;
    for (int i = 1; i <= n; i++) kt[i] = 0;
    kt[x] = 1;
    queue <pair<int, ll> > q;
    q.push(mk(x, 0LL));
    while (!q.empty())
    {
        int u = q.front().first;
        ll ss = q.front().second;
        q.pop();
        if (u < x) continue;
        for (int i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i].first;
            int an = g[u][i].second;
            //cout << v <<" "<< an << endl;
            if (kt[v] == 1) continue;
            if (v <= k) a[x][v] = ss + an;
            kt[v] = 1;
            q.push(mk(v, ss + an));
        }
    }
}


int bfs(int x,ll mid)
{
    int i,u,j;
    queue <int> p;
    memset(vt,0,sizeof vt);
    p.push(x);
    while(!p.empty())
    {
        u=p.front();
        p.pop();
        for (int i = 1; i <= k; i++)
            if (a[u][i] <= mid && vt[i] == 0)
            {
                vt[i] = u;
                if (sy[i]==0) return i;
                else p.push(sy[i]);
            }
    }
    return 0;
}

void xl(int y)
{
    int i,j,u;
    while(y!=0)
    {
        u=vt[y];
        i=sx[u];
        sx[u]=y;
        sy[y]=u;
        y=i;
    }

}

bool check(ll mid)
{
    int d = 0, i, j;
    memset(sx,0,sizeof(sx));
    memset(sy,0,sizeof(sy));
    for (int i = 1; i <= k; i++)
        if (sx[i]==0)
        {
            j = bfs(i,mid);
            if (j != 0) xl(j);
        }
    for (int i = 1; i <= k; i++)
        if (sx[i]==0) d++;
    //cout <<"asfd " << d;
    return d <= 1;
}


int main()
{
	#define file "BUBBLETEA"
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    cin >> n >> k;
    for (int i = 1; i <= k; i++) cin >> b[i], kt[b[i]]++;
    sort(b + 1, b + 1 + k);
    m = k;
    for (int i = 1; i <= n; i++)
        if (kt[i] == 0) m++, b[m] = i;
    for (int i = 1; i <= n; i++) rr[b[i]] = i;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y >> m;
        x = rr[x], y = rr[y];
        //cout << x <<" "<< y <<" "<< m <<endl;
        g[x].push_back(mk(y, m));
        g[y].push_back(mk(x, m));
    }
    if (k <= 7000)
    {
        for (int i = 1; i <= k; i++) cal(i);
        ll r = 0;
        for (int i = 1; i <= k; i++)
			for (int j = 1; j <= i; j++) a[i][j] = oo;
        for (int i = 1; i <= k; i++)
			for (int j = i + 1; j <= k; j++) r = max(r, a[i][j]);
		/*for (int i = 1; i <= k; i++)
		{
            for (int j = 1; j <= k; j++) //cout << a[i][j] <<" ";cout << endl;
				if (a[i][j] <= 12) cout << a[i][j] <<" ";
				else cout <<"0 ";
				cout << endl;
		}*/
		//cout << check(2);
		ll l = 0, mid;
        res = (long long) 1e15 + 15;
        while (l <= r)
        {
			mid = (l + r) >> 1;
			if (check(mid)) res = min(res, mid), r = mid - 1;
			else l = mid + 1;
        }
        cout << res;
    }

    return 0;
}
