#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i <= b; i++)
const long long base = 1000000009;
typedef int64_t ll;
using namespace std;

ll n, mmax, c, u1, u2, b[1001], res;

bool kt1(ll d1, ll d2)
{
    if(d1 < 1 || d2 < 1) return false;
    return true;
}

bool kt2(ll d1)
{
    if(d1 < 3) return false;
    return true;
}

void check()
{
    ll c1 = c, uu1 = u1, uu2 = u2;
    For(i, 1, n)
    {
        if(b[i] == 0)
        {
            c1++;
            if(c1 > mmax) return;
        }
        if(b[i] == 1)
        {
            if(c1 == 0) return;
            else
            {
                uu1++, c1--;
                if(uu1 > mmax) return;
            }
        }
        if(b[i] == 2)
        {
            uu2++;
            if(uu2 > mmax) return;
            if(kt1(c1, uu1) && kt2(c1))
            {
                uu1--, c1--;
                continue;
            }
            if(kt1(c1, uu1))
            {
                uu1--, c1--;
                continue;
            }
            if(kt2(c1))
            {
                c1 -= 3;
                continue;
            }
            return;
        }
    }
    res++;
}

void Try(int k)
{
    if(k > n)
    {
        check();
        return;
    }
    For(i, 0, 2)
    {
        b[k] = i;
        Try(k + 1);
    }
}

ll mu[10001];
map<pair<ll, pair<int, int> >, int> dx1;
map<pair<ll, pair<int, int> >, ll> F1;
ll QHD(ll tt, int d1, int d2, int d3, int k)
{
    if(k > n)
    {
        return 1;
    }
    if(dx1[{tt, {d1, d3}}] == 1) return F1[{tt, {d1, d3}}];
    ll aa = 0;
    if((tt / mu[k - 1]) % 2 == 0)
    {
        if(d1 + 1 <= mmax) aa = (aa + QHD(tt + mu[k - 1], d1 + 1, d2, d3, k + 1)) % base;
        if(d2 + 1 <= mmax && d1 > 0) aa = (aa + QHD(tt + mu[k - 1], d1 - 1, d2 + 1, d3, k + 1)) % base;
        if(d3 + 1 <= mmax)
        {
            if(d2 >= 1 && d1 >= 1) aa = (aa + QHD(tt + mu[k - 1], d1 - 1, d2 - 1, d3 + 1, k + 1)) % base;
            else
            {
                if(d1 >= 3) aa = (aa + QHD(tt + mu[k - 1], d1 - 3, d2, d3 + 1, k + 1)) % base;
            }
        }
    }
    F1[{tt, {d1, d3}}] = aa;
    dx1[{tt, {d1, d3}}] = 1;
    return aa;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("icecream.inp", "r", stdin);
    freopen("icecream.out", "w", stdout);
    cin >> n >> mmax;
    mu[0] = 1;
    For(i, 1, n + 1)
    {
        mu[i] = mu[i - 1] * 2;
    }
    For(i, 1, mmax)
        cin >> c >> u1 >> u2;
    if(n <= 10)
    {
        Try(1);
        cout << res;
        return 0;
    }
    else
    {
        cout << QHD(0, c, u1, u2, 1);
        return 0;
    }
}
