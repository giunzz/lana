#include <bits/stdc++.h>
#define FILE "GIFTS"

using namespace std;
const int maxn=3e6+5;

struct Data{ long long val; int vt; }s[maxn];
int n, k, a[maxn];

bool cmp(Data a, Data b){ return a.val > b.val; }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin >> n >> k; for (int i=1; i<=n; i++) cin >> a[i];
    s[1].vt = 1; for (int i=1; i<=k; i++) s[1].val += a[i];
    for (int i=2; i<=n-k+1; i++){ s[i].vt = i; s[i].val = s[i-1].val-a[i-1]+a[i+k-1]; }
    sort(s+1,s+n-k+2,cmp);
    int i = 1, l = s[1].vt, r = s[1].vt;
    while(r-l+1 <= 2*k-1){ i++; l = min(l,s[i].vt); r = max(r,s[i].vt); }
    cout << s[i].val;
    return 0;
}
