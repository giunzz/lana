#include <bits/stdc++.h>
#define FILE "ARRANGE"
#define pii pair <int,int>

using namespace std;
const int maxn=1e5+5;

int n, s, mn, ans, a[maxn], IT[4*maxn];

bool cmp(pii a, int val){ return a.first <= val; }

void Init(int l, int r, int id)
{
    if (l == r){ if (a[l] > mn) IT[id] = l; else IT[id] = maxn; return; }
    int g = (l+r) >> 1; Init(l,g,2*id); Init(g+1,r,2*id+1);
    IT[id] = min(IT[2*id],IT[2*id+1]);
}

int Get(int s, int f, int l, int r, int id)
{
    if (l >= s && r <= f) return IT[id];
    if (l >  f || r <  s) return maxn;
    int g = (l+r) >> 1;
    return min(Get(s,f,l,g,2*id),Get(s,f,g+1,r,2*id+1));
}

void Update(int x, int l, int r, int id)
{
    if (l >  x || r <  x) return;
    if (l == r){ IT[id] = maxn; return; }
    int g = (l+r) >> 1; Update(x,l,g,2*id); Update(x,g+1,r,2*id+1);
    IT[id] = min(IT[2*id],IT[2*id+1]);
}

void Hand_1()
{
    Init(1,n,1);
    for (int i=1; i<=n; i++)
        if (a[i] < mn)
        while (a[i] < mn)
        {
            if (Get(i+1,n,1,n,1)-i < i-Get(1,i-1,1,n,1)) loc = Get(i+1,n,1,n,1); else Get(1,i-1,1,n,1);
            int x = a[loc] - mn, y = mn - a[i];
            if (x >  y)
            {
                ans += y*abs(loc-i);
                a[i] = mn; a[loc] -= y;
            }
            else
            {
                ans += x*abs(loc-i); a[i] += x;
                Update(loc,1,n,1);
            }
        }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin >> n; for (int i=1; i<=n; i++){ cin >> a[i]; s += a[i]; }
    mn = s/n;
    if ( !(s%n)) Hand_1();
    return 0;
}
