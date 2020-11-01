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

#define taskname "tree"
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

const int maxn=5005;
const int lim=1e9+5;
int n, root;
int a[maxn], p[maxn], l[maxn], r[maxn];
long long d[maxn][maxn];
long long res=lim;

void enter()
{
    fi >> n;
    fort(i, 1, n) fi >> a[i];
    int u, v;
    fort(i, 1, n-1)
    {
        fi >> u >> v;
        if (!l[u]) l[u]=v;
        else r[u]=v;
        p[v]=u;
    }
    fort(i, 1, n)
    if (!p[i])
    {
        root=i; break;
    }
}

void init()
{
    fort(i, 1, n)
        fort(j, 0, 5000) d[i][j]=-1;

    fort(i, 1, n)
    if (!l[i])
    {
        d[i][0]=a[i]; d[i][1]=abs(a[i]-1);
        fort(j, 2, 5000) d[i][j]=lim;
    }
}

long long stat(int id, int val)
{
    if (d[id][val]>-1) return d[id][val];
    long long ans=lim;
    int u=l[id], v=r[id];
    if (v)
    {
        if (!l[u]) fort(i, 0, min(1, val)) ans=min(ans, stat(u, i)+stat(v, val-i));
        else if (!l[v]) fort(i, val-min(1, val), val) ans=min(ans, stat(u, i)+stat(v, val-i));
        else fort(i, 0, val) ans=min(ans, stat(u, i)+stat(v, val-i));
    } else ans=stat(u, val);
    ans+=abs(a[id]-val);
    d[id][val]=ans;
    return ans;
}

void solve()
{
    init();
    res=lim;
    fort(i, 0, 5000) res=min(res, stat(root, i));
    fo << res;
}

int main()
{
    enter();
    solve();
}
