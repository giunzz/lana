#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
#pragma GCC optimize("Ofast")
#define ballolo freopen("ucdn.inp","r",stdin),freopen("ucdn.out","w",stdout)
using namespace std;
int t,n, ok = 0;

int main()
{
    giuncute;
    cin >> t >> n;
    if (n % 4 == 0 && n % 100 != 0) ok = 1;
    if ( t == 1 || t == 3 || t == 5 || t == 7 || t == 8 || t == 10 || t == 12)  cout << "thang co 31 ngay";
    else if (t == 4 || t == 6 || t == 9 || t == 11 ) cout << "thang co 30 ngay ";
    else if (ok == 1 && t == 2) cout << "thang co 29 ngay ";
    else if (ok == 0 && t == 2)cout << "thang co 28 ngay ";
}

