/**Lucky Boy**/
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 305
#define maxm 500005
#define pii pair <int,int>
#define Task "TABLE"
template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar())) x=x*10+c-48;if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}
using namespace std;
int n,m,q,a[maxn][maxn],b[maxn][maxn];
long long ans,dp[maxn][maxn],dp1[maxn][maxn];
long long Calc(int x,int y,int u,int v)
{
    FOR(i,0,x+1)
        FOR(j,0,y+1) dp[i][j] = -1ll*maxc*maxc;
    dp[1][1] = b[1][1];
    FOR(i,1,x)
        FOR(j,1,y)
        {
            if (i == u && j == v) continue;
            if (i == 1 && j == 1) continue;
            dp[i][j] = max(dp[i][j-1],dp[i-1][j]) + b[i][j];
        }
    return dp[x][y];
}
void Sub1(int x,int y)
{
    ans = 1ll*maxc*maxc;
    FOR(i,1,x)
        FOR(j,1,y)
            if ((i == 1 && j == 1) || (i == x && j == y));
            else
            {
                ans = min(ans,Calc(x,y,i,j));
            }
    cout << ans << '\n';
}
void Sub2(int x,int y)
{
    ans = 1ll*maxc*maxc;
    FOR(i,0,y) b[0][i] = -maxc;
    FOR(i,0,x+1)
        FOR(j,0,y+1) dp[i][j] = dp1[i][j] = -1ll*maxc*maxc;
    dp[1][1] = b[1][1];
    FOR(i,1,x)
        FOR(j,1,y)
        {
            if (i == 1 && j == 1) continue;
            dp[i][j] = max(dp[i][j-1],dp[i-1][j]) + b[i][j];
        }
    dp1[x][y] = b[x][y];
    FORD(i,x,1)
        FORD(j,y,1)
        {
            if (i == x && j == y) continue;
            dp1[i][j] = max(dp1[i+1][j],dp1[i][j+1]) + b[i][j];
        }
    FOR(i,1,x)
        FOR(j,1,y)
            if ((i == 1 && j == 1) || (i == x && j == y));
            else
            {
                long long temp = 0;
                FOR(k,1,i-1)
                    {
                        temp = max(temp,dp[k][j] + dp1[k][j+1]);
                    }
                FOR(k,i+1,x)
                {
                    temp = max(temp,dp[k][j-1] + dp1[k][j]);
                }
                FOR(k,1,j-1)
                    {
                        temp = max(temp,dp[i][k] + dp1[i+1][k]);
                    }
                FOR(k,j+1,y)
                {
                    temp = max(temp,dp[i-1][k] + dp1[i][k]);
                }
                ans = min(ans,temp);
            }
    cout << ans << '\n';
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(Task".inp", "r",stdin);
    freopen(Task".out", "w",stdout);
    cin >> n >> m >> q;
    FOR(i,1,n) FOR(j,1,m) cin >> a[i][j];
    FOR(i,1,q)
    {
        int x,y,u,v;
        cin >> x >> y >> u >> v;
        FOR(i,x,v)
            FOR(j,y,v)
                b[i-x+1][j-y+1] = a[i][j];
        if (n <= 30 && m <= 30 && q <= 30) Sub1(u-x+1,v-y+1);else
        Sub2(u-x+1,v-y+1);
    }
    return 0;
}
