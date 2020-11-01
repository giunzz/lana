//Trương Minh Trí
#include <bits/stdc++.h>
#define FOR(i, x, y) for(int i = x; i <= y; ++i)
#define FORN(i, x, y) for(int i = x; i >= y; --i)
#define Task "LIONDANCE"
#define maxn 4005
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
int n, dt;
int a[maxn], b[maxn];
int c[maxn], cnt;
//-----------------------------//
int st[maxn], kq[maxn], sz;
bool xuli(int len)
{
    FOR(i, 1, len) if(c[i] > kq[i]) return 1;
    else if(c[i] == kq[i]) continue;
    else if(c[i] < kq[i]) return 0;
    return 0;
}
void Check()
{
    cnt = 0;
    FOR(i, 1, n) if(st[i]) c[++cnt] = a[i];
    if(cnt <2) return;
    int res = 1;
    FOR(i, 1, n) if(b[i]==c[res]) res ++;
    if(res==cnt+1)
    {
        FOR(i, 2, cnt)
            if(abs(c[i] -c[i-1]) >= dt) return;
        if(cnt > sz)
            FOR(i, 1, cnt) kq[i] = c[i], sz = cnt;
        else if(cnt==sz)
            if(xuli(cnt)) FOR(i, 1, cnt) kq[i] = c[i], sz = cnt;
    }
}
void Try(int pos)
{
    if(pos == n + 1)
    {
        Check();
        return;
    }
    FOR(i, 0, 1)
    {
        st[pos] = i;
        Try(pos+1);
    }
}
void Sub1()
{
    sz = 0;
    Try(1);
    cout << sz << "\n";
    FOR(i, 1, sz)
    cout << kq[i] << " ";
}
//------------------------------//
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n >> dt;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];
    Sub1();

}
























template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar())) x=x*10+c-48;if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}
