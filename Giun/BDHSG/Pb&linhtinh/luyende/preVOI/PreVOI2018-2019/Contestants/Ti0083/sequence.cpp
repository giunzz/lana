#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 3e3+7;
int n, m, k, a[maxn], b[maxn], tr[maxn*2];
int curn, curm;

vector <int > A[maxn*2];

bool cmp(int x, int y) { return (a[x] == a[y]) ? x < y : a[x] < a[y];}

void outp(int u){
    vector <int > res;
    while (u != -1) res.push_back(a[u]), u=tr[u];
    for (int i=res.size()-1; i>=0; --i) cout << res[i] << " ";
}

bool ok(int v){
    if (!tr[v])
        if (v > n) return v > curm;
        else return v > curn;
    return 0;
}

bool dfs(int u, int t){
    if (t == k)
    { outp(u); return 1; }
    int tg1=curm, tg2=curn;
    if (u <= n) curn=max(curn, u);
    else curm=max(curm, u);
    for (int v : A[u])
    {
        bool fl=0;
        if (ok(v)) tr[v]=u, fl=dfs(v, t+1), tr[v]=0;
        if (fl) return 1;
    }
    curm=tg1; curn=tg2;
    return 0;
}

void init(){
    curm=curn=0;
    for (int i=1; i<=n+m; ++i) tr[i]=0;
}

int main(){
    freopen("sequence.inp","r",stdin);
    freopen("sequence.out","w",stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i=1; i<=n; ++i) scanf("%d", &a[i]);
    for (int i=1+n; i<=n+m; ++i) scanf("%d", &a[i]);

    for (int i=1; i<=n; ++i)
        for (int j=i+1; j<=n; ++j) A[i].push_back(j);

    for (int i=1+n; i<=m+n; ++i)
        for (int j=i+1; j<=m+n; ++j) A[i].push_back(j);

    for (int i=1; i<=n; ++i)
        for (int j=1+n; j<=m+n; ++j)
            A[i].push_back(j), A[j].push_back(i);

    for (int i=1; i<=n+m; ++i)
        sort(A[i].begin(), A[i].end(), cmp);

    vector <pair <int, int > > pii;
    for (int i=1; i<=n+m; ++i) pii.push_back({a[i], i});
    sort(pii.begin(), pii.end());

    for (int i=0; i<m+n; ++i)
    {
        init();
        int u=pii[i].second;
        tr[u]=-1;
        if (dfs(u, 1)) break;
    }

    return 0;
}
