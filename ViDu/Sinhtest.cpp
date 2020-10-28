#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll giun (ll l , ll h)
{
    return l+ ((ll) rand() * (RAND_MAX + 1 ) * (RAND_MAX + 1 ) * (RAND_MAX + 1 ) + 
                (ll) rand() * (RAND_MAX + 1 ) * (RAND_MAX + 1 ) + 
                (ll) rand() * (RAND_MAX + 1 ) +
                rand() )  % (h-l+1);
}


ll giun (ll l , ll r )
{
    
}

int main()
{
    srand(time(NULL));
    freopen("giun.inp","w",stdout);
        cout << giun(1,10000);
}