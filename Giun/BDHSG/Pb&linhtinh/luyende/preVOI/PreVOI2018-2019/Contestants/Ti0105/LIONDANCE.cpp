#include <bits/stdc++.h>

using namespace std;

const int maxn=4011;

int n, delta, l[maxn], r[maxn], dp[111][111][111], res[111];

int slv(int i, int j, int pre)
{
    if (i==n+1 | j==n+1) return 0;
    if (dp[i][j][pre]!=-1) return dp[i][j][pre];
    int cur;
    if (l[i]==r[j])
    {
        if (pre==0) cur=slv(i+1, j+1, i)+1;
        else
        {
            if (abs(l[i]-l[pre])<=delta) cur=slv(i+1, j+1, i)+1;
            else cur=max(slv(i+1, j, pre), slv(i, j+1, pre));
        }
    }
    else cur=max(slv(i+1, j, pre), slv(i, j+1, pre));
    return dp[i][j][pre]=cur;
}

void trace(int i, int j, int pre, int cnt)
{
    if (i==n+1 || j==n+1) return;
    if (l[i]==r[j])
    {
        if (pre==0)
        {
            if (res[cnt]<l[i])
            {
                res[cnt]=l[i];
                trace(i+1, j+1, i, cnt+1);
            }
        }
        else
        {
            if (abs(l[i]-l[pre])<=delta)
            {
                if (res[cnt]<l[i])
                {
                    res[cnt]=l[i];
                    trace(i+1, j+1, i, cnt+1);
                }
            }
            else
            {
                if (slv(i, j, pre)==slv(i+1, j, pre)) trace(i+1, j, pre, cnt);
                else trace(i, j+1, pre, cnt);
            }
        }
    }
    else
    {
        if (slv(i, j, pre)==slv(i+1, j, pre)) trace(i+1, j, pre, cnt);
        else trace(i, j+1, pre, cnt);
    }
}

int main()
{
    freopen("LIONDANCE.INP", "r", stdin);
    freopen("LIONDANCE.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>delta;
    for (int i=1; i<=n; i++) cin>>l[i];
    for (int i=1; i<=n; i++) cin>>r[i];
    if (n<=500)
    {
        memset(dp, -1, sizeof(dp));
        cout<<slv(1, 1, 0)<<"\n";
        trace(1, 1, 0, 1);
        for (int i=1; i<=slv(1, 1, 0); i++) cout<<res[i]<<" ";
        return 0;
    }
    cout<<n<<"\n";
    for (int i=1; i<=n; i++) cout<<l[i]<<" ";
    return 0;
}
