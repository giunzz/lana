#include <bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
int n ;
string x[(int)1e3+7] , ans ="";
bool cpr(string a, string b){
    // cerr << 1 << '\n';
    string t1 = a + b, t2 = b + a;
    return t1 > t2;
}
int main()
{
    giuncute;
    freopen("connect.inp","r",stdin);
    freopen("connect.out","w",stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++)  cin >> x[i];
    // if (x[1]+x[2] > x[2]+x[1]) ans = x[1]+x[2];
    // else ans = x[2]+x[1];
    // for(int i = 1; i <= n; i++) cerr << x[i] << '\n';
    sort(x + 1, x + 1 + n, cpr);
    for(int i = 1; i <= n; i++) cout << x[i];
}
