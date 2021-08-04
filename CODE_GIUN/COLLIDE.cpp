#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;
string a , b , a1 , b1;
int main()
{
    giuncute;
    freopen("COLLIDE.inp","r",stdin);
    freopen("COLLIDE.out","w",stdout);
    cin >> a >> b; 
    while (a.size() < b.size()) a = '0' + a;
    while (a.size() > b.size()) b = '0' + b;
    for (int i = 0 ; i < a.size() ; i++)
    {
        if (a[i] == b[i]) a1 += a[i] , b1 += b[i];
        else if (a[i] > b[i]) a1 += a[i];
        else b1 += b[i];
    }
    if (a1.size() == 0) cout << 0 << endl << stoi(b1);
    else if (b1.size() == 0 ) cout << stoi(a1) << endl << 0 ;
    else cout << stoi(a1) << endl << stoi(b1);
}