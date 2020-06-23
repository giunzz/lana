#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
long long n , a[(int)1e6+7] , s = 0;
int main()
{
    ios_base::sync_with_stdio(0) , cin.tie(0);
    balabalo;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        if ( (long long) sqrt(a[i]) ==  sqrt(a[i]) )
        {
            cerr << a[i] << " ";
             s += a[i];
        }
    }
    cout << s;
}