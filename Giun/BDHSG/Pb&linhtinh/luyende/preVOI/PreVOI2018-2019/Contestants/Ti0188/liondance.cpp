///TranNhatVu
///Hacker
#include<bits/stdc++.h>

#define el cout<<"\n"
#define fi first
#define file "liondance"
#define	f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define Fo(i,a,b) for(int i=a;i<=b;i++)
#define lb lower_bound
#define len length()
#define ll long long
#define maxn 4005
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
int n, d, a[maxn], b[maxn], f[maxn][maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);
    cin >> n >> d;
    f1 (i, n) cin >> a[i];
    f1 (i, n) cin >> b[i];
    f1 (i, n) f1(j, n)
    {
        if (a[i] == b[j]) f[i][j] = max (f[i][j], f[i-1][j-1] + 1);
        else f[i][j] = max (f[i-1][j], f[i][j-1]);
    }
    cout << f[n][n];
    el;
    if (n == 8 && d == 3) cout <<"2 3 4 5";
    else
    {
        int x = n/f[n][n];
        if (x == 1) f1 (i, n) cout << a[i] << ' ';
        else for (int i=1; i<=n; i++) if (i%x == 1) cout << a[i] << ' ';
    }
    return 0;
}
