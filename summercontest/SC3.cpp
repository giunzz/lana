#include<bits/stdc++.h>
using namespace std;
const string tenfile = "SC3";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

int n , m , x , y , a[100000] ={0} , dem = 0 , t;
int main()
{
    balabalo;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for (int giun = 1 ; giun <= t ; giun++)
    {
        cin >> n >> m;
        for (int i = 1 ; i <= m ; i++) a[i] = 0;
        dem = 0;

        for (int i = 1 ; i <= n ; i++) a[i] = 1;
        for (int i = 1 ; i <= n ; i++)
        {
            cin >> x >> y;
            for (int j =  x ; j <= y ; j++) a[j] = 1;
        }
        for (int i = 1 ; i <= m ; i++)
        {
            if (a[i] != 0) dem ++;
        }
        cout << dem -1 << endl;
        dem = 0;
    }
    return 0;
}
