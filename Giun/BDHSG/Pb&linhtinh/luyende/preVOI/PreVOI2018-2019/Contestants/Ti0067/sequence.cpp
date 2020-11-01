#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef pair <int, int> II;

const int maxN = 3005;
int N, M, K;
int A[maxN], B[maxN];
II f1[maxN][maxN], f2[maxN][maxN];

#define DU "sequence"
int main()
{

    freopen(DU".inp","r",stdin);
    freopen(DU".out","w",stdout);
    scanf("%d%d%d", &M, &N, &K);
    for(int i = 1; i <= M; ++i) scanf("%d", &A[i]);
    for(int j = 1; j <= N; ++j) scanf("%d", &B[j]);
    for(int i = 1; i <= max(M, N); ++i)
    for(int j = i; j <= max(M, N); ++j)
        if(j == i)
        {
            f1[i][i] = II(A[i],i);
            f2[i][i] = II(B[i],i);
        }
        else
        {
            f1[i][j] = min(f1[i][j - 1], II(A[j], j));
            f2[i][j] = min(f2[i][j - 1], II(B[j], j));
        }
    A[0] = B[0] = maxN;
    int p1 = 0, p2 = 0;
    for(int L = 1 ; L <= K; ++L)
    {
        int x = f1[p1 + 1][min(M, N + M + L - K - p2)].Y;
        int y = f2[p2 + 1][min(N, N + M + L - K - p1)].Y;
        if(A[x] <= B[y]) printf("%d ", A[x]), p1 = x;
        else printf("%d ", B[y]), p2 = y;
    }
}
