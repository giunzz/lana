#include<bits/stdc++.h>
using namespace std;
const string tenfile = "TAMGIAC";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
double a[5] ,  ans;
int main()
{
    balabalo;
    giuncute;
    cin >> a[1] >> a[2] >> a[3];
    sort(a+1 , a+1+3);
    cout << fixed << setprecision(5) << a[1]+a[2] - a[3];
    return 0;
}
