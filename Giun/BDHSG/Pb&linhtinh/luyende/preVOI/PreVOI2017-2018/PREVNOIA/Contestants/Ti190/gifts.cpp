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

#define taskname "gifts"
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

const int maxn=1e6+5;
const long long lim=1e15+5;
int n, k;
long long a[maxn];
long long s[maxn], l[maxn], r[maxn];
long long res=lim;

void enter()
{
    fi >> n >> k;
    fort(i, 1, n)
    {
        fi >> a[i];
        s[i]=s[i-1]+a[i];
    }
}

long long sum(int st)
{
    return s[st+k-1]-s[st-1];
}

void init()
{
    l[0]=0; r[n-k+2]=0;
    fort(i, 1, n-k+1) l[i]=max(l[i-1], sum(i));
    forl(i, n-k+1, 1) r[i]=max(r[i+1], sum(i));
}

void solve()
{
    init();
    fort(i, 1, n-k+1)
    {
        long long t=0;
        if (i>k) t=max(t, l[i-1]);
        if (i+k-1<n-k+1) t=max(t, r[i+k]);
        res=min(res, t);
    }
    fo << res;
}

int main()
{
    enter();
    solve();
}
