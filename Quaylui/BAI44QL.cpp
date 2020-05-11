#include<bits/stdc++.h>
using namespace std;
const string tenfile = "bai44ql";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);

int n ;
string ans ;

void TRYY (int vt)
{
    for (int i = 'A' ; i <= 'B' ; i++)
    {
        if ( vt > 0 && ans[vt - 1] == 'B' && i == 'B') continue;
        ans.push_back(i);
        if ( (int) ans.length() == n ) cout << ans << endl;
        else TRYY (vt + 1);
        ans.pop_back();
    }
}

int main()
{
    balabalo;
    giuncute;
    cin >> n ;
    TRYY(0);
}