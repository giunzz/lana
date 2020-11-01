#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e3+7;
int n, k, a[maxn][3], f[maxn], tr[maxn];

bool ok(int i, int j){
    vector <int > tg;
    tg.push_back(a[i][0]);
    while (j) tg.push_back(a[j][0]), j=tr[j];

    int it=tg.size()-1;
    for (int t=1; t<=n; ++t)
    {
        if (a[t][1] == tg[it]) it--;
        if (it < 0) return 1;
    }
    return 0;
}

bool check(int i, int j){
    vector <int > t1, t2;
    while (i) t1.push_back(a[i][0]), i=tr[i];
    while (j) t2.push_back(a[j][0]), j=tr[j];
    for (int t=t1.size()-1; t>=0; --t)
        if (t1[t] > t2[t]) return 1;
    return 0;
}

int main(){
    freopen("liondance.inp","r",stdin);
    freopen("liondance.out","w",stdout);
    scanf("%d%d", &n, &k);
    for (int i=1; i<=n; ++i) scanf("%d", &a[i][0]);
    for (int i=1; i<=n; ++i) scanf("%d", &a[i][1]);

    for (int i=1; i<=n; ++i)
    {
        f[i]=1;
        for (int j=i-1; j>=1; --j)
            if (abs(a[j][0] - a[i][0]) <= k && ok(i, j))
            {
                if (f[j] + 1 > f[i]) f[i]=f[j]+1, tr[i]=j;
                if (f[j] + 1 == f[i])
                    if (a[j] > a[tr[i]]) tr[i]=j;
            }
    }

    int ans=-1, vt;
    for (int i=1; i<=n; ++i)
    {
        if (f[i] > ans) ans=f[i], vt=i;
        if (f[i] == ans)
            if (check(i, vt)) vt=i;
    }

    cout << ans << "\n";
    vector <int > res;
    while (vt) res.push_back(a[vt][0]), vt=tr[vt];

    for (int i=res.size()-1; i>=0; --i) cout << res[i] << " ";

    return 0;
}
