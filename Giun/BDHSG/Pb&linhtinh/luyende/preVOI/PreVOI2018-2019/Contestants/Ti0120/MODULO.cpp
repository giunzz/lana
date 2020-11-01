#include <bits/stdc++.h>

using namespace std;

int64_t A, B, N, K, C, D;

int64_t calc(int64_t x)
{
    if(x == 0) return 1;
    for(int i = 1; i <= N; ++i)
        if((x >> (i - 1)) & 1)
        {
            int64_t y = x ^ (1 << (i - 1));
            int64_t T = calc(y);
            T = ((1 << (N - i)) + T) % C;
            if((D - T) % C == K) return x;
        }
    return -1;
}

void Solve()
{
    scanf("%I64d %I64d %I64d %I64d", &A, &B, &N, &K);

    C = 1 << N;
    if(A > B) swap(A, B);
    D = (B % C * (C - 1)) % C;
    int64_t a = calc((1 << N) - 1);
    if(a == -1)
    {
        printf("%I64d", A);
        for(int i = 1; i <= N - 1; ++i) printf("%I64d", B);
    }
    else
        for(int i = 0; i <= N - 1; ++i)
            if((a >> i) & 1) printf("%I64d", A);
            else printf("%I64d", B);
}

#define TASK "MODULO"
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
