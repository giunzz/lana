//Trương Minh Trí
#include <bits/stdc++.h>
#define FOR(i, x, y) for(int i = x; i <= y; ++i)
#define FORN(i, x, y) for(int i = x; i >= y; --i)
#define Task "ICECREAM"
#define maxn 305
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
const int M = 1e9+7;
int res;
int n, mmax, m50, m1, m2;
int a[maxn];
void Check()
{
    int sd1 = m50, sd2 =m1, sd3 = m2;
    FOR(i, 1, n)
    {
        if(a[i]==1)
        {
            if(sd1 + 1 > mmax) return;
            else sd1++;
        }
        else
        if(a[i]==2)
        {
            if(sd2+1 > mmax) return;
            else
            {
                if(sd1 == 0 ) return;
                else sd1--, sd2++;
            }
        }
        else
        if(a[i]==3)
        {
            if(sd3+1 > mmax) return;
            else
            {
                if(sd1>=3)
                {
                    sd1-=3;
                    sd3++;
                }
                else
                if(sd1 > 0 && sd2 > 0)
                {
                    sd1--;
                    sd2--;sd3++;
                }
                else return;
            }
        }
    }
    res++;
    if(res > M) res -= M;
}
void Try(int pos)
{
    if(pos == n + 1)
    {
        Check();
        return;
    }
    FOR(i, 1, 3)
    {
        a[pos] = i;
        Try(pos+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n >> mmax;
    cin >> m50 >> m1 >> m2;
    Try(1);
    cout << res;

}
























template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar())) x=x*10+c-48;if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}
