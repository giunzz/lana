#include <bits/stdc++.h>

using namespace std;

int ReadInt()
{
    char c;
    for(c = getchar(); c < '0' || c > '9'; c = getchar());
    int ans = c - '0';
    for(c = getchar(); c >= '0' && c <= '9'; c = getchar())
        ans = ans * 10 + c - '0';
    return ans;
}

void WriteInt(int64_t x)
{
    if(x > 9)WriteInt(x / 10);
    putchar(x % 10 + '0');
}

int64_t A, B;

void Enter()
{
    A = ReadInt(); B = ReadInt();
}

int64_t gcd(int64_t a, int64_t b)
{
    while(b)
    {
        int64_t r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void Solve()
{
    int64_t A1, B1;
    do
    {
        A1 = A; B1 = B;
        int64_t d = gcd(A, B);
        A /= d; B /= d;
        for(int i = 1; i <= sqrt(A); ++i)if(A % (i * i) == 0)A /= (i * i);
        for(int i = 1; i <= sqrt(B); ++i)if(B % (i * i) == 0)B /= (i * i);
        for(int i = 1; i <= sqrt(A); ++i)if(A % i == 0 && A / i > B)A /= i, B *= i;
        for(int i = 1; i <= sqrt(B); ++i)if(B % i == 0 && B / i > A)A *= i, B /= i;
    }while(A1 != A || B1 != B);
    WriteInt(A);
    putchar(' ');
    WriteInt(B);
    putchar('\n');
}

#define TASK "minsum"

int main()
{
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int T = ReadInt();
    while(T--)
    {
        Enter();
        Solve();
    }
}
