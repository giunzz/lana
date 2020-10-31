///TranNhatVu
///Hacker
#include<bits/stdc++.h>

#define el cout<<"\n";
#define fi first
#define file "icecream"
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
int n, m1, m2, m3, mm;
ll dequy(int m1, int m2, int m3, int d)
{
    if (d > n) return 1;
    int ans = 0;
    if (m1 < mm) ans += dequy (m1+1, m2, m3, d+1);
    if (m1 && m2 < mm) ans += dequy (m1-1, m2+1, m3, d+1);
    if (m1 && m2 && m3 < mm) ans += dequy (m1-1, m2-1, m3+1, d+1);
    if (m1 > 2 && m2 == 0 && m3 < mm) ans += dequy(m1-3, m2, m3+1, d+1);
    return ans % MOD;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);
    cin >> n >> mm >> m1 >> m2 >> m3;
    cout << dequy (m1, m2, m3, 1);
    return 0;
}
