#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
using namespace std;
const ll maxn = 1e4 + 7 ;
string s ;
vector <ll> a;

int main()
{
    giuncute;
    freopen("maths.inp","r",stdin);
    freopen("maths.out","w",stdout);
    cin >> s;
    string tmp = "";
    for (int i =  0 ; i < (int)s.size() ; i++) 
    {
        if (s[i] == '+' ) a.push_back(stoi(tmp.c_str())) , tmp ="";
        else tmp += s[i];
    }
    if (tmp != "") a.push_back(stoi(tmp.c_str()));
    sort(a.begin() , a.end());
    for (int i = 0 ; i < (int) a.size()-1 ; i++) cout << a[i] << '+';
    cout << a[(int) a.size()-1];
}