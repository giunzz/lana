#include<bits/stdc++.h>
#define ll long long
const ll maxn = 1e3+7;
using namespace std;

#define ll long long

ll giun (ll l , ll h)
{
    return l+ ((ll) rand() * (RAND_MAX + 1 ) * (RAND_MAX + 1 ) * (RAND_MAX + 1 ) + 
                (ll) rand() * (RAND_MAX + 1 ) * (RAND_MAX + 1 ) + 
                (ll) rand() * (RAND_MAX + 1 ) +
                rand() )  % (h-l+1);
}
int c[maxn][maxn] ={0};
int main()
{
    srand(time(NULL));
    freopen("giun.inp","w",stdout);
    ll n = 10;
    cout << n << endl;
    ll t = 0 , cnt[600] = {0};
    while (t != n)
    {
        int a = giun(1 , 30); 
        if (cnt[a] == 0) cout << a << " "  , cnt[a] = 1 , t++;
    }
    cout << endl;
    t = 0 ;
    memset(cnt , 0 , sizeof cnt);
    while (t != n)
    {
        int a = giun(1 , 30); 
        if (cnt[a] == 0) cout << a << " ",  cnt[a] = 1 , t++;
    }
}