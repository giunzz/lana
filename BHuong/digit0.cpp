#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
using namespace std;
inline ll POW (int x , int n) //  x^n
{
    if (n == 1) return x;
    ll baby = POW(x,n/2);
    if (n % 2 ) return baby*baby*x;
    return baby*baby;
}
inline int calc5 (int n )
{
    int t = 1 , k = 0;
    while ( POW(5,t) <= n )
    {
        t++;
        k += n / POW(5,t);
    }
    return k ;
}
inline int calc2 (int n)
{
    int t1 = 1 , k1 = 0;
    while ( POW(2,t1) <= n )
    {
        k1 += n / POW(2,t1);
        t1++;
    }
    return k1;
}
string  a;
int dd[300]={0};
int main()
{
    giuncute;
    freopen("digit0.inp","r",stdin);
    freopen("digit0.out","w",stdout);
    cin >> a;
    int n = a.size()  ;
    for (int i = 0 ; i < a.size() ; i++) dd[a[i]]++;
    int count5 = 0,  count2 = 0;
    for (int i = 'a' ; i <= 'z' ; i++)
    {
        if (dd[i] != 0) 
        {
            count2  += calc2(dd[i]) ;
            count5  += calc5(dd[i]); 
        }
    }
    cout << min(calc2(n)-count2 , calc5(n) -count5);    
}
//testttttt