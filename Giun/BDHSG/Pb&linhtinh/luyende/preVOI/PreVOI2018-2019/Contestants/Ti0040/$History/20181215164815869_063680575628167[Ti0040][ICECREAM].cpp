/**Lucky Boy**/
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 100005
#define maxm 500005
#define pii pair <int,int>
#define Task "ICECREAM"
template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar())) x=x*10+c-48;if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}
using namespace std;
const int mod = 1e9 + 9;
int n,ma,a[4],dp[51][201][201][201],lim[4];
void Add(int &x,int y)
{
    x += y;
    if (x >= mod) x -= mod;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(Task".inp", "r",stdin);
    freopen(Task".out", "w",stdout);
    cin >> n >> ma;
    FOR(i,1,3)
    {
        cin >> a[i];
        lim[i] = min(ma,a[i] + n);
    }
    dp[0][a[1]][a[2]][a[3]] = 1;
    FOR(i,0,n-1)
        FOR(j,0,lim[1])
            FOR(k,0,lim[2])
                FOR(h,0,lim[3])
                {
                    /// mua 50 cent
                    if (j != ma)
                        Add(dp[i+1][j+1][k][h],dp[i][j][k][h]);
                    /// mua 1$
                    if (k != ma && j != 0)
                        Add(dp[i+1][j-1][k+1][h],dp[i][j][k][h]);
                    /// mua 2$
                    if (h != ma)
                    {
                        if (j != 0 && k != 0) Add(dp[i+1][j-1][k-1][h+1],dp[i][j][k][h]);
                        else if (j > 2) Add(dp[i+1][j-3][k][h+1],dp[i][j][k][h]);
                    }
                }
    int ans = 0;
    FOR(i,0,ma)
        FOR(j,0,ma)
            FOR(k,0,ma) Add(ans,dp[n][i][j][k]);
    cout << ans;
    return 0;
}
