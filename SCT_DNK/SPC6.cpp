#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
using namespace std;

ll t , m , n ;
char a[50][50];

int main()
{
    giuncute;
    freopen("SPC6.inp","r",stdin);
    freopen("SPC6.out","w",stdout);
    cin >> t;
    int xa , ya ;
    while (t--)
    {
        cin >> n  >> m ;
        for (int i = 1 ; i <= n ; i++)
        {
            for (int j = 1 ; j <= m ; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 'a') xa = i , ya = j; 
            }
        }
        cout << abs (1-xa) + abs (1-ya) << endl;
    }

}