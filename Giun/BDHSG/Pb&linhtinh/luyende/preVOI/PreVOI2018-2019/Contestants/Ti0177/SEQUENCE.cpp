/*//-------------------------------//
    *   Coded by FML_PhongVan   *
    * Try hard to escape Bronze *
*///-------------------------------//
#include <bits/stdc++.h>

using namespace std;

const int maxn = 3005;
const int maxm = 305;

typedef pair<int, int> II;
typedef pair<II, int> III;

int M, N, K;
int a[maxn], b[maxn];
int F[maxm][maxm][maxm];
int G[maxm][maxm][maxm];
III Prev[maxm][maxm][maxm];

int ReadInt()
{
    char ch;
    do ch = getchar();
    while (ch != '-' && ch != '+' && (ch < '0' || ch > '9'));
    int sign = (ch == '-') ? -1 : 1;
    int res = (ch>='0' && ch<='9') ? ch-'0' : 0;
    ch = getchar();
    while (ch>='0' && ch<='9') {
        res = res*10 + ch-'0';
        ch = getchar();
    }
    return res * sign;
}

void WriteInt(int x)
{
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}

void Input()
{
    M = ReadInt(); N = ReadInt(); K = ReadInt();
    for (int i = 1; i <= M; ++i) a[i] = ReadInt();
    for (int i = 1; i <= N; ++i) b[i] = ReadInt();
}

void Solve()
{
    a[0] = 3005; b[0] = 3005;
    for (int i = 1; i <= K; ++i) {
        for (int j = 0; j <= M; ++j) {
            for (int k = 0; k <= N; ++k) {
                if (j == 0 && k == 0) continue;
                if (a[j] <= b[k]) {
                    for (int h = 0; h <= j - 1; ++h) {
                        if (F[i][j][k] < F[i - 1][h][k] + 1) {
                            F[i][j][k] = max(F[i][j][k], F[i - 1][h][k] + 1),
                            Prev[i][j][k] = III(II(h, k), a[j]);
                        }
                        if (F[i][j][k] < G[i - 1][h][k] + 1) {
                            F[i][j][k] = max(F[i][j][k], G[i - 1][h][k] + 1);
                            Prev[i][j][k] = III(II(h, k), a[j]);
                        }
                        if (F[i][j][k] == F[i][h][k]) {
                            if (a[j] > a[h]) Prev[i][j][k] = III(II(h, k), a[h]);
                        }
                        if (F[i][j][k] == G[i][h][k]) {
                            if (a[j] > a[h]) Prev[i][j][k] = III(II(h, k), a[h]);
                        }
                    }
                    //G[i][j][k] = max(G[i][j][k], G[i - 1][j][k]);
                }
                else {
                    for (int h = 0; h <= k - 1; ++h) {
                        if (G[i][j][k] < F[i - 1][j][h] + 1) {
                            G[i][j][k] = max(G[i][j][k], F[i - 1][j][h] + 1);
                            Prev[i][j][k] = III(II(j, h), b[k]);
                        }
                        if (G[i][j][k] < G[i - 1][j][h] + 1) {
                            G[i][j][k] = max(G[i][j][k], G[i - 1][j][h] + 1);
                            Prev[i][j][k] = III(II(j, h), b[k]);
                        }
                        if (G[i][j][k] == G[i][j][h]) {
                            if (b[k] > b[h]) Prev[i][j][k] = III(II(j, h), b[h]);
                        }
                        if (G[i][j][k] == F[i][j][h]) {
                            if (b[k] > b[h]) Prev[i][j][k] = III(II(j, h), b[h]);
                        }
                    //F[i][j][k] = max(F[i - 1][j][k], G[i - 1][j][k]);
                    }
                }
            }
        }
    }
    int posi = 0, posj = 0;
    for (int i = 0; i <= M; ++i) {
        for (int j = 0; j <= N; ++j)
        if (F[K][i][j] == K) {
            if (a[i] <= a[posi]) {
                posi = i;
                if (b[j] <= b[posj]) posj = j;
            }
        }
        else if (G[K][i][j] == K) {
            if (b[j] <= b[posj]) {
                posj = j;
                if (a[i] <= a[posi]) posi = i;
            }
        }
    }
    //cout <<posi<<" "<<posj;
    int u = K, X[K + 5], v, t;
    while (u != 0) {
        X[u] = Prev[u][posi][posj].second;
        v = Prev[u][posi][posj].first.first;
        t = Prev[u][posi][posj].first.second;
        posi = v; posj = t;
        //cout <<v<<" "<<t<<endl;
        u -= 1;
    }
    for (int i = 1; i <= K; ++i) WriteInt(X[i]), putchar(' ');
}

void Subtask0_1()
{
    int X[K + 5];
    int j = 1, k = 1;
    for (int i = 1; i <= K; ++i) {
        if (a[j] < b[k]) X[i] = a[j], ++j;
        else X[i] = b[k], ++k;
        if (j == M && i < K) {
            int p = i +1 ;
            for (k = k; k <= N; ++k) X[p] = b[k], ++p;
            break;
        }
        else if (i == N && i < K) {
            int p = i + 1;
            for (j = j; j <= M; ++j) X[p] = a[j], ++p;
            break;
        }
    }
    for (int i = 1; i <= K; ++i) WriteInt(X[i]), putchar(' ');
}

void Output()
{
    if (M <= 500 && N <= 500) Solve();
    else Subtask0_1();
}

int main()
{
    #define TASK "SEQUENCE"
    #ifdef TASK
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    #else
    freopen("INPUT.INP", "r", stdin);
    #endif // TASK
    Input();
    Output();
}

