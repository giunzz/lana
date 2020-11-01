#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
const int nmax = 1e5 + 50;
ll n,a[nmax],s,k,kq,t;
queue <ll> q;
set <ll> p;

ll len(int u)
{
    for(int i=u+1; i<=n; i++)
        if(a[i] > t)return i;
    return 0;
}

ll xuong(int u)
{
    for(int i=u-1; i>=1; i--)
        if(a[i] > t)return i;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("ARRANGE.inp","r",stdin);
    freopen("ARRANGE.out","w",stdout);
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    t = s/n;
    if(s % n == 0)k = t;
    else k = t + 1;
    for(int i=1; i<=n; i++)
    {
        if(a[i] < t)q.push(i);
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        int u1 = len(u);
        int u2 = xuong(u);
        ll v = 1e15,vt = -1;
        if(u1 != 0)
        {
            v = abs(u1-u);
            vt = u1;
        }
        if(u2 != 0)
        {
            if(abs(u2 - u) < v)
            {
                v = abs(u2-u);
                vt = u2;
            }
        }
        if(vt == -1)continue;
        ll k = t - a[u];
        ll k1 = min(k,a[vt]-t);
        kq += v*k1;
        a[u] += k1;
        a[vt] -= k1;
        if(a[u] < t)q.push(u);
    }
    for(int i=1; i<=n; i++)
    {
        if(a[i] > k)q.push(i);
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=1; i<=n; i++)
        {
            if(a[u] <= k)break;
            if(a[max(u-i,1)] <= t)
            {
                a[u]--;
                a[max(u-i,1)]++;
                kq += abs(u - max(u-i,1));
            }
            if(a[u] <= k)break;
            if(a[min(u+i,(int)n)] <= t)
            {
                a[u]--;
                a[min(u+i,(int)n)]++;
                kq += abs(u - min(u+i,(int)n));
            }
        }
    }
    cout << kq;

    return 0;
}
