#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n;
double tmp,de ;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("giun.inp","r", stdin);freopen("giun.out","w",stdout);
    freopen("EQT.inp","r", stdin);freopen("EQT.out","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> n >> de;
        tmp =  (double)(2 + n * de) / 2;
        cout << setprecision(5) << fixed << tmp << endl ;
    }
    return 0;
}
