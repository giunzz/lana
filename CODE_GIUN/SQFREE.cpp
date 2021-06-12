#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
ll n ;

int main()
{
    giuncute;
 //   freopen("giun.inp","r",stdin);
 //   freopen("giun.out","w",stdout);
    cin >> n ; 
    if (n == 2) 
    {
        cout << "NO";
        return 0;
    }
    if (n % 2 == 0 )
    {
        if (n % (2*2) == 0)
        {
            cout << "YES";
            return 0;
        }
        else n /= 2;
    }
    // cerr << n << '\n' ;
    for (ll i = 3 ; i*i <= n ; i += 2)
    {
        if (n % i == 0)
        {
            if (n % (i*i) == 0)
            {
                cout << "YES";
                return 0;
            }
            else n /= i;
        }
    }
    cout << "NO";
}