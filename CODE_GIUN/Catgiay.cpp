#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
const double pi = 3.14159;
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);

double m , n ;
int main ()
{
    balabalo;
    giuncute;
    cin >> m  >> n ;
    cout << fixed <<  setprecision(5)  <<   min (m , n ) / 2 * min (m , n ) / 2  * pi;
    return 0;
}
