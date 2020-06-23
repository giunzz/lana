#include<bits/stdc++.h>
using namespace std;
const string tenfile = "DENDUONG";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);

long long a , n;

long long UCLN(long long x , long long y)
{
        long long t = 0 ;
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
    cin >> a >> n ;
    long long s = ( n / UCLN(a,n) ) + 1;
    cout <<  s - 3;
    return 0;
}
