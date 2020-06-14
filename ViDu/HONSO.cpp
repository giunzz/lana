#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
const string tenfile = "HONSO";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

int a , b;

long UCLN(long x , long y)
{
        long t = 0 ;
        while ( y  != 0 )
        {
            t = x % y ;
            x = y;
            y = t;
        }
        return x;
}

int main()
{
    balabalo;
    giuncute;
    cin >> a >> b;
    if ( a == 0 ) cout << 0 << " " <<  0 << " " << b;
    else if ( b == 0 ) cout << -1;
        else 
        {
            long c = UCLN( a , b );
            if(!c) c = 1;
            a /= c, b /= c;
            cout << a / b << " " << a - ((a / b) * b) << " " << b; 
        }
    return 0;

}
