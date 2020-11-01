#include <bits/stdc++.h>
using namespace std;
int n,t,a,b;
map<long long, long long> m;
long long k,MOD,POW,d;
long long BigMul(long long A, long long B, long long K)
{
    A = A % K; B = B % K;
    long long q = (long double)A*B/K;
    long long r = A*B - K*q;
    return r;
}
void PrintRes(long long A, int n)
{
    for (int i = 1; i <= n; i++)
        if ((A >> (n - i)) & 1) cout<<a;
    else cout<<b;
}
int main()
{
    freopen("MODULO.inp","r",stdin);
    freopen("MODULO.out","w",stdout);
    scanf("%d%d",&a,&b);
    scanf("%d%lld",&n,&k);
    MOD = (1 << n); POW = 1;
    for (int i = 1; i <= n; i++);
    int t = n/2;
    for (int i = 1; i <= n - t; i++)
        POW = BigMul(POW,10,MOD);
    for (int stt = 0; stt < (1 << t); stt++)
    {
        d = 0;
        for (int i = 1; i <= t; i++)
        {
            d = BigMul(d,10,MOD);
            if ((stt >> (t - i)) & 1) d = (d + a) % MOD;
            else d = (d + b) % MOD;
        }
        d = BigMul(d,POW,MOD);
        if (m.count(d) == 0) m[d] = stt;
    }
    t = n - t;
    for (int stt = 0; stt < (1 << t); stt++)
    {
        d = 0;
        for (int i = 1; i <= t; i++)
        {
            d = BigMul(d,10,MOD);
            if ((stt >> (t - i)) & 1) d = (d + a) % MOD;
            else d = (d + b) % MOD;
        }
        d = k - d; if (d < 0) d = d + MOD;
        if (m.count(d) > 0)
        {
            PrintRes(m[d],n-t); PrintRes(stt,t);
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
