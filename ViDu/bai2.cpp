#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
#pragma GCC optimize("Ofast")
#define ballolo freopen("ucdn.inp","r",stdin),freopen("ucdn.out","w",stdout)
using namespace std;
int t;

int main()
{
    giuncute;
    cin >> t;
    if ( t == 1 || t == 3 || t == 5 || t == 7 || t == 8 || t == 10 || t == 12)  cout << "thang co 31 ngay";
    else if (t == 4 || t == 6 || t == 9 || t == 11 ) cout << "thang co 30 ngay ";
    else cout << "thang co 28 ngay ";
}
