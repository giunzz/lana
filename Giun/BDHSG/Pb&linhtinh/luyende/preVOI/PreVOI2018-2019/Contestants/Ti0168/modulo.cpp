/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define pii pair<int, int>
#define sz(x) ((int) x.size())
#define PB push_back
#define PF push_front
#define MP make_pair
#define ull unsigned long long
#define F first
#define S second
#define maxc 1000000007
#define MOD 1000000007
#define base 107
#define eps 1e-6
#define pi acos(-1)
#define N 70
#define task "modulo"
#define remain(x) ((x > MOD) ? (x - MOD) : x)

template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar())) x=x*10+c-48;if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}

using namespace std;

int a, b, n, cnt = 0;

long long mod;

ull k;

ull luu[2000006];

bool comp(ull p, ull q)
{
    return (p%mod < q%mod);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    read(a); read(b);//cin >> a >> b;
    read(n); read(k);//cin >> n >> k;
    if (n >= 39) return cout << -1, 0;
    mod = (1ll << n);
    int m = (n+1)/2;
    int Last = (1 << m) - 1;
    FOR(x, 0, Last)
    {
        ull cur = 0;
        FOR(i, 1, m)
            if ((x >> (i-1)) & 1) cur = cur * 10 + a;
                else cur = cur * 10 + b;
        luu[++cnt] = cur;
    }
    sort(luu+1, luu+cnt+1, comp);
    Last = (1 << (n-m)) - 1;
    FOR(x, 0, Last)
    {
        ull cur = 0;
        FOR(i, 1, n-m)
            if ((x >> (i-1)) & 1) cur = cur * 10 + a;
                else cur = cur * 10 + b;
        ull du = cur % mod;
        FOR(i, 1, m) du = (du * 10) % mod;
        ull pos;
        if (k >= du) pos = k - du;
            else pos = mod - du + k;
        int l = 0, r = cnt+1;
        while (r - l > 1)
        {
            int mid = (l + r) >> 1;
            if (luu[mid] % mod <= pos) l = mid;
                else r = mid;
        }
        if (luu[l] % mod == pos)
        {
            if (cur) writep(cur), write(luu[l]);// cout << cur << luu[l];
                else write(luu[l]);//cout << luu[l];
            return 0;
        }
    }
    cout << -1;
    return 0;
}
