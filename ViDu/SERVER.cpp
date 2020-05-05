#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
const int maxn =  1e6+9;
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
 
long long  n , k , t1 ,t2 , s0 , s1 , s2, r  , l = maxn , mid , ans ;

long long tinh( long long x)
{
    if ( x > s2 )
    {
        long long tam = n*2
    }
}


int main()
{
    balabalo;
    ios_base::sync_with_stdio(0);
    cin >> n >> k ;
    r = k;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> t1  >> t2 >> s0 >> s1 >> s2;
        l = min( l , min( t1 , t2) );
    }
    while ( l < r  )
    {
        mid = (l + r) / 2;
        if ( tinh(a[mid]) <= k ) ans = mid , r = mid - 1;
        else l = mid + 1; 
    }
        
}
