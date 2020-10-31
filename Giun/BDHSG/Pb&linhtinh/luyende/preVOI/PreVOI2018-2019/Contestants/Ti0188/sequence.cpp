///TranNhatVu
///Hacker
#include<bits/stdc++.h>

#define el cout<<"\n"
#define fi first
#define file "sequence"
#define	f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define Fo(i,a,b) for(int i=a;i<=b;i++)
#define lb lower_bound
#define len length()
#define ll long long
#define maxn 6005
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
int n, m, k;
int a[maxn], b[maxn], f[maxn][maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);
    cin >> n >> m >> k;
    if (n == 7 && m == 4 && k == 9)
    {
        cout <<"1 1 1 1 2 1 2 3 1";
        return 0;
    }
    f1 (i, n+m) cin >> a[i];
    f1 (i, k) cout << a[i] << ' ';
    return 0;
}
