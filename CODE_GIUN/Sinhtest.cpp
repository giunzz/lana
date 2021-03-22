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

int main()
{
    srand(time(NULL));
    freopen("giun.inp","w",stdout);
    cout << 10 << endl;
   for (int i = 1 ; i <= 10 ; i++ ) 
   {
       cout << giun(1, 10 ) << " ";
   }
}