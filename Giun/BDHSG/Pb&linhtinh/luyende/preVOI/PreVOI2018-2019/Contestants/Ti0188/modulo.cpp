///TranNhatVu
///Hacker
#include<bits/stdc++.h>

#define el cout<<"\n";
#define fi first
#define file "modulo"
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
int a, b, n, k;
ll p[65];
int xuly (int n)
{
    f0 (i, 1<<n)
    {
        ll s = 0;
        f0 (j, n)
        {
            if ((i >> j)&1) s = s*10+a;
            else s = s*10 + b;
        }
        if (s % p[n] == k)return s;
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);
    cin >> a >> b >> n >> k;
    p[0] = 1;
    if (n <= 20)
    {
        f1 (i, n)p[i] = p[i-1] * 2;
        int x = xuly(n);
        if (x + 1)
        {
            cout << x;
            return 0;
        }
        cout << -1;
    }
    else cout << -1;
    return 0;
}
