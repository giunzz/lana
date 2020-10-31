/*//-------------------------------//
    *   Coded by FML_PhongVan   *
    * Try hard to escape Bronze *
*///-------------------------------//
#include <bits/stdc++.h>

using namespace std;

int A, B, N;
long long K;
long long CONST;
int Mark[65];
bool ok = false;

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

long long ReadLL()
{
    char ch;
    do ch = getchar();
    while (ch != '-' && ch != '+' && (ch < '0' || ch > '9'));
    int sign = (ch == '-') ? -1 : 1;
    long long res = (ch>='0' && ch<='9') ? ch-'0' : 0;
    ch = getchar();
    while (ch>='0' && ch<='9') {
        res = res*10 + ch-'0';
        ch = getchar();
    }
    return res * (long long) sign;
}

void WriteInt(int x)
{
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}

void Input()
{
    A = ReadInt(); B = ReadInt();
    N = ReadInt(); K = ReadLL();
}

void Backtrack(int k)
{
    if (k > N) {
        long long tmp = 0;
        for (int i = 1; i <= N; ++i) {
            if (Mark[i] == 1) tmp = (tmp * 10 + A) % CONST;
            else tmp = (tmp * 10 + B) % CONST;
        }
        if (tmp == K) {
            for (int i = 1; i <= N; ++i)
            if (Mark[i] == 1) WriteInt(A);
            else WriteInt(B);
            ok = true;
            goto l1;
        }
        return ;
    }
    for (int i = 0; i <= 1; ++i) {
        Mark[k] = i; Backtrack(k + 1);
    }
    l1:; return ;
}

void Solve()
{
    CONST = 1 << N;
    Backtrack(1);
    if (!ok) puts("-1");
}

void Output()
{
    if (N <= 40) Solve();
    else puts("-1");
}

int main()
{
    #define TASK "MODULO"
    #ifdef TASK
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    #else
    freopen("INPUT.INP", "r", stdin);
    #endif // TASK
    Input();
    Output();
}

