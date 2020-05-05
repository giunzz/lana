#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

int n , m , x , y , a[1000]  , dem , t , b[1000] ;
int main()
{
    balabalo;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for (int giun = 1 ; giun <= t ; giun++)
    {
        dem = 0;
        cin >> n >> m;
        for (int i = 1 ; i <= 1000 ; i++) b[i] = 0 , a[i] = 0;
        for (int i = 1 ; i <= n ; i++) a[i] = 1;
        for (int i = 1 ; i <= n ; i++)
        {
            cin >> x >> y;
            for (int j =  x ; j <= y ; j++) a[j] = i;
        }
        for (int i = 1 ; i <= m ; i++) b[a[i]]++;
        for (int i = 1 ; i <= m ; i++)
        {
            if ( b[i] != 0 ) dem++;
        }
        cout << dem  << endl;
    }
    return 0;
}
