
#include <iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>

#define ll long long
#define fti(i, x, y) for(int i = (x), _y = (y); i <= _y; ++i)

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;

const int N = 2001;
const int maxn = 20;
const int base = 2010;

int X[] = {1, 0, -1, 0};
int Y[] = {0, 1, 0, -1};
int n, m, k, x[N], y[N], z[N], r[N], xn[maxn], yn[maxn], zn[maxn], e[maxn], cnt, u, v, t, ans;
typedef pair<int, int> ii;
typedef pair< ii, int > iii;
typedef pair<ii, ii> iiii;

int a[base][base], d[base][base], c[base][base];
priority_queue<iiii> pq;
void Input()
{
    cin >> m >> n >> k;
    fti(i, 1, m) {
        cin >> x[i] >> y[i] >> z[i] >> r[i];
        x[i] += 1001;
        y[i] += 1001;
        ++ cnt;
        fti(q, x[i] - r[i], x[i] + r[i]) d[q][y[i]] |= cnt;
        fti(q, y[i] - r[i], y[i] + r[i]) d[x[i]][q] |= cnt;
    }
    fti(i, 1, n){
        cin >> xn[i] >> yn[i] >> zn[i] >> e[i];
        xn[i] += 1001;
        yn[i] += 1001;
        a[xn[i]][yn[i]] = e[i];
    }
    cin >> u >> v >> t;
    u += 1001;
    v += 1001;
}

void dijsktra()
{
    c[u][v] = 1;
    pq.push(mp(mp(a[u][v], u), mp(v, 0)));
    iiii H, T;
    while(pq.size()){
        H = pq.top();
        pq.pop();
        if(H.se.se > k) continue;
        if(H.se.se == k) ans = max(ans, H.fi.fi);
        fti(i, 0, 3){
            if(H.fi.se + X[i] > 2001 || H.fi.se + X[i] < 1 || H.se.fi + Y[i] > 2001 || H.se.fi + Y[i] < 1) continue;
            if(c[H.fi.se + X[i]][H.se.fi + Y[i]] == 0){
                c[H.fi.se + X[i]][H.se.fi + Y[i]] = 1;
                T.fi.fi = H.fi.fi + a[H.fi.se + X[i]][H.se.fi + Y[i]];
                T.fi.se = H.fi.se + X[i];
                T.se.fi = H.se.fi + Y[i];
                T.se.se = H.se.se;
                if(d[H.fi.se][H.se.fi] != d[H.fi.se + X[i]][H.se.fi + Y[i]]) T.se.se++;
                pq.push(T);
            }
        }
    }
    cout << ans;
}
void io()
{
    freopen("TEAWORLD.inp", "r", stdin);
    freopen("TEAWORLD.out", "w", stdout);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    io();
    Input();
    dijsktra();
}
