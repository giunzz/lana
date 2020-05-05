#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

int t , n , x[45] , yy[45]; 

int main()
{
    //balabalo;
    cin >> t;
    x[1] = 1 , yy[1] = 1;
    for (int i = 2 ; i <= 40 ; i++)
    {
        x[i] = x[i-1] * 2;
        yy[i] = x[i] + yy[i-1];
    }
    for (int i = 1 ; i <= t ; i++)
    {
        cin >> n;
        for (int i = 2 ; i <= n ; i++)
        {
            if ( n % yy[i] == 0 )
            {    
                cout << n / yy[i] << endl;
                break;
            }
        }
    }
    return 0;
}