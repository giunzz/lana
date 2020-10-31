#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int maxN=20;
const int maxM=2011;

typedef pair<int, int> pii;

int m, n, k, xs, ys, zs, maxx;
pii ball[maxM], store[maxN];

int main()
{
    freopen("TEAWORLD.INP", "r", stdin);
    freopen("TEAWORLD.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>m>>n>>k;
    for (int i=1; i<=m; i++)
    {
        int x, y, z, r;
        cin>>x>>y>>z>>r;
        ball[i]=pii(x, r);
    }
    for (int i=1; i<=n; i++)
    {
        int x, y, z, e;
        cin>>x>>y>>z>>e;
        store[i]=pii(x, e);
    }
    cin>>xs>>ys>>zs;
    sort(store+1, store+n+1);
    for (int i=1; i<=n; i++)
        for (int j=i; j<=n; j++)
        {
            int del=0;
            int pos1=min(xs, min(store[i].F, store[j].F));
            int pos2=max(xs, max(store[i].F, store[j].F));
            for (int u=1; u<=m; u++)
            {
                int l=ball[u].F-ball[u].S;
                int r=ball[u].F+ball[u].S;
                if (l<=pos1 && pos2<=r) continue;
                else
                {
                    if (r<pos1) continue;
                    if (pos2<l) continue;
                }
                del++;
            }
            if (del<=k)
            {
                int res=0;
                for (int u=i; u<=j; u++) res+=store[u].S;
                maxx=max(maxx, res);
            }
        }
    cout<<maxx;
    return 0;
}
