#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define maxn 1000005
#define mp make_pair

using namespace std;
int n,d[maxn],e[maxn],cnt = 0;
void er()
{
    int t = 1;
    while ( t*t <= 1e9 )
    {
        e[++cnt] = t*t;
        t++ ;
    }
}

int chia( int x )
{
    int pos = lower_bound( e + 1, e + cnt + 1, x ) - e;
    while ( x % e[pos] != 0 ) pos --;
    return x / e[pos];
}

void toiuu( int &a, int &b )
{
    a = chia(a);
    b = chia(b);
    if ( a > b ) swap(a,b);
    int k = b/a;
    for ( int i = 2 ; i<=k ; i++ )
    {
        if ( b % i == 0 )
        {
            b = b/i;
            a = a*i;
            break;
        }
    }
}
void g1( int &a, int &b )
{
    int k = __gcd(a,b);
    a = a/k;
    b = b/k;
}
void solve( int a, int b )
{
    g1(a,b);
    while ( 1 )
    {
        int x = a;
        int y = b;
        toiuu(a,b);
        if ( a == x && b == y ) break;
    }
    cout << a << " " << b << "\n";
}

main()
{
    ios_base::sync_with_stdio(0);
    freopen("MINSUM.inp","r",stdin);
    freopen("MINSUM.out","w",stdout);
    er();
    cin >> n;
    for ( int i = 1 ; i<=n ; i++ )
    {
        int a,b;
        cin >> a >> b;
        solve(a,b);
    }
}
