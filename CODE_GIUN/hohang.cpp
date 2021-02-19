#include <bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long 
string s ,t;
ll d[300] ={0} , d1[300]={0} , ans = 0;
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> s >> t;
    for (int i = 0 ; i < s.length() ; i++) d[int(s[i])]++;
    for (int i = 0 ; i < t.length() ; i++) d1[int(t[i])]++;
    for (int i = 0 ; i < max(t.length(),s.length()) ; i++)
    {
        cout << 1;
        if (d[t[i]] == 0 ) ans++;
        if (d1[s[i]] == 0) ans++;
    } 
    cout << ans;
}
