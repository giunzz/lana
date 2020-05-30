#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long

ll d1, m1 , y1 , d2 , m2 , y2;

bool nhuan( ll  x)
{
    if ( x % 400 ) return true;
    if ( x % 100 ) return false;
    if ( x % 4  ) return true;
    return false;
}

ll doiso ( ll d , ll m , ll y)
{
    ll t =  ( y - 1) / 4 - (y - 1) / 100 + (y-1) / 400; 
    ll res = t * 366 + (y - 1 - t) *365;
    for (int i = 1 ; i <= m - 1)
    {
        switch (i)
        {
            case 1: 
            case 3:
            case 5: 
            case 7:
            case 8: 
            case 10:
            case 12: 
            res += 31;
            
            
            break;
        
        default:
            break;
        }
    }


}
