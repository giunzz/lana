#include<iostream>
#include<cstdio>
#define ull unsigned long long
using namespace std;

const int H = 2e7;
int A, B, N;
ull K, base;
bool HaveRes, TLE;
int cnt, S[65];
ull TenPow[65], D[65][10];

void Input()
{
    cin >> A >> B;
    cin >> N >> K;

    base = 1;
    for (int i = 1; i <= N; i++)
        base = base * (ull) 2;
}

void MakeS(int num)
{
    cnt++;
    if (cnt > H)
    {
        TLE = true;
        return;
    }

    if (num == N)
    {
        ull mod = 0;
        for (int i = 0; i < N; i++)
        {
            if ((ull) mod + D[i][S[i]] >= base)
                mod = (ull) mod - base + D[i][S[i]];
            else
                mod = mod + D[i][S[i]];
        }
        if (mod == K)
            HaveRes = true;
        return;
    }

    S[num] = A;
    MakeS(num + 1);
    if (HaveRes || TLE)
        return;
    S[num] = B;
    MakeS(num + 1);
    if (HaveRes || TLE)
        return;
}

ull Mul(ull a, ull b)
{
    if (b == 1)
        return a;
    else if (b == 0)
        return 0;

    ull s = Mul(a, (ull) b / 2);

    if ((ull) 2 * s >= base)
        s = (ull) 2 * s - base;
    else
        s = (ull) 2 * s;

    if (b % 2 == 1)
    {
        if ((ull) s + a >= base)
            s = (ull) s + a - base;
        else
            s = (ull) s + a;
    }

    return s;
}

void Solve()
{
    TenPow[0] = 1;
    for (int i = 1; i < N; i++)
        TenPow[i] = Mul(TenPow[i - 1], 10);

    for (int i = 0; i < N; i++)
    {
        D[i][A] = Mul(TenPow[N - 1 - i], A);
        D[i][B] = Mul(TenPow[N - 1 - i], B);
    }

    cnt = 0;
    S[0] = 0;
    HaveRes = false;
    TLE = false;

    S[0] = A;
    MakeS(1);
    if (HaveRes || TLE)
        return;
    S[0] = B;
    MakeS(1);
    if (HaveRes || TLE)
        return;
}

void Output()
{
    if (!HaveRes)
        cout << -1;
    else
    {
        for (int i = 0; i < N; i++)
            cout << S[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //freopen("test.inp" , "r" , stdin);
    //freopen("test.out" , "w" , stdout);

    freopen("MODULO.INP" , "r" , stdin);
    freopen("MODULO.OUT" , "w" , stdout);

    Input();
    Solve();
    Output();
}

