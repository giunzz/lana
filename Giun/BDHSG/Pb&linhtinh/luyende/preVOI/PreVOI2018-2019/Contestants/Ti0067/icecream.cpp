#include <bits/stdc++.h>

using namespace std;

const int maxN = 305, MOD = 1e9 + 9;
int N, Mmax, m50, m1, m2;
int x[maxN], ans;

void Try()
{
    //for(int i = 1; i <= N; ++i) cerr << x[i] << ' '; cerr << '\n';
    int M50 = m50, M1 = m1, M2 = m2;
    for(int i = 1; i <= N; ++i)
        if(x[i] == 1)
        {
            if(M50 == Mmax) return;
            ++M50;
        }
        else if(x[i] == 2)
        {
            if(M1 == Mmax || M50 == 0) return;
            ++M1, --M50;
        }
        else
        {
            if(M2 == Mmax) return;
            if(M50 && M1) ++M2, --M50, --M1;
            else if(M50 >= 3) ++M2, M50 -= 3;
            else return;
        }
    ++ans;
    if(ans == MOD) ans = 0;
    //cerr << ans << '\n';
}

void BackTrack(int i)
{
    if(i > N)
    {
        Try();
        return;
    }
    for(int j = 1; j <= 3; ++j)
    {
        x[i] = j;
        BackTrack(i + 1);
    }
}

void sub1()
{
    BackTrack(1);
    printf("%d", ans);
}

int F[maxN][3];

void sub2()
{
    for(int i = 1; i <= N; ++i)
    {
        if(m50 < Mmax) F[i][0] = 1;
        else F[i][0] = 0;
        if(m1 < Mmax) F[i][1] = 1;
        else F[i][1] = 0;
        if(m2 < Mmax) F[i][2] = 1;
        else F[i][2] = 0;
        if(m50) F[i][0] += F[i - 1][0] + 1;
        if(m1)
        {
            F[i][1] += F[i - 1][1] + 1;
            if(m50) F[i][2] += F[i - 1][2] + 1;
        }
        else if(m50 >= 3) F[i][2] += F[i - 1][2] + 1;
    }
    int ans = 0;
    for(int k = 0; k < 3; ++k) ans += F[N][k];
    printf("%d", ans);
}

#define DU "icecream"
int main()
{
    freopen(DU".inp", "r", stdin);
    freopen(DU".out", "w", stdout);
    scanf("%d%d", &N, &Mmax);
    scanf("%d%d%d", &m50, &m1, &m2);
    if(N <= 15) sub1();
    else if(N <= 50) sub1();
    else sub1();
}
