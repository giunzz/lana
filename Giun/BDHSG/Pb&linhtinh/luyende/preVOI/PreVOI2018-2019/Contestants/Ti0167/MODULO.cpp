//Trương Minh Trí
#include <bits/stdc++.h>
#define FOR(i, x, y) for(int i = x; i <= y; ++i)
#define FORN(i, x, y) for(int i = x; i >= y; --i)
#define Task "MODULO"
#define maxn
#define maxm
#define pii pair <int,int>
#define pll pair <long long, long long>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define reset(x) memset(x, 0, sizeof(x));
#define resett(x,n) FOR(i,1,n) x[i] = 0;
using namespace std;
long long M;
int a[3], n;
int val[65];
map<long long,pii> sd;
long long k;
//-------------------------------------------//
void Check()
{
    long long x = 0;
    FOR(i, 1, n)
    {
        x = x*10+val[i];
        x %= M;
    }
    if(x==k)
    {
        FOR(i, 1, n) cout << val[i];
        exit(0);
    }
}
void Try(int pos)
{
    if(pos == n + 1)
    {
        Check();
        return;
    }
    FOR(i, 1, 2)
    {
        val[pos] = a[i];
        Try(pos+1);
    }
}
void Sub1()
{
    Try(1);
    cout << -1;
}
//-------------------------------------------//
bool bit(int val, int pos)
{
    return ((val>>pos)&1);
}
void Xuli()
{
    long long x = 0;
    FOR(i, 1, n/2)
    {
        x = x*10 + val[i];
        x %= M;
    }
    if(sd[x].F == 0)
    {
        sd[x].F = 1;
        FOR(i, 1, n/2)
            if(val[i] == a[1]) sd[x].S += (1<<(i-1));
    }
}
void Try2(int pos)
{
    if(pos==n/2+1)
    {
        Xuli();
        return;
    }
    FOR(i, 1, 2)
    {
        val[pos] = a[i];
        Try2(pos+1);
    }
}
void Xuli2()
{
    long long x = 0;
    FOR(i, 1, (n+1)/2)
    {
        x = x*10 + val[i];
        x %= M;
    }
    FOR(i, 1, n/2)
    {
        x = x*10;
        x %= M;
    }
    if(x <= k)
    {
        if(sd[k-x].F)
        {
            int cur = sd[k-x].S;
            FOR(i, 1, (n+1)/2) cout << val[i];
            FOR(i, 1, n/2) if(bit(cur, i-1)) cout << a[1];
            else cout << a[2];
            exit(0);
        }
    }
    else
    {
        if(sd[k+M-x].F)
        {
            int cur = sd[k+M-x].S;
            FOR(i, 1, (n+1)/2) cout << val[i];
            FOR(i, 1, n/2) if(bit(cur, i-1)) cout << a[1];
            else cout << a[2];
            exit(0);
        }
    }
}
void Try3(int pos)
{
    if(pos == (n+1)/2+1)
    {
        Xuli2();
        return;
    }
    FOR(i, 1, 2)
    {
        val[pos] = a[i];
        Try3(pos+1);
    }
}
void Sub2()
{
    Try2(1);
    Try3(1);
    cout << -1;
}
//---------------------------------//
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> a[1] >> a[2] >> n >> k;
    M = (1<<n);
    if(n<=20)
        Sub1();
    else
        Sub2();


}
























template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar())) x=x*10+c-48;if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}
