#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);

double a,b;

int main()
{
    //balabalo;
    giuncute;
    cin >> a >> b ;
    if ( a == 0 ) cout <<"vo nghiem";
    else if ( b == 0 ) cout << "vo so nghiem";
        else cout << fixed() << setprecision(2) << -b/a;
    return 0;
}