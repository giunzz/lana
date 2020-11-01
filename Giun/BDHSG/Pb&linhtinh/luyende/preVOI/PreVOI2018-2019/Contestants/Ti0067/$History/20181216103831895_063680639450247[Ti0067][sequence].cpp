#include <bits/stdc++.h>
#define num first
#define id second
#define NUM second
#define ID first

using namespace std;
typedef pair <int, int> II;

const int maxN = 3005;
int M, N, K, C[maxN], Ans[maxN];
II A[maxN], B[maxN], Ca[maxN], Cb[maxN];

bool cmp(II a, II b)
{
    return ((a.num < b.num) || (a.num == b.num && a.id > b.id));
}

#define DU "sequence"
int main()
{
    freopen(DU".inp", "r", stdin);
    freopen(DU".out", "w", stdout);
    scanf("%d%d%d", &M, &N, &K);
    for(int i = 1; i <= M; ++i) scanf("%d", &A[i].num), A[i].id = i;
    for(int j = 1; j <= N; ++j) scanf("%d", &B[j].num), B[j].id = j;
    sort(A + 1, A + M + 1, cmp);
    sort(B + 1, B + N + 1, cmp);
    for(int i = 1; i <= K; ++i) Ans[i] = maxN;
    for(int i = 1; i <= M; ++i)
    {
        int j = K - i;
        if(j > N) continue;
        for(int u = 1; u <= i; ++u) Ca[u] = II(A[u].id, A[u].num);
        sort(Ca + 1, Ca + i + 1);
        for(int u = 1; u <= j; ++u) Cb[u] = II(B[u].id, B[u].num);
        sort(Cb + 1, Cb + j + 1);
        int u = 1, v = 1, cnt = 0;
        while(u <= i || v <= j)
            if(u > i) C[++cnt] = Cb[v].NUM, ++v;
            else if(v > j) C[++cnt] = Ca[u].NUM, ++u;
            else if(Ca[u].NUM <= Cb[v].NUM) C[++cnt] = Ca[u].NUM, ++u;
            else C[++cnt] = Cb[v].NUM, ++v;
        //for(int u = 1; u <= K; ++u) cerr << C[u] << ' '; cerr << '\n';
        u = 1;
        while(u <= cnt && C[u] == Ans[u]) ++u;
        if(u > cnt || C[u] > Ans[u]) continue;
        for(; u <= cnt; ++u) Ans[u] = C[u];
    }
    for(int i = 1; i <= K; ++i) printf("%d ", Ans[i]);
}
