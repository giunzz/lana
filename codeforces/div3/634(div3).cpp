// A

/*#include<bits/stdc++.h>
using namespace std;
int  t   ;
long long n , tam , d = 0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> t;
    for (int i = 1 ; i <= t ; i++)
    {
        cin >> n;
        if ( n % 2 == 0 ) cout << ( n / 2 ) - 1 << endl;
        else cout << n / 2 << endl; 
    }
    
    return 0;
}*/


// B
#include<bits/stdc++.h>
using namespace std;
const int st = (int)'a';
int t, n, a, b, c;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    /*freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);*/
    cin >> t;
    for (int j = 1 ; j <= t ; j++ )
    {
        cin >> n >> a >> b;
        int i = 0;
        while(i < n)
        {
            
            if (i % a < b - 1) cout << (char)(st + (i % a));
            else cout << (char)(st + b - 1);
            ++i;
        }
        cout << endl;
    }
    return 0;
}
  
