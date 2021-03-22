#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define giuncute  ios_base::sync_with_stdio(0),cin.tie(0); cout.tie(0);
using namespace std;
ll t , n  ;
int main()
{
    giuncute;
    freopen("SC2.inp","r",stdin);
    freopen("SC2.out","w",stdout);
    cin >> t;
    while (t--)
    {
        ll a = 0 , b = 1;
        cin >> n ;
        if (n == 1 || n == 2) cout << n-1 << endl;
        else 
        {
            for (int i = 3 ; i <= n ; i++)
            {
                ll tmp = ((i-1)*(a+b)) % 1000000007  ;
                a = b;
                b = tmp ;
            }
            cout << b  << endl;
        }
    }
}