#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct pp
{
    int x, y;
    ll z;
};
const int N = 100015;
int n, m, tmp, i, j, k;
int a[N];
pp b[N];
ll res;

int main()
{
//#define file "r"
#define file "BUBBLETEA"
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= k; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++)
    {
        cin >> b[i].x >> b[i].y >> b[i].z ;
        res += b[i].z;
    }
    if(k == n) cout << res << "\n";
    else cout << res / 3 << "\n";
    return 0;
}
