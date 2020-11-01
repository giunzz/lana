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

#define taskname "minsum"
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

const int maxn=1e3+5;
const int lim=1e9+5;
int t, a, b;
pair<int, int> l[maxn][maxn];
pair<long long, long long> res;

/*pair<int, int> stat(int u, int v)
{
    if (l[u][v]!=mp(0, 0)) return l[u][v];
    pair<int, int> ans=mp(lim, lim);
    fort(i, 2, max(u, v))
    {
        if (u%i==0 && v%i==0)
        {
            pair<int, int> tmp=stat(u/i, v/i);
            if (ans.fir+ans.sec>tmp.fir+tmp.sec) ans=tmp;
        }
        if (u%i==0 && u!=i)
        {
            pair<int, int> tmp=stat(u/i, v*i);
            if (ans.fir+ans.sec>tmp.fir+tmp.sec) ans=tmp;
        }
        if (v%i==0 && v!=i)
        {
            pair<int, int> tmp=stat(u*i, v/i);
            if (ans.fir+ans.sec>tmp.fir+tmp.sec) ans=tmp;
        }
    }
    l[u][v]=ans;
    return ans;
}*/

pair<long long, long long> stat(long long u, long long v)
{
    bool over=true;
    while (1)
    {
        over=true;
        int tmp=__gcd(u, v);
        if (tmp!=1)
        {
            over=false;
            u/=tmp; v/=tmp;
        }

        fort(i, 2, sqrt(u))
        if (u%i==0)
        {
            if ((u/i)%i==0)
            {
                over=false;
                u=(u/i)/i;
            } else if (u+v>u/i+v*i)
            {
                over=false;
                u/=i;  v*=i;
            }
            if (!over) break;
        }

        fort(i, 2, sqrt(v))
        if (v%i==0)
        {
            if ((v/i)%i==0)
            {
                over=false;
                v=(v/i)/i;
            } else if (u+v>u*i+v/i)
            {
                over=false;
                u*=i; v/=i;
            }
            if (!over) break;
        }

        if (over) break;
    }
    return mp(u, v);
}

void solve()
{
    fi >> a >> b;
    res=stat(a, b);
    fo << res.fir << ' ' << res.sec << '\n';
}

int main()
{
    fi >> t;
    fort(i, 1, t)
    {
        solve();
    }
}
