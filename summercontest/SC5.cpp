#include<bits/stdc++.h>
using namespace std;
const string tenfile = "SC5";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

int a , b , n , t ;
long long ans[100000] ={0};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    balabalo;
    cin >> t;
    for (int i = 1 ; i <= t ; i++)
    {
        cin >> n >> a >> b;
        for (int i = 1 ; i <= n ; i++)
        {
            if ( i % 2 == 0 ) ans[i] = min( ans[i-1] + a , ans[i / 2] + b );
            else ans[i] = ans[i-1] + a;
        }
        cout << ans[n] << endl;
    }
    return 0;
}
