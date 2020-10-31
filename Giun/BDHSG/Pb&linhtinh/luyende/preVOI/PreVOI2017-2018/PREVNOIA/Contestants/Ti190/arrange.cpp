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

#define taskname "arrange"
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

const int maxn=1e5+5;
int n;
long long a[maxn];
long long s=0;
long long low;
long long res=0;

void enter()
{
    fi >> n;
    fort(i, 1, n)
    {
        fi >> a[i];
        s+=a[i];
    }
}

void solve()
{
    low=s/n;
    fort(i, 1, n)
    if (a[i]>low)
    {
        fort(j, 1, i-1)
        if (a[j]<low)
        {
            long long t=min(a[i]-low, low-a[j]);
            a[i]-=t; a[j]+=t; res+=t*(i-j);
            if (a[i]==low) break;
        }
        if (a[i]==low) continue;
        fort(j, i+1, n)
        if (a[j]<low)
        {
            long long t=min(a[i]-low, low-a[j]);
            a[i]-=t; a[j]+=t; res+=t*(j-i);
            if (a[i]==low) break;
        }
    }
    fo << res;
}

int main()
{
    enter();
    solve();
}
