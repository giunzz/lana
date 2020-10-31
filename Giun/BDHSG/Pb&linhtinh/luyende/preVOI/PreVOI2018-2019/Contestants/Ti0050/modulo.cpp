#include<bits/stdc++.h>
#define taskname "modulo"
#define int long long
using namespace std;

int A, B, n, k, MOD;
unordered_map<int, int> m;

int getbit(int k, int x)
{
    return (x >> (k - 1)) & 1;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);
    if (ifstream("test.inp"))
    {
        freopen("test.inp", "r", stdin);
        #ifdef CHECKING
            freopen(taskname".out", "w", stdout);
        #else
            freopen("test.out", "w", stdout);
        #endif //CHECKING
    }
    else if (ifstream(taskname".inp"))
    {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }

    cin >> A >> B >> n >> k;
    MOD = 1 << n;
    int n1 = n >> 1;
    for (int i = 0; i < 1 << n1; ++i)
    {
        int hold = 0;
        for (int j = 1; j <= n1; ++j)
            hold = (hold * 10 + ((getbit(j, i))? A : B)) % MOD;
        m[hold] = i + 1;
    }
    int n2 = n - n1;
    for (int i = 0; i < 1 << n2; ++i)
    {
        int hold = 0;
        for (int j = 1; j <= n2; ++j)
            hold = (hold * 10 + ((getbit(j, i))? A : B)) % MOD;
        for (int j = 1; j <= n1; ++j) hold = hold * 10 % MOD;
        int p = m[(k - hold + MOD) % MOD];
        if (p--)
        {
            for (int j = 1; j <= n2; ++j) cout << (getbit(j, i)? A : B);
            for (int j = 1; j <= n1; ++j) cout << (getbit(j, p)? A : B);
            return 0;
        }
    }
    cout << -1;
}
