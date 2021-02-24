#include <bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long 
string s ,t;
ll d[300] ={0} , d1[300]={0} , ans = 0;
int main()
{
    giuncute;
    freopen("hohang.inp","r",stdin);
    freopen("hohang.out","w",stdout);
    cin >> s >> t;
    for (int i = 0 ; i < s.length() ; i++) d[s[i]]++;
    for (int i = 0 ; i < t.length() ; i++) d1[t[i]]++;
    for (int i = 0 ; i < s.length() ; i++)
        if (d1[s[i]] == 0) ans++;
    for (int i = 0 ; i < t.length() ; i++)
        if (d[t[i]] == 0) ans++;
    cout << ans;
}
