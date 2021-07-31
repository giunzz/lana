#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;
const ll MOD = 1e9 + 7;
const ll maxn = 1e5 + 3;
ll k , r , m , n ,  ans = 0  , dd[200][200] ={0} , c[200] = {0} , t[200] ={0};
ll sum = 0 ;

struct giun
{
    int x, y, val;
} a[maxn] , b[maxn];


ll p2 (ll i) { return i*i ;}
ll kc(ll i, ll j) 
{
    ll d = p2(a[i].x - b[j].x) + p2(a[i].y - b[j].y);
    return  d;
}

void quaylui (ll vt)
{
    ll tmp[200] , l = 0 ;
    for (int i = t[vt - 1] + 1 ; i + k - vt <= m ; i++ )
    {
        t[vt] = i;
        l = 0 ; 
        for (int j = 1 ; j <= n ; j++)
        {
            if (dd[i][j] == 1 && c[j] == 0)
            {
                c[j] = 1;
                tmp[++l] = j ;
                sum += b[j].val;
            }
        }
        if (vt == k ) ans = max(ans , sum);
        else quaylui(vt+1);
        for (int j = 1 ; j <= l ; j++ ) c[tmp[j]] = 0 , sum -= b[tmp[j]].val;
    }
}

int main()
{
    giuncute;
    freopen("pizza.inp","r",stdin);
    freopen("pizza.out","w",stdout);
    cin >> k >> r >> m ;
    for (int i = 1 ; i <= m ; i++ ) cin >> a[i].x >> a[i].y;
    cin >> n ;
    for (int i = 1 ; i <= n ; i++ ) cin >> b[i].x >> b[i].y >> b[i].val;

    for (int i = 1 ; i <= m ; i++)
        for (int j = 1 ; j <= n ; j++)
            if (kc(i , j) <= r*r) dd[i][j] = 1;
            else dd[i][j] = 0 ;

    quaylui(1);
    cout << ans;
}
