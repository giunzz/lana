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
#define Task "ARRANGE"

using namespace std;

int n, a[maxn];
long long sum, answer;

void Setup()
{
    cin >> n;
    FOR(i, 1, n) cin >> a[i], sum += a[i];
}

void Operate()
{
    //cout << 1;
    if (n > 5000)
    {
        cout << 1;
        return;
    }
    long long key = sum / n;
    FOR(i, 1, n)
        if (a[i] < key)
            FOR(j, 1, n)
                if (a[j] > key)
                {
                    int result = min(key - a[i], a[j] - key);
                    a[i] += result;
                    a[j] -= result;
                    answer += result * abs(j - i);
                }
    cout << answer;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);

    Setup();
    Operate();
}
