#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 30
#define pii pair <int,int>
#define Task "TEAWORLD"
using namespace std;
int n,m,k,ans;
pair <pii,pii> b[2005],a[maxn];
vector <int> can[maxn];
pair <pii,int> s;
bool dd[2005];
bool trong (int x,int y,int a,int b,int c)
{
    return (x-a)*(x-a) +(y-b)*(y-b) <= c*c;
}
bool check(int i,int j)
{
    /*if (trong(s.F.F,s.F.S,b[j].F.F,b[j].F.S,b[j].S.S) && trong(a[i].F.F,a[i].F.S,b[j].F.F,b[j].F.S,b[j].S.S)) return 0;
    if (!trong(s.F.F,s.F.S,b[j].F.F,b[j].F.S,b[j].S.S) && trong(a[i].F.F,a[i].F.S,b[j].F.F,b[j].F.S,b[j].S.S)) return 1;
    if (trong(s.F.F,s.F.S,b[j].F.F,b[j].F.S,b[j].S.S) && !trong(a[i].F.F,a[i].F.S,b[j].F.F,b[j].F.S,b[j].S.S)) return 1;
    int aa = s.F.S - a[i].F.S;
    int bb = a[i].F.F - s.F.F;
    int cc = -aa*s.F.F - bb*s.F.S;
    int temp1 = (b[j].F.F*aa + b[j].F.S*bb+cc);
    int temp2 = (aa*aa+bb*bb);
    int temp3 = b[j].S.S;
    if (b[j].F.F*aa + b[j].F.S*bb+cc == 0)
    {
        if ()
    }
    return 1ll*(b[j].F.F*aa + b[j].F.S*bb+cc)*(b[j].F.F*aa + b[j].F.S*bb+cc) <= 1ll*(aa*aa+bb*bb) * b[j].S.S * b[j].S.S;*/
    if (s.F.F == b[j].F.F - b[j].S.S && a[i].F.F == b[j].F.F + b[j].S.S) return 0;
    if (a[i].F.F == b[j].F.F - b[j].S.S && s.F.F == b[j].F.F + b[j].S.S) return 0;
    if (s.F.F < b[j].F.F - b[j].S.S && a[i].F.F < b[j].F.F - b[j].S.S) return 0;
    if (s.F.F > b[j].F.F + b[j].S.S && a[i].F.F > b[j].F.F + b[j].S.S) return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    freopen(Task".inp", "r",stdin);
    freopen(Task".out", "w",stdout);
    cin >> m >> n >> k;
    FOR(i,1,m) cin >> b[i].F.F >> b[i].F.S >> b[i].S.F >> b[i].S.S;
    FOR(i,1,n) cin >> a[i].F.F >> a[i].F.S >> a[i].S.F >> a[i].S.S;
    FOR(i,1,n)
        FOR(j,1,m)
            if (check(i,j)) can[i].pb(j);
    FOR(i,0,(1 << n) - 1)
    {
        int cnt = 0,temp = 0;
        FOR(j,1,m) dd[j] = 0;
        FOR(j,0,n-1)
            if ((i >> j) & 1)
            {
                temp += a[j+1].S.S;
                for (int v : can[j+1])
                    if (!dd[v]) ++cnt,dd[v] = 1;
            }
        if (cnt <= k) ans = max(ans,temp);
    }
    cout << ans;
    return 0;
}
