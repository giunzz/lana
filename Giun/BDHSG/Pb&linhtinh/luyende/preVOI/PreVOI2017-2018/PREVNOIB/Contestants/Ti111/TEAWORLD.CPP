#define Link ""

#include <iostream>
#include <cstdio>
#include <bitset>
#include <cstdlib>
#include <cmath>

#define TASK "TEAWORLD"

using namespace std;

void OpenFile()
{
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
}

const int maxm = 2e3;
const int maxn = 15;
int m,n,k,x[maxm],y[maxm],z[maxm],r[maxm],xt[maxn],yt[maxn],zt[maxn],et[maxn],X,Y,Z;
bitset <maxm> b[maxn];

void Enter()
{
    cin >> m >> n >> k;
    for (int i=0;i<m;++i)
        cin >> x[i] >> y[i] >> z[i] >> r[i];
    for (int i=0;i<n;++i)
        cin >> xt[i] >> yt[i] >> zt[i] >> et[i];
    cin >> X >> Y >> Z;
}

long long D(long long X1, long long Y1, long long Z1, long long X2, long long Y2, long long Z2)
{
    return (X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2) + (Z1 - Z2) * (Z1 - Z2);
}

bool In(long long X, long long Y, long long Z, long long j)
{
    return D(X,Y,Z,x[j],y[j],z[j]) <= r[j] * r[j];
}

long long CCW(long long X0, long long Y0, long long Z0, long long X1, long long Y1, long long Z1, long long X2, long long Y2, long long Z2)
{
    long long v1x = X1 - X0;
    long long v1y = Y1 - Y0;
    long long v1z = Z1 - Z0;
    long long v2x = X2 - X0;
    long long v2y = Y2 - Y0;
    long long v2z = Z2 - Z0;
    return v1x * v2y - v2x * v1y + v1z * v2x - v2z * v1x + v1y * v2z - v2y * v1z;
}

bool Cut(int i, int j)
{
    long long D1 = D(X,Y,Z,x[j],y[j],z[j]);
    long long D2 = D(xt[i],yt[i],zt[i],x[j],y[j],z[j]);
    long long D0 = D(X,Y,Z,xt[i],yt[i],zt[i]);
    long long S = abs(CCW(X,Y,Z,x[j],y[j],z[j],xt[i],yt[i],zt[i]));
    return max(D1,D2) <= D0 && S * S <= r[j] * r[j] * D0;
}

bool Check(int i, int j)
{
    bool fl1 = In(X,Y,Z,j);
    bool fl2 = In(xt[i],yt[i],zt[i],j);
    if (fl1 && fl2)
        return 0;
    if (fl1 || fl2)
        return 1;
    return Cut(i,j);
}

void Init()
{
    for (int i=0;i<n;++i) {
        b[i] = 0;
        for (int j=0;j<m;++j)
            b[i][j] = Check(i,j);
    }
}

void Solve()
{
    long long res = 0;
    for (int t=0;t<(1<<n);++t) {
        long long s = 0;
        bitset <maxn> aby = t;
        bitset <maxm> use = 0;
        for (int i=0;i<n;++i)
            if (aby[i]) {
                s += et[i];
                use |= b[i];
            }
        if (use.count() <= k)
            res = max(res,s);
    }
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
