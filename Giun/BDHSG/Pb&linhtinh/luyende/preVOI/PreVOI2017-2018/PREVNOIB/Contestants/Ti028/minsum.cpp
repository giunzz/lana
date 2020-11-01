#include <bits/stdc++.h>
#define task "minsum"

using namespace std;

int T;

int gcd(int a, int b)
{
    if(a == 0) return 1;
    while(b > 0)
    {
        int r = a % b;
        a = b; b = r;
    }
    return a;
}

bool check(int a)
{
    if(a == 1 || a == 2 || a == 3) return true;
    for(int i = 2; i <= sqrt(a); ++i) if(a % i == 0) return false;
    return true;
}

void sub1()
{
    while(T--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        while(gcd(a, b) > 1)
        {
            int d = gcd(a, b);
            a /= d, b /= d;
        }
        int da, db;
        if(check(a)) da = 1; else da = 0;
        if(check(b)) db = 1; else db = 0;
        if(da && db) printf("%d %d\n", a, b);
        else
        {
            int x = sqrt(a), y = sqrt(b);
            if(x * x == a && y * y == b) printf("1 1\n");
            else
            {
                if(x * x == a && db) printf("1 %d\n", b); else
                if(da && y * y == b) printf("%d 1\n", a);
                else printf("%d %d\n", a, b);
            }
        }
    }
}

void sub2()
{
    sub1();
}

int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    scanf("%d", &T);
    if(T <= 100) sub1();
    else sub2();
}
