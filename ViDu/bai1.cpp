#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
#pragma GCC optimize("Ofast")
#define ballolo freopen("ucdn.inp","r",stdin),freopen("ucdn.out","w",stdout)
using namespace std;
double dtb;

int main()
{
    giuncute;
    cin >> dtb;
    if (dtb >= 8) cout << "Gioi";
    else if (dtb >= 6.5) cout << "Kha";
    else if (dtb >= 5) cout << "Trung Bình";
    else if (dtb >= 3.5) cout <<"Yeu" ;
    else if (dtb > 0) cout << "Kem ";
}
