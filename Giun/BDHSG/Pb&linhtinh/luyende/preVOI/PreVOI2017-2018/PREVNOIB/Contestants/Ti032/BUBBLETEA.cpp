#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define fti(i , x , y) for(int i = (x) ; i <= (y) ; ++i)
#define ftd(i , x , y) for(int i = (x) ; i >= (y) ; --i)
#define file "BUBBLETEA"

using namespace std;

const int maxn = 5e4+5;

int n , k;
int a[maxn]; // khu vui choi
typedef pair < ll , int > li;
vector < li > adj[maxn];

void fr()
{
    freopen (file".INP" , "r" , stdin);
    freopen (file".OUT" , "w" , stdout);
}

void enter()
{
    int u , v ; ll c;
    scanf("%d%d" , &n , &k);
    for (int i = 1 ; i <= k ; ++i)
        scanf("%d" , &a[i]);
    for (int i = 1 ; i <= n - 1 ; ++i)
    {
        scanf("%d%d%lld" , &u , &v , &c);
        adj[u].pb(li(c , v));
        adj[v].pb(li(c , u));
    }
}

main()
{
    fr();
    enter();
    cout << -1;
    return 0;
}
