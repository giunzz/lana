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
    int a = giun(5,20);
    cout << giun(1,20) << " " << a  << endl;
   for (int i = 1 ; i <= a ; i++ ) 
   {
       cout << giun(1, 10 ) << " " << giun(1,10) << " " << giun(1,10) << endl;
   }
}