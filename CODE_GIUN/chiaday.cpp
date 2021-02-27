#include<bits/stdc++.h>

using namespace std;

int n , a[2209] , t , c = 1 , d[2007];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);freopen("giun.out","w",stdout);
    //freopen("giun.inp","r",stdin);freopen("giun.out","w",stdout);
    cin >> t ;
    while ( t-- )
    {
        for (int i = 1 ; i <= 2000 ; i++) d[i] = 0;
        c= 0;
        cin >> n;
        for (int i = 1 ; i <= 2*n ; i++) cin >> a[i];
        for (int i = 1 ; i <= 2 * n ; i++)
        {
            if ( c  < n - 1 )
            {
            for (int j  = i+1 ; j <= 2*n ; j++) 
                if(((a[i] % 2 == 0 && a[j] % 2 == 0 ) || (a[i] % 2 != 0 && a[j] % 2 != 0) )  &&  (!d[i] && !d[j]))
                    {
                        cout << i << " " << j << endl;
                        d[i] =1  , d[j] = 1;    
                        c++;   
                        break;                          
                    }
            }
            else break;
        }
    }

    return 0;

}