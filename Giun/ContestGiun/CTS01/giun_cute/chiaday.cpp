#include<bits/stdc++.h>
using namespace std;
int n , t , a[1008],b[1008];

int UCLN (int x , int y )
{
    int  t;
    while (y != 0 )
    {
        t = x % y;
        x = y;
        y = t;
    }
    return x;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("chiaday.inp","r",stdin);
    freopen("chiaday.out","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> n ;
        for (int i = 1 ; i <= 2*n ; i++) cin >> a[i];
        int i = 1, j = 2 , k = 0 , tam = 1;
        while ( tam <= n - 1 )
        {
            if ( UCLN((a[i] + a[j]) , k ) > 1 )
            {
                k += a[i]+a[j] ;
                b[tam] = a[i] +a[j];
                cout << a[i] << " " << a[j] << endl;
                i++ , j++;
            }
            else j++;
            tam ++;
        }
    }
    return 0;
}
