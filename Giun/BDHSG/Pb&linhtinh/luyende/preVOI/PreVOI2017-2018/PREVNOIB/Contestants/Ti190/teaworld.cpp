#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

#define taskname "teaworld"
#define pb push_back
#define mp make_pair
#define ins insert
#define era erase
#define fort(i,a,b) for(int i=(a); i<=(b); ++i)
#define forl(i,a,b) for(int i=(a); i>=(b); --i)
#define forc(i,c) for(__typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)
#define forcn(i,c) for(__typeof(c.rbegin()) i=c.rbegin(); i!=c.rend(); ++i)
#define fir first
#define sec second

ifstream fi(taskname".inp");
ofstream fo(taskname".out");

const int maxn=2e3+5;
int m, n, k, lim;
int x[maxn], y[maxn], z[maxn], r[maxn];
int tx[maxn], ty[maxn], tz[maxn], e[maxn];
int gx, gy, gz;
int res=0;
int mark[maxn];

void enter()
{
    fi >> m >> n >> k; lim=(1<<n)-1;
    fort(i, 1, m) fi >> x[i] >> y[i] >> z[i] >> r[i];
    fort(i, 1, n) fi >> tx[i] >> ty[i] >> tz[i] >> e[i];
    fi >> gx >> gy >> gz;
}

int get_bit(int x, int k)
{
    return (x>>k)&1;
}

double dis(int x, int y, int u, int v)
{
    return sqrt((x-u)*(x-u)+(y-v)*(y-v));
}

double high(long long a, long long b, int x, int y)
{
    double ts=abs(a*(x-gx)+b*(y-gy)), ms=sqrt(a*a+b*b);
    return ts/ms;
}

void solve()
{
    fort(i, 1, lim)
    {
        int cnt=0, tea=0;
        fort(j, 1, n)
        if (get_bit(i, j-1)==1)
        {
            tea+=e[j];
            long long a=gy-ty[j], b=tx[j]-gx;
            fort(cir, 1, m)
            if (mark[cir]!=i)
            {
                /*if (high(a, b, x[cir], y[cir])>r[cir]) continue;
                //else if (dis(gx, gy, x[cir], y[cir])>r[cir] && dis(tx[j], ty[j], x[cir], y[cir])>r[cir]) continue;
                else*/
                double p=dis(gx, gy, x[cir], y[cir]), q=dis(tx[j], ty[j], x[cir], y[cir]);
                if (high(a, b, x[cir], y[cir])<=r[cir])
                    if ((p<=r[cir] && q>r[cir]) || (p>r[cir] && q<=r[cir]) || (p>r[cir] && q>r[cir]))
                    {
                        mark[cir]=i; ++cnt;
                        if (cnt>k) break;
                    }
            }
            if (cnt>k) break;
        }
        if (cnt<=k) res=max(res, tea);
    }
    fo << res;
}

int main()
{
    enter();
    solve();
}
