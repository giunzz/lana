#include <bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long 

ll t , x1 , x2 , yy1 , y2 ;
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> x1 >> yy1 >> x2 >> y2; 
        cout << __gcd(abs (x1-x2) ,  abs(yy1-y2)) - 1 << endl;
    }
}