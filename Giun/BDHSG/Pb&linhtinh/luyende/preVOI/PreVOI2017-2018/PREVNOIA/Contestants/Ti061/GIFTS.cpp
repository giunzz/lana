#include <bits/stdc++.h>
#define maxn 1000005
#define maxC 1000000007
#define Reset(d, a) memset(d, a, sizeof(d))
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
#define Length(a) int(a.length())
#define Size(a) int(a.size())
#define F first
#define S second
#define Task "GIFTS"

using namespace std;

int n, k, a[maxn];
long long sum[maxn], Max_1[maxn], Max_2[maxn], answer = 1ll * maxC * maxC;

void Setup()
{
    scanf("%d %d", &n, &k);
    FOR(i, 1, n)
    {
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] + a[i] - a[max(0, i - k)];
        Max_1[i] = max(Max_1[i - 1], sum[i]);
    }
    FORD(i, n, 1) Max_2[i] = max(Max_2[i + 1], sum[i]);
}

void Operate()
{
    FOR(i, k, n)
    {
        int k1 = i - k, k2 = i + k;
        long long d = -maxC;
        if (k1 >= k) d = Max_1[k1];
        if (k2 <= n) d = max(d, Max_2[k2]);
        answer = min(answer, d);
    }
    printf("%lld", answer);
}

int main()
{
    freopen(Task".INP", "r", stdin);
    freopen(Task".OUT", "w", stdout);

    Setup();
    Operate();
}
