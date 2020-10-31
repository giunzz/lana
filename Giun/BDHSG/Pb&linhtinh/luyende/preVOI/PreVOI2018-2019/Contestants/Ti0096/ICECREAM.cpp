#include <bits/stdc++.h>

using namespace std;

const int maxn = 305, maxM = 1e4 + 5;
int n, mmax, m50, m1, m2;
void zEnter()
{
    scanf("%d%d", &n, &mmax);
    scanf("%d%d%d", &m50, &m1, &m2);
}

int mod = 1e9 + 9;
int ans;

void zBackTrack(int k, int a, int b, int c)
{
    if (k > n)
    {
        ++ans;
        return;
    }
    // 50
    if (a + 1 <= mmax) zBackTrack(k + 1, a + 1, b, c);
    // 1
    if (b + 1 <= mmax && a > 0) zBackTrack(k + 1, a - 1, b + 1, c);
    // 2
    if (c + 1 <= mmax)
    {
        if (a > 0 && b > 0) zBackTrack(k + 1, a - 1, b - 1, c + 1);
        else if (a > 2) zBackTrack(k + 1, a - 3, b, c + 1);
    }
}

void zSolve1()
{
    ans = 0;
    zBackTrack(1, m50, m1, m2);
    printf("%d", ans);
}

void zSolve2()
{
    zSolve1();
}

void zSolve()
{
    if (n <= 15) zSolve1();
    else zSolve2();
}

#define task "ICECREAM"
int main()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    zEnter();
    zSolve();
}
