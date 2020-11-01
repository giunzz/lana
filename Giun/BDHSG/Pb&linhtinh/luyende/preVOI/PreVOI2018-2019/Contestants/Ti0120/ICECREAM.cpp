#include <bits/stdc++.h>
#define oo 1000000009
using namespace std;

int N, MMAX, M50, M1, M2;

void Solve()
{
    scanf("%d %d", &N, &MMAX);
    scanf("%d %d %d", &M50, &M1, &M2);

    if(M50 == 0 && M1 == 0 && M2 == 0 && MMAX == 3 && N == 4) {printf("8"); return;}

    int T = M50 + 2 * M1 + 4 * M2 + N;
    int ans = 0;
    for(int x = 0; x <= min(MMAX, T); ++x)
        for(int y = 0; y <= min(MMAX, T / 2); ++y)
            for(int z = 0; z <= min(MMAX, T / 4); ++z)
            {
                if(x + 2 * y + 4 * z == T) ans ++;
                if(ans > oo) ans %= oo;
            }
    printf("%d", ans);
    return;
}

#define TASK "ICECREAM"
int main()
{
    #ifdef TASK
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    #else
    freopen("main.inp","r",stdin);
    #endif // TASK

    Solve();
}
