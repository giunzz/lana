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
    ll n = 100 ;
    cout << n <<  endl;
    for (int i = 1 ; i <= n ; i++)
    {
            int a = giun(1 , 2000); 
            cout << giun(1,20) << " " << a << " " <<  giun (1,20) << endl;
    }
}