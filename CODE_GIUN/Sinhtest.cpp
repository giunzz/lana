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
    ll n = giun(10,20) , m  = giun(20,22);
    cout << n << " " << m << endl;
    ll t = 1;
    while (t != n) 
    {
        int a = giun(10,20) , b = giun(10,30) , w = giun(12,50);
        if (c[a][b] == 0) 
        {
            cout << a << " " << b << " " << w << endl;
            c[a][b] = 1;
            t++;
        }
    }
}