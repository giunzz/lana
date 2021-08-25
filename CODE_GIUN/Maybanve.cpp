#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e5 + 7;
using namespace std;
ll n ;
string s , x;
vector<string> a;
char d1[300] = {0};
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> x , a.push_back(x);
    cin >> s;
    for (int i = 0 ; i < a.size() ; i++)
    {
        string x = a[i];
        if (x.substr(0 , s.length()) == s) d1[x[s.size()]] = 1;
    }
    ll cnt = 3 ;
    cout << "*" << "*" << "*";
    for (char i = 'A' ; i  <= 'Z' ; i++ )
    {
        if (d1[i] == 1) cout << i;
        else cout << "*";
        cnt++;
        if (cnt == 8) cout << endl , cnt = 0;
    }
    cout << "*" << "*" << "*";
}