#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
const char chat[] = {'P', 'K', 'H', 'T'};
const string num[] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13"};
map<char, map<string, ll>> cnt;
string s;
ll ok = 0, ans = 0;
int main()
{
    giuncute;
    freopen("giun.inp" ,"r",stdin);
    freopen("giun.out", "w" ,stdout);
    cin >> s;
    for(ll i = 0; i < s.length(); i++){
        ++cnt[s[i]][s.substr(i + 1, 2)];
        if(cnt[s[i]][s.substr(i+1, 2)] > 1){ok = 1; break;}
        i += 2;
    }
    if(ok) {cout << -1; return 0;}
    for (int i = 0 ; i <= 3 ; i++)
    {
        ans = 0;
        for (int j = 0 ; j <= 12 ; j++)
            if(!cnt[chat[i]][num[j]]) ++ans;
        cout << ans << " ";
    }

}