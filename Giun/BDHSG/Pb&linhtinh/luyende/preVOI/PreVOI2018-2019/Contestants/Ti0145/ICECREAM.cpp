#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define FOR(i, u, v) for (int i = u; i <= v; i++)
#define FORD(i, v, u) for (int i = v; i >= u; i--)
#define N 302
#define mod 1000000009


using namespace std;

int n, MMAX, M1, M2, M4, TOTAL, LimM1, LimM2, LimM4, ans;
int dp[N][2*N][N];

void inline add(int &A, int B) {A += B; if (A >= mod) A -= mod;}

void Try(int pos, int n1, int n2, int n4)
{
    if (pos > n)
    {
        ans++;
        return;
    }
    if (n1 < MMAX) Try(pos+1, n1+1, n2, n4);
    if (n2 < MMAX && n1 > 0) Try(pos+1, n1-1, n2+1, n4);
    if (n4 < MMAX && n1 > 0 && n2 > 0) Try(pos+1, n1-1, n2-1, n4+1);
    else if (n4 < MMAX && n1 >= 3) Try(pos+1, n1-3, n2, n4+1);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("ICECREAM.INP", "r", stdin);
    freopen("ICECREAM.OUT", "w", stdout);
    cin >> n >> MMAX;
    cin >> M1 >> M2 >> M4;

    //Try(1, M1, M2, M4);
    //cout <<ans<<endl;
    LimM1 = MMAX;
    LimM2 = MMAX;
    if (M2 >= 300) {LimM2 = min(600, 300 + MMAX - M2); M2 = 300;}
    LimM4 = min(300, MMAX - M4); M4 = 0;


    TOTAL = M1 + 2*M2 + 4*M4;
    dp[0][M2][M4] = 1;
    FOR(i, 1, n)
        FOR(n2, 0, LimM2)
            FOR(n4, 0, LimM4)
            {
                int n1 = TOTAL + i - 2*n2 - 4*n4;
                if (n1 < 0 || n1 > LimM1) continue;
                if (n1 > 0) add(dp[i][n2][n4], dp[i-1][n2][n4]);
                if (n2 > 0 && n1 + 1 <= LimM1) add(dp[i][n2][n4], dp[i-1][n2-1][n4]);
                if (n4 > 0)
                {
                    if (n1 + 1 <= LimM1 && n2 + 1 <= LimM2) add(dp[i][n2][n4], dp[i-1][n2+1][n4-1]);
                    if (n1 + 3 <= LimM1 && n2 == 0) add(dp[i][n2][n4], dp[i-1][n2][n4-1]);
                }
            }
    int res = 0;
    FOR(n2, 0, LimM2)
        FOR(n4, 0, LimM4)
            add(res, dp[n][n2][n4]);
    cout <<res;
}
