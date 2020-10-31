#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i <= b; i++)
typedef int64_t ll;
using namespace std;

ll a, b, n, k, mu[100001];
int b1[1001];
void check()
{
    ll aa = 0;
    if(b1[1] == 0) aa = a;
    else aa = b;
    For(i, 2, n)
    {
        if(b1[i] == 0) aa = (aa * 10 + a) % mu[n];
        else aa = (aa * 10 + b) % mu[n];
    }
    if(aa == k)
    {
        For(i, 1, n)
        {
            if(b1[i] == 0) cout << a;
            else cout << b;
        }
        exit(0);
    }
}

void Try(int ss)
{
    if(ss > n)
    {
        check();
        return;
    }
    For(i, 0, 1)
    {
        b1[ss] = i;
        Try(ss + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("modulo.inp", "r", stdin);
    freopen("modulo.out", "w", stdout);
    cin >> a >> b >> n >> k;
    mu[0] = 1;
    For(i, 1, n + 1)
        mu[i] = mu[i - 1] * 2;
    Try(1);
}
