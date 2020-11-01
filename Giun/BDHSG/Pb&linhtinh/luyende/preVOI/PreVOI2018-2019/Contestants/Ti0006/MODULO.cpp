#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i = j; i <= k; i ++)
#define FORD(i,j,k) for(int i = j; i >= k; i --)
using namespace std;
long long res = 0, mun = 1;
int d[45];
map < long long, bool > dg;
map < long long, string > S;
//string S[100000];
string xau = {"0123456789"};
int n, k, a, b;
void xuli()
{
    long long tinh = 0, mu = 1;
    FORD(i,n,1)
    {
        tinh = (tinh + d[i]*mu)%mun;
        mu = (mu*10)%mun;
    }
    if(tinh == k)
    {
        FOR(i,1,n) cout << d[i];
        exit(0);
    }
}
void dequy(int x)
{
    if(x == n + 1) xuli();
    else
    {
        FOR(i,0,1)
        {
            if(i == 0) d[x] = a;
            else d[x] = b;
            dequy(x+1);
        }
    }
}
void xuli1()
{
    long long tinh = 0, mu = 1;
    FOR(i,n/2+1,n)  mu = (mu*10)%mun;
    FOR(i,n/2,1)
    {
        tinh = (tinh + d[i]*mu)%mun;
        mu = (mu*10)%mun;
    }
    if(dg[tinh] == 0)
    {
        dg[tinh] = 1;
        FOR(i,1,n/2)
        S[tinh] = S[tinh] + xau[d[i]];
    }
}
void xuli2()
{
    long long tinh = 0, mu = 1;
    FORD(i,n,n/2+1)
    {
        tinh = (tinh + d[i]*mu)%mun;
        mu = (mu*10)%mun;
    }
    long long kk = k+mun-tinh;
    if(kk == mun) kk = 0;
    if(dg[kk] == 1)
    {
        cout << S[kk];
        FOR(i,n/2+1,n) cout << d[i];
        exit(0);
    }
}
void dequy1(int x)
{
    if(x == n/2+1) xuli1();
    else
    {
        FOR(i,0,1)
        {
            if(i == 0) d[x] = a;
            else d[x] = b;
            dequy1(x+1);
        }
    }
}
void dequy2(int x)
{
    if(x == n + 1) xuli2();
    else
    {
        FOR(i,0,1)
        {
            if(i == 0) d[x] = a;
            else d[x] = b;
            dequy2(x+1);
        }
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("MODULO.inp","r",stdin);
    freopen("MODULO.out","w",stdout);
    cin >> a >> b;
    cin >> n >> k;
    FOR(i,1,n) mun*=2;
    if(n <= 20) dequy(1);
    else
    {
        dequy1(1);
        dequy2(n/2+1);
    }
}
