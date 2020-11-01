#include <bits/stdc++.h>
#define task "gifts"
#define maxn int(1e6+5)

using namespace std;

int n, k;
int a[maxn];
int64_t s[maxn];

void sub1()
{
    s[0] = 0;
    for(int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
    int64_t ds = s[n];
    for(int i = 1; i <= n - k + 1; ++i)
    {
        int64_t Cam = s[i + k - 1] - s[i - 1];
        int64_t Tam = 0;
        if(i > k)
            for(int j = 1; j < i - k + 1; ++j)
                Tam = max(Tam, s[j + k - 1] - s[j - 1]);
        if(i + k - 1 < n - k + 1)
            for(int j = i + k; j <= n - k + 1; ++j)
                Tam = max(Tam, s[j + k - 1] - s[j - 1]);
        if(Tam <= Cam) ds = min(ds, Tam);
    }
    printf("%I64d", ds);
}

void sub2()
{
    sub1();
}

int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    if(n <= 5000) sub1();
    else sub2();
}
