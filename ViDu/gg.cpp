#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
int  t , d = 0 ,tam ;
long n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    balabalo;
    cin >> t;
    cerr << t << endl;
    for (int i = 1 ; i <= t ; i++)
    {
        cin >> n;
        cout << n << endl;
        /*cerr << endl;
        tam = n /2;
        for (int i = n ; i >= tam  ; i--)
        {
           if ( i == 2 ) d = 2;
        }
        cout << d ;
        //cerr << d << " ";
        cout << endl;
        d = 0;*/
    }
    return 0;
}