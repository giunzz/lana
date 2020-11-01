#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
typedef unsigned long long ull;
ull n, a[maxn], k, s[maxn];
const ull inf = 1e16;
int read_int()
{
    int kq = 0, sign = 1;
    char c = getchar();
    while (c <'0' || c >'9')
    {
        if (c == '-')
            sign = -1;
        c = getchar();
    }
    while (c>='0' && c <='9')
        kq = kq*10+c-'0', c= getchar();
    return kq*sign;
}
ull t[maxn], p[maxn];
void sub1()
{
    ull minn = inf;
    ull maxx =  0;
    for (int i = 1; i<=n; i++)
    {
        maxx = max(maxx, s[max((ull)0,i-k)]);
        t[i] = maxx;
    }
    maxx = 0;
    for (int i = n; i>0; i--)
    {
        maxx = max(maxx, s[min(n+1, i+k)]);
        p[i] = maxx;
    }
    for (int i = 1; i<=n; i++)
        /*cout << t[i]  << " " << p[i] << endl, */minn = min(minn, max(t[i], p[i]));
    //cout << endl;
    cout << minn;
}

void sub2()
{
    sub1();
}

int main()
{
    freopen("GIFTS.INP", "r", stdin);
    freopen("GIFTS.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    n = read_int();
    k = read_int();
    for (int i=1 ; i<=n; i++)
        a[i] = read_int(), s[i] = s[i-1]+a[i]-a[i-k];
    /*for (int i = 1; i<=n; i++)
        cout << s[i] << " ";
    cout << endl;*/
    if (n <= 5000)
        sub1();
    else
        sub2();
    return 0;
}
