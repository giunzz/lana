#define Link ""

#include <iostream>
#include <cstdio>

#define TASK "GIFTS"

using namespace std;

void OpenFile()
{
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
}

const int maxn = 1e6 + 10;
int n,k,a[maxn];
long long f[maxn],l[maxn],r[maxn],res;

int FastIn()
{
    int res = 0;
    register char c = getchar();
    while (c < '0' || '9' < c) c = getchar();
    while ('0' <= c && c <= '9') res = res * 10 + c - '0', c = getchar();
    return res;
}

void Enter()
{
    //cin >> n >> k;
    n = FastIn();
    k = FastIn();
    for (int i=1;i<=n;++i)
        //cin >> a[i];
        a[i] = FastIn();
}

void Init()
{
    for (int i=1;i<=k;++i)
        f[1] += a[i];
    for (int i=2;i+k-1<=n;++i)
        f[i] = f[i-1] - a[i-1] + a[i+k-1];
    for (int i=1;i+k-1<=n;++i)
        l[i] = max(l[i-1],f[i]);
    for (int i=n-k+1;i>=1;--i)
        r[i] = max(r[i+1],f[i]);
}

void Solve()
{
    res = 1e18;
    for (int i=1;i+k-1<=n;++i)
        res = min(res,max(l[i-1],r[i+k]));
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    OpenFile();

    Enter();
    Init();
    Solve();
}
