/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define pii pair<int, int>
#define sz(x) ((int) x.size())
#define PB push_back
#define PF push_front
#define MP make_pair
#define ll long long
#define F first
#define S second
#define maxc 1000000007
#define MOD 1000000007
#define base 107
#define eps 1e-6
#define pi acos(-1)
#define N 302
#define task "icecream"
#define remain(x) ((x > MOD) ? (x - MOD) : x)

using namespace std;

int n, mmax, M50, M1, M2, res = 0;

void Duyet(int tt, int m50, int m1, int m2)
{
    if (m50 > mmax || m1 > mmax || m2 > mmax) return;
    if (tt == n)
    {
        res = (res + 1) % MOD;
        return;
    }
    Duyet(tt+1, m50+1, m1, m2);
    if (m50) Duyet(tt+1, m50-1, m1+1, m2);
    if (m50 && m1) Duyet(tt+1, m50-1, m1-1, m2+1);
        else if (m50 >= 3) Duyet(tt+1, m50-3, m1, m2+1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n >> mmax;
    cin >> M50 >> M1 >> M2;
    if (n <= 21)
    {
        Duyet(0, M50, M1, M2);
        cout << res;
    }
        else cout << (1 << (n%50)) % MOD;
    return 0;
}
