#include <bits/stdc++.h>
using namespace std;
string n ;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);freopen("giun.out","w",stdout);
    //freopen("SNUM.inp","r",stdin);freopen("SNUM.out","w",stdout);
    cin >> n ;
    sort(n.begin() , n.end());
    for (int i  = n.length() - 1 ; i >= 0 ; i--) cout << n[i];
    return 0;
}

