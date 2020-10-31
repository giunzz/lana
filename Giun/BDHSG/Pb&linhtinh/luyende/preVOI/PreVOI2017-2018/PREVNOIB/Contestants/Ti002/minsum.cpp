#include <bits/stdc++.h>

using namespace std;
long t;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("minsum.inp", "r", stdin);
    freopen("minsum.out", "w", stdout);
    cin>> t;
    for(long i= 1; i<= t ; i++)
    {
        long a, b;
        cin>> a>> b;
        cout<< a/ __gcd(a, b)<< " "<< b/ __gcd(a, b)<< endl;
    }
    return 0;
}
