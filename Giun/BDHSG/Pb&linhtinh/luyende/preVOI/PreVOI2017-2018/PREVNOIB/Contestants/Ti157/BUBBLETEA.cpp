#include <bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define ii pair<int, int>
#define mod 1e9+7;
#define HANH "BUBBLETEA"
using namespace std;
const int N=50005;
vector <pair<pair<int, int>, int> > f[N];
int n, k, sua[N], u, v, c, d[N];
ii pre[20][N];
long long kq;
dfs1(int uu)
{
    d[uu]=1;
    int cnt=0, con[N];
    for(int i=0; i<f[uu].size(); ++i)
    {
        int vv=f[uu][i].x.x;
        int cc=f[uu][i].x.y;
        if(!d[vv])
        {
            dfs1(vv);
            if(sua[vv]) con[++cnt]=cc;
        }
    }
    sort(con+1, con+cnt+1);
    if(cnt%2) { kq=max(kq, 1ll*con[cnt]); --cnt; sua[uu]=0; }
    for(int i=1; i<=cnt/2; ++i) kq=max(kq, 1ll*con[i]+con[cnt+1-i]);
}
void sub2()
{
    kq=0;
    dfs1(1);
    cout <<kq;
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen(HANH".inp", "r", stdin);
    freopen(HANH".out", "w", stdout);
    cin >>n >>k;
    for(int i=1; i<=k; ++i) cin >>c, sua[c]=1;
    for(int i=1; i<n; ++i)
    {
        cin >>u >>v >>c;
        f[u].push_back(mp(mp(v, c), i));
        f[v].push_back(mp(mp(u, c),i ));
    }
    sub2(); return 0;
}
