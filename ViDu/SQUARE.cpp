#include<bits/stdc++.h>
using namespace std;
//const string tenfile = "giun";//
//#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
const char x = '*';
int a , b   ;
char r[107][107] ;
int  main()
{
    //balabalo;
    ios_base::sync_with_stdio(0) , cin.tie(0);
    cin >> a >> b;
    for (int i = 1 ; i <= a ; i++)
        for (int j = 1 ; j <= a ; j++) r[i][j] = x;
    if ( b != 0 )
    {
        for (int i = a ; i >= a-b+1 ; i--)
        {
            for (int j = a ; j >= a-b+1 ; j--) r[i][j] =' ';
        }
    }
    for (int i = 1 ; i <= a ; i++) 
    {
        for (int j = 1 ; j <= a ; j++) cout << r[i][j] << " ";
        cout << endl;
    }
    return 0;
}
