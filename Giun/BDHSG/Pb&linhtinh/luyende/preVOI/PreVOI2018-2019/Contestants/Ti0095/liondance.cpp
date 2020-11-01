#include <bits/stdc++.h>

using namespace std;
const int N = 4012;
int n,delta,l[N],r[N],dd[N],ans,aw[N];

void Btrack(int rl,int rr,int sl)
{
    bool fl = 1;
    for(int i = rl+1;i <= n;i++)
        for(int j = rr+1;j <= n;j++) if(l[i] == r[j] && abs(l[i] - l[rl]) <= delta)
        {
            fl = 0;
            dd[sl+1] = l[i];
            Btrack(i,j,sl+1);
        }
    if(fl)
    {
        if(ans == sl)
        {
            for(int i = 1;i <= sl;i++)
            {
                if(aw[i] > dd[sl]) break;
                if(aw[i] < dd[sl])
                {
                    for(int j = i;j <= sl;j++) aw[j] = dd[j];
                    break;
                }
            }
        }
        else if(ans < sl)
        {
            ans = sl;
            for(int i = 1;i <= sl;i++) aw[i] = dd[i];
        }
    }
}

void sub1()
{
    dd[1] = l[1];
    Btrack(1,1,1);
    cout << ans << '\n';
    for(int i = 1;i <= ans;i++) cout << aw[i] << ' ';
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("liondance.inp","r",stdin);
    freopen("liondance.out","w",stdout);
    cin >> n >> delta;
    for(int i = 1;i <= n;i++) cin >> l[i];
    for(int i = 1;i <= n;i++) cin >> r[i];
    sub1();
    return 0;
}
