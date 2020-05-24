#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);

int d , k , a[105] , nho , dem = 0 ;
//unsigned long long b;

/*unsigned long long mu10 (int o )
{
    unsigned long long s = 10;
    for (int i = 2 ; i <= o ; i++) s *= 10;
    return s;
}

int main()
{
    balabalo;
    giuncute;
    cin >> d >> k ;
    int t = k*10-1;
    for (int i = 1 ; i <= 15 ; i++)
    {
        b =  ( d* ( mu10(i) ) - d*k ) / t;
        //cerr << b << " ";
        if ( (( b * 10 + d) * k ) == d*mu10(i) +b )
        {
            cout <<  (b *10 + d);
            return 0;
        }  
    }
    cout << -1;
    return 0;
}*/

int main()
{
   balabalo;
   giuncute;
   cin >> d >> k;
   a[0] = d; 
   nho = 0;
   for (int i = 1 ; i <= 105 ;i++)
   {
       dem ++;
       a[i] = ( a[i-1] * k + nho ) % 10;
       nho  = ( a[i-1] * k + nho ) / 10 ;
       //cerr  << a[i] << " " << nho << endl;
       if ( nho  ==  0  && a[i] == d  ) break;
   }
   for (int j = dem -1 ; j >= 0 ; j--) cout << a[j];
   return 0; 
}

