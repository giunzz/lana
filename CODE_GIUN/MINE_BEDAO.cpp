#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0)
const ll maxn = 7e3+7;
ll n , x , m , y;

int main()
{ 
    giuncute;
    freopen("giun.inp", "r", stdin);
    freopen("giun.out", "w", stdout);
    cin >> n >> m ;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j =  1 ; j <= m ; j++) 
        {
            cin >> x;
            if (x == 1) cout << 0 << " ";
            else cout << 1 << " ";
        }
        cout << endl;
    }
}
    
