#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
char c;
ll t , pos ;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("wc5.inp","r",stdin);
    freopen("wc5.ans","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> s >> pos;
        pos--;
        ll k = pos / s.length();
        if(k % 2) reverse(s.begin(), s.end());
        cout << s[pos % s.length()] << endl;
    }
}