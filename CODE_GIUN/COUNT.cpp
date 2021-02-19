#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long 
string s;
int main()
{
    giuncute;
    freopen("count.inp","r",stdin);
    freopen("count.out","w",stdout);
    getline(cin,s);
    ll  ans = 0 , i = 0;
    for (int j = 0  ; j < s.size() ; j++)
    {
        if (j && s[j] == s[j-1] && s[j] == '1') i = j;
        ans += j-i+1;
    }
    cout << ans;
}