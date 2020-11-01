/*//-------------------------------//
    *   Coded by FML_PhongVan   *
    * Try hard to escape Bronze *
*///-------------------------------//
#include <bits/stdc++.h>

using namespace std;

const int maxn = 305;
const long long oo = 1e18;

typedef pair<int, int> II;
typedef pair<long long, II> III;

int M, N, K;
long long ans;
long long Distance[maxn][maxn];
int color[maxn][maxn], a[maxn][maxn];
int X_Top[maxn], Y_Top[maxn];
int X_Bot[maxn], Y_Bot[maxn];
int dh[5] = {0, 0, -1, 0, 1};
int dc[5] = {0, 1, 0, -1, 0};
set<III> s;

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

void WriteLL(long long x)
{
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) WriteLL(x / 10);
    putchar(x % 10 + '0');
}

void Input()
{
    M = ReadInt(); N = ReadInt(); K = ReadInt();
    for (int i = 1; i <= M; ++i)
        for (int j = 1; j <= N; ++j)
            a[i][j] = ReadInt();
    for (int i = 1; i <= K; ++i)
        X_Top[i] = ReadInt(), Y_Top[i] = ReadInt(),
        X_Bot[i] = ReadInt(), Y_Bot[i] = ReadInt();
}

void DIJKSTRA(int i, int x, int y)
{
    s.clear();
    if (x == X_Top[i] && y == Y_Top[i]) {Distance[X_Bot[i]][Y_Bot[i]] = oo; return ; }
    if (x == X_Bot[i] && y == Y_Bot[i]) {Distance[X_Bot[i]][Y_Bot[i]] = oo; return ; }
    for (int j = X_Top[i]; j <= X_Bot[i]; ++j)
        for (int k = Y_Top[i]; k <= Y_Bot[i]; ++k)
            color[j][k] = 0, Distance[j][k] = -oo;
    color[X_Top[i]][Y_Top[i]] = 1; color[x][y] = 2;
    Distance[X_Top[i]][Y_Top[i]] = a[X_Top[i]][Y_Top[i]];
    s.insert(III(-Distance[X_Top[i]][Y_Top[i]], II(X_Top[i], Y_Top[i])));

    while (!s.empty()) {
        II tmp = (*s.begin()).second; s.erase(s.begin());
        int u = tmp.first, v = tmp.second;
        color[u][v] = 2;
        for (int k = 1; k <= 4; ++k) {
            int x = u + dh[k], y = v + dc[k];
                if (x >= X_Top[i] && y >= Y_Top[i] && x <= X_Bot[i] && y <= Y_Bot[i]) {
                if (color[x][y] == 0) {
                    color[x][y] = 1;
                    Distance[x][y] = Distance[u][v] + a[x][y];
                    s.insert(III(-Distance[x][y], II(x, y)));
                }
                else if (color[x][y] == 1 && Distance[x][y] < Distance[u][v] + a[x][y]) {
                    s.erase(III(-Distance[x][y], II(x, y)));
                    Distance[x][y] = Distance[u][v] + a[x][y];
                    s.insert(III(-Distance[x][y], II(x, y)));
                }
            }
        }
    }
}

void Subtask0_1()
{
    for (int i = 1; i <= K; ++i) {
        long long ans = oo;
        for (int j = X_Top[i]; j <= X_Bot[i]; ++j) {
            for (int k = Y_Top[i]; k <= Y_Bot[i]; ++k) {
                DIJKSTRA(i, j, k);
                ans = min(ans, Distance[X_Bot[i]][Y_Bot[i]]);
                //cout <<Distance[X_Bot[i]][Y_Bot[i]]<<endl;
            }
        }
        WriteLL(ans); putchar('\n');
    }
}

void Solve()
{

}

void Output()
{
    Subtask0_1();
}

int main()
{
    #define TASK "TABLE"
    #ifdef TASK
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    #else
    freopen("INPUT.INP", "r", stdin);
    #endif // TASK
    Input();
    Solve();
    Output();
}

