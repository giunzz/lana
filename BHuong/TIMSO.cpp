#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
using namespace std;
string s1 , s;
int ans = 0;
int stringToNum(char c){return c - '0';}
int main()
{
    giuncute;
    freopen("TIMSO.inp","r",stdin);
    freopen("TIMSO.out","w",stdout);
    cin >> s1 ;
    for (int  i = 0 ; i < (int) s1.size() ; i++)
    {
        if (s1[i] >= '0' && s1[i] <='9') s += s1[i];
    }
    for (int i = 0 ; i < (int) s.size() ; i++)
    {
        for (int j = i+1 ; j < (int) s.size() ; j++)
        {
            for (int z = j + 1 ; z < (int) s.size() ; z++)
            {
                int t = 100*stringToNum(s[i]) +  10 * stringToNum(s[j]) + stringToNum(s[z]);
                ans = max(ans,t);
 //               cerr << t << " ";
            }
        }
    }
    cout << ans;
}