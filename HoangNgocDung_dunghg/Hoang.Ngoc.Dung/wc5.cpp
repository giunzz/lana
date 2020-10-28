#include<bits/stdc++.h>
using namespace std;
string s, s1;
char c;
int t;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("wc5.inp","r",stdin);
    freopen("wc5.out","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> s >> c >> s1;
        s.pop_back(); 
        s1.pop_back();
        s1.pop_back();
        s += s1;
        cout << s << endl;
    }
}