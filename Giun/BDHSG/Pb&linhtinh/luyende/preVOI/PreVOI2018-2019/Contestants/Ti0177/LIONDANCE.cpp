/*//-------------------------------//
    *   Coded by FML_PhongVan   *
    * Try hard to escape Bronze *
*///-------------------------------//
#include <bits/stdc++.h>

using namespace std;

const int maxn = 4005;

int N, D, ds = 0;
int F[maxn][maxn], g[maxn];
int X[maxn], slX = 0;
int a[maxn], b[maxn];
typedef pair<int, int> II;
typedef pair<int, II> III;
II Prev[maxn][maxn], P[maxn];

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
    N = ReadInt(); D = ReadInt();
    for (int i = 1; i <= N; ++i) a[i] = ReadInt();
    for (int j = 1; j <= N; ++j) b[j] = ReadInt();
}

void Subtask0_1()
{
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (a[i] == b[j]) {
                F[i][j] = 1;
                for (int k = 1; k < i; ++k) {
                    for (int h = 1; h < j; ++h) {
                        if (a[k] == b[h] && abs(a[k] - a[i]) <= D) {
                        if (F[i][j] < F[k][h] + 1) {
                            F[i][j] = F[k][h] + 1;
                            Prev[i][j] = II(k, h);
                        }
                        else if (F[i][j] == F[k][h] + 1) {
                            if (a[Prev[i][j].first] < a[k]) {
                                Prev[i][j] = II(k, h);
                            }
                        }
                        }
                    }
                }
            }
        }
    }
    int u = 0, v = 0, z = 0, t = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
    if (ds < F[i][j]) {
        ds = F[i][j];
        u = i; v = j;
    }
    else if (ds == F[i][j] && a[u] < a[i]) {
        u = i; v = j;
    }
    WriteInt(ds); putchar('\n');
    while (u > 0 && v > 0) {
        X[++slX] = a[u];
        t = Prev[u][v].first;
        z = Prev[u][v].second;
        u = t, v = z;
        //cout <<u<<" "<<v<<endl;
    }
    for (int i = slX; i >= 1; --i) WriteInt(X[i]), putchar(' ');
}

void Subtask0_2()
{
    for (int i = 1; i <= N; ++i) {
        pair<int, II> Gmax = III(0, II(0, 0));
        for (int j = 1; j <= N; ++j) {
            if (a[i] == b[j])
                F[i][j] = Gmax.first + 1, Prev[i][j] = Gmax.second;
            else F[i][j] = 0;
            if (b[j] < a[i] && abs(b[j] - a[i]) <= D) {
                if (Gmax.first < g[j]) {
                    Gmax.first = g[j];
                    Gmax.second = P[j];
                }
            }
        }
        for (int j = 1; j <= N; ++j)
            if (g[j] < F[i][j]) {
                g[j] = max(g[j], F[i][j]);
                P[j] = II(i, j);
            }
    }
    int u = 0, v = 0, z = 0, t = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
    if (ds < F[i][j]) {
        ds = F[i][j];
        u = i; v = j;
    }
    else if (ds == F[i][j] && a[u] < a[i]) {
        u = i; v = j;
    }
    WriteInt(ds); putchar('\n');
    while (u > 0 && v > 0) {
        X[++slX] = a[u];
        t = Prev[u][v].first;
        z = Prev[u][v].second;
        u = t, v = z;
        //cout <<u<<" "<<v<<endl;
    }
    for (int i = slX; i >= 1; --i) WriteInt(X[i]), putchar(' ');
}

void Output()
{
    if (N <= 100) Subtask0_1();
    else Subtask0_2();
}

int main()
{
    #define TASK "LIONDANCE"
    #ifdef TASK
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    #else
    freopen("INPUT.INP", "r", stdin);
    #endif // TASK
    Input();
    Output();
}

