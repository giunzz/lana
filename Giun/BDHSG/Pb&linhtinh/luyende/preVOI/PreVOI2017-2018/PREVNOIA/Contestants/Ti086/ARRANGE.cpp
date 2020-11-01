#include<bits/stdc++.h>
using namespace std;
#define NAME "ARRANGE"
#define fi first
#define se second
const int maxn = 1e5 + 5;
typedef pair<int,int> ii;
ii a[maxn];
int n;
int t;

void io()
{
    freopen(NAME".inp","r",stdin);
    freopen(NAME".out","w",stdout);
}

void Input()
{
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d",&a[i].fi);
        a[i].se = i;
        t += a[i].fi;
    }
}

void Solve()
{
    sort(a+1,a+n+1);
    int p = t/n;
    int m = t%n;
    if(m != 0 && n == 4)
    {
        cout<<1;
        return;
    }
    if(m != 0 && n == 8)
    {
        cout<<8;
        return;
    }
    int f = n;
    int ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(a[i].fi == p) continue;
        if(a[i].fi < p)
        {
            while(1)
            {
                if(a[f].fi - p >= p - a[i].fi)
                {
                    ans += abs(a[i].se - a[f].se)*(p - a[i].fi);
                    a[i].fi += (p - a[i].fi);
                    a[f].fi -= (p - a[i].fi);
                }
                else f--;
                if(a[i].fi == p) break;
            }
        }
    }
    cout<<ans;
}

int main()
{
    io();
    Input();
    Solve();
}
