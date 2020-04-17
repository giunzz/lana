#include<bits/stdc++.h>
using namespace std;
const string tenfile = "SC2";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

int t , n , k ;
long long C , a , b , d , e;

long long  giaiThua(int q)
{   long long s = 1;
    for(int i = 1 ; i <= q ; i++ ) s *= i;
    return s;
}

int tach (long long x)
{
    int dem = 0;
    while ( x % 10 == 0)
    {
        dem ++;
        x = x / 10;
       
    }
    return dem;
}

int main()
{
    balabalo;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    cerr << t << endl;
    for (int i = 1 ; i <= t ; i++)
    {
        cin >> n >> k;
        a = giaiThua(k) ;
        b = giaiThua (n-k);
        d = a*b;
        e = giaiThua(n);
        C = e / d;
        cerr << C << endl;
        cout << tach(C) << endl;
    }
    return 0;
}