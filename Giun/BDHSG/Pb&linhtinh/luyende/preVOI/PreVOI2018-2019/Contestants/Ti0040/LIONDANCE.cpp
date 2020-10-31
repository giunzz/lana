/**Lucky Boy**/
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 4005
#define maxm 500005
#define pii pair <int,int>
#define Task "LIONDANCE"
template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar())) x=x*10+c-48;if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}
using namespace std;
int n,a[maxn],b[maxn],del,dp[501][501][501],tr[501][501][501];
vector <int> rr;
void Sub2()
{
     FORD(i,n,1)
        FORD(j,n,1)
        {
            FOR(k,1,rr.size())
            {
                if (dp[i][j+1][k] > dp[i+1][j][k])
                {
                    dp[i][j][k] = dp[i][j+1][k];
                    tr[i][j][k] = tr[i][j+1][k];
                }
                else
                {
                    dp[i][j][k] = dp[i+1][j][k];
                    tr[i][j][k] = tr[i+1][j][k];
                }
            }
            int k = upper_bound(rr.begin(),rr.end(),a[i]) - rr.begin();
            if (a[i] == b[j])
            {
                FOR(id,1,rr.size())
                    if (abs(rr[id-1] - a[i]) <= del)
                    {
                        if (dp[i+1][j+1][id] + 1 > dp[i][j][k])
                        {
                            dp[i][j][k] = dp[i+1][j+1][id] + 1;
                            tr[i][j][k] = id;
                        }
                        else if (dp[i+1][j+1][id] + 1 == dp[i][j][k])
                        {
                            tr[i][j][k] = id;
                        }
                    }
            }
        }
    int pos = 1;
    FOR(i,2,rr.size())
        if (dp[1][1][i] >= dp[1][1][pos]) pos = i;
    int ans = dp[1][1][pos];
    cout << ans << '\n';
    int down = 1,up = 1;
    FOR(i,1,ans)
    {
        cout << rr[pos-1] << ' ';
        while (a[up] != rr[pos-1]) ++up;
        ++up;
        while (b[down] != rr[pos-1]) ++down;
        ++down;
        pos = 1;
        FOR(i,2,rr.size())
            if (dp[up][down][i] >= dp[up][down][pos]) pos = i;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(Task".inp", "r",stdin);
    freopen(Task".out", "w",stdout);
    cin >> n >> del;
    FOR(i,1,n) cin >> a[i],rr.pb(a[i]);
    FOR(i,1,n) cin >> b[i],rr.pb(b[i]);
    sort(rr.begin(),rr.end());
    rr.resize(unique(rr.begin(),rr.end()) - rr.begin());
    Sub2();
    return 0;
}
