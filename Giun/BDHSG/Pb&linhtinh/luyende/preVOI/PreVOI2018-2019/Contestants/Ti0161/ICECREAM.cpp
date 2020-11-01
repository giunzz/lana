/*********THACH THAO*********/

#include <bits/stdc++.h>
#define maxC 1000000007
#define maxn 307
#define Task "ICECREAM"
#define pii pair <int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

int n, nmax, m50, m1, m2, d[maxn];
long long ans = 0;

void in()
{
    cin >> n >> nmax >> m50 >> m1 >> m2;
}

void check()
{
    int mm50 = m50, mm1 = m1, mm2 = m2;
    for (int i = 1; i <= n; ++i)
    {
        if (d[i] == 0)
        {
            mm50++;
            if (mm50 > nmax) return;
        }
        if (d[i] == 1)
        {
            if (!mm50) return;
            mm1++;
            if (mm1 > nmax) return;
            mm50--;
        }
        if (d[i] == 2)
        {
            if (!mm50 || (!mm1 && mm50 < 3)) return;
            mm2++;
            if (mm2 > nmax) return;
            if (mm1 && mm50 >= 2) mm1--, mm50 -= 2;
                else mm50 -= 3;
        }
    }
    ans = (ans + 1) % maxC;
}

void backtrack(int id)
{
    if (id > n)
    {
        check();
        return;
    }
    for (int i = 0; i <= 2; ++i)
    {
        d[id] = i;
        backtrack(id+1);
    }
}

void solve()
{
    if (n <= 15)
    {
        backtrack(1);
        cout << ans;
    }
    else cout << 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(); cout.tie();
    freopen(Task".INP", "r", stdin);
    freopen(Task".OUT", "w", stdout);
	in();
    solve();
    return 0;
}
