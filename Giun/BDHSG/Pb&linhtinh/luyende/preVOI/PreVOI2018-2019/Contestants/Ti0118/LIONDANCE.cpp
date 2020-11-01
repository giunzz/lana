#define Link ""

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define TASK "LIONDANCE"

using namespace std;

const int maxn = 4e3 + 100;
int n,d,l[maxn],r[maxn],f[maxn][maxn];
vector <int> mem[maxn*maxn];

void Enter()
{
    cin >> n >> d;
    for (int i=1;i<=n;++i)
        cin >> l[i];
    for (int i=1;i<=n;++i)
        cin >> r[i];
}

void Init()
{
    reverse(l+1,l+n+1);
    reverse(r+1,r+n+1);
}

void Trade(int T, int m, int n, int pre)
{
    int mx = -1;
    int chosei,chosej;
    for (int t=0;t<mem[T].size();t+=2) {
        int i = mem[T][t];
        int j = mem[T][t+1];
        if (i >= m || j >= n)
            continue;
        if (pre == -1 || (pre != -1 && pre - d <= l[i] && l[i] <= pre + d)) {
            if (l[i] > mx) {
                chosei = 0;
                chosej = 0;
            }
            mx = max(mx,l[i]);
            if (mx == l[i]) {
                chosei = max(chosei,i);
                chosej = max(chosej,j);
            }
        }
    }
    cout << mx << ' ';
    if (T > 1)
        Trade(T-1,chosei,chosej,mx);
}

void Solve()
{
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j) {
            f[i][j] = max(f[i-1][j],f[i][j-1]);
            if (l[i] == r[j] && f[i][j] <= f[i-1][j-1] + 1) {
                f[i][j] = f[i-1][j-1] + 1;
                mem[f[i][j]].push_back(i);
                mem[f[i][j]].push_back(j);
            }
        }
    cout << f[n][n] << '\n';
    Trade(f[n][n],n+1,n+1,-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifdef LHL
    freopen(".INP","r",stdin);
    freopen(".OUT","w",stdout);
#else
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
#endif // LHL

    Enter();
    Init();
    Solve();
}
