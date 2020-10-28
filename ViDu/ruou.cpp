#include<bits/stdc++.h>
using namespace std;
string s, a[11] ={ "ABSINTH", "TEQUILA", "VODKA","WHISKEY", "WINE", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE"};
int n, ans = 0;
bool kt (string x)
{
    for (int i = 0 ; i <= 10 ; i++) 
    {
        if (x == a[i]) return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ruou.inp","r",stdin);
    freopen("ruou.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> s;
        if (kt(s) == true) ans++;
        else if (s[0] >= '0' && s[0] <= '9')
            if ( stoi(s) < 18 ) ans++;
    }
    cout << ans;
}