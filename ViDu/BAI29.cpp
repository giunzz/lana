#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);

int d , k , a[9]={0};
long long  ans1 , ans2;

int kt ()
{
    ans2 = d;
    for (int j = n-d ; j >= 1 ; j++)
    {
        cerr << a[j];
        ans1 = ans1 * 10 + a[j];
        ans2 = ans2 * 10 + a[j];
    }
    ans2 = ans2 / 10;
    if (  ans2 / ans1 == k ) return 0;
    else return 1;
}

void chonso ()
{
    int i = 8 , nho = 0 , d = 1;
    while ( kt() == 1)
    {
        int tam = (a[i+1] * k + nho)  ;
        int t = tam % 10 ;
        int nho = (tam / 10 );
        a[i] = t ;
        i--;
        d++;
    }
}

int main()
{
    balabalo;
    giuncute;
    cin >> d >> k ;
    if ( d < k ) cout << -1;
    else 
    {
        a[9] = d;
        chonso();
    }

}