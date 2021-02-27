#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
using namespace std;
string s1 , s2;
int main()
{
    giuncute;
    freopen("ghepxau.inp","r",stdin);
    freopen("ghepxau.out","w",stdout);
    cin >> s1 >> s2;
    int n = s2.size() / s1.size() ;
    string s = s1;
    //while (s1.length() != s2.length()) s1.push_back(s1[j]) , j++;
    for (int i = 1 ; i < n ; i++) s1 += s;
    //cerr << n << " " << s1 << " " << s2 << endl;
    if (s1 == s2) cout << n;
    else cout << 0;
}