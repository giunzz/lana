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
inline int calc (int n )
{
    int t = 1 , k = 0;
    while ( POW(5,t) <= n )
    {
        k += n / POW(5,t);
        t++;
    }
    int t1 = 1 , k1 = 0;
    while ( POW(2,t1) <= n )
    {
        k1 += n / POW(2,t);
        t1++;
    }
    return min(k1,k);
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
    int count1 = calc(n) , count2 = 0;
    for (int i = 'a' ; i <= 'z' ; i++)
    {
        if (dd[i] != 0) 
        {
            count2 += calc(dd[i]);
        }
    }
    if (!count2) cout << 0;
    else cout << count1/count2;
}
//testtttt