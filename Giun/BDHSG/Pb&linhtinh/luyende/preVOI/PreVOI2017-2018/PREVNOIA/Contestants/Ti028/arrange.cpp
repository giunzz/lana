#include <bits/stdc++.h>
#define task "arrange"
#define maxn int(1e5+5)

using namespace std;

int n;
int a[maxn];
int64_t s[maxn];

bool check()
{
    int amax = a[1], amin = a[1];
    for(int i = 1; i <= n; ++i)
    {
        amax = max(amax, a[i]);
        amin = min(amin, a[i]);
    }
    if(amax - amin > 1) return false;
    return true;
}

void sub1()
{
    int ds = 0;
    while(!check())
    {
        int m = s[n] / n;
        int amax = a[1], imax = 1;
        for(int i = 1; i <= n; ++i)
            if(amax < a[i]) amax = a[i], imax = i;
        int imin = 1;
        for(int i = 1; i <= n; ++i) if(a[i] < m && imax - i < imax - imin) imin = i;
        int k = min(amax - m, m - a[imin]);
        ds += k * (imax - imin);
        a[imax] -= k;
        a[imin] += k;
    }
    printf("%d", ds);
}

void sub2()
{
    sub1();
}

void sub3()
{
    sub2();
}

int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    s[0] = 0;
    for(int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
    if(s[n] % n == 0) sub1();
    else if(n <= 2000) sub2();
    else sub3();
}
