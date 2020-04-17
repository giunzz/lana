#include<bits/stdc++.h>
using namespace std;
const string tenfile = "SC4";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

long long  t , n ,m , x , s ;
double k;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    balabalo;
    cin >> t;
    for (int i = 1 ; i <= t ; i++)
    {
        cin >> x >> n >> m ;
        k =  pow( x , n+1 ) -1  ;
        s = k / ( x-1 );
        cout << s % m << endl; 
    }
    return 0;
}