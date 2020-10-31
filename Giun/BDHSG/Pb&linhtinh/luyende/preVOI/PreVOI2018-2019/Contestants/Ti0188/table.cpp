///TranNhatVu
///Hacker
#include<bits/stdc++.h>

#define el cout<<"\n"
#define fi first
#define file "table"
#define	f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define Fo(i,a,b) for(int i=a;i<=b;i++)
#define lb lower_bound
#define len length()
#define ll long long
#define maxn
#define MOD 1000000007
#define mp make_pair
#define oo 2003012500
#define pb push_back
#define pi acos(-1)
#define pii pair<int,int>
#define reset(x) memset(x,0,sizeof(x))
#define se second
#define sz size
#define ub upper_bound
#define ull unsigned long int

using namespace std;
///declare:
int n, m, k, u, v, p, q, ans, zzz;
int a[305][305], f[305][305];
int tinh (int x, int y)
{
    if (x == p) return zzz - f[x][y] + f[x-1][y+1];
    if (y == q) return zzz - f[x][y] + f[x+1][y-1];
    int s = f[x-1][y] + a[x-1][y+1] + a[x][y+1];
    int t = f[x][y-1] + a[x+1][y-1] + a[x+1][y];
    return f[p][q] - max (f[x][y+1], f[x+1][y]) + max(s, t);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);
    cin >> n >> m >> k;
    f1 (i, n) f1 (j, m) cin >> a[i][j];
    f1 (i, n) f1 (j, m) f[i][j] = max (f[i][j-1], f[i-1][j]) + a[i][j];
    while (k--)
    {
        cin >> u >> v >> p >> q;
        ans = f[p][q] - max (f[u][v-1], f[u-1][v]);
        zzz = ans;
        if (u == p)
        {
            if (q - v > 1) cout << 0;
            else cout << ans;
            el;
            continue;
        }
        if (v == q)
        {
            if (p - u > 1) cout << 0;
            else cout << ans;
            continue;
        }
        int x = p, y = q;
        while (x != u || y != v)
        {
            if (f[x][y-1] > f[x-1][y])
            {
                ans = min (ans, tinh (x, y-1));
                y--;
            }
            else
            {
                if(f[x][y-1] < f[x-1][y])
                {
                    ans = min (ans, tinh (x-1, y));
                    x--;
                }
                else
                {
                    ans = zzz;
                    break;
                }
            }
        }
        cout << ans;
        el;
    }
    return 0;
}
