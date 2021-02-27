#include <bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long 
string s ;
ll  sol(string n)
{
    ll ans = n[n.length()-1] - '0';
    n.erase(n.length()-1,1);
    while (n.length() != 0 )
    {
        ans += n[n.length()-1]-'0';
        n.erase(n.length()-1,1);
    }
    if (ans > 9)
    {
        ostringstream convert;   
        convert << ans;   
        string result = convert.str();   
        return sol(result);
    } 
    return ans;
}
int main()
{
    giuncute;
    freopen("finalnum.inp","r",stdin);
    freopen("finalnum.out","w",stdout);
    cin >> s;
    cout << sol(s);
}