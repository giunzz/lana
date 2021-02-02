#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
int n;
string s;
stack<int> a;
bool checkdau (string x)
{
    if (x == "-" || x == "+" || x == "*" || x == "/" || x == "^") return true;
    else return false;
}
ll giunn (string x)
{
    ll s = 0 ;
    for (int i = 0 ; i < x.length() ; i++) s= s *10 + (x[i]-'0');
    return s;
}
void calc ( string s)
{
    if (checkdau(s) == true)
        {
            x1 = a.top() , a.pop() , x2 = a.top() , a.pop();
            if (s == "+") ans = x1 + x2;
            if (s == "-") ans = x1 - x2;
            if (s == "*") ans = x1 * x2;
            if (s == ":") ans = x1 / x2;
            a.push(ans);
        }
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    while (cin >> s)
    {
        int  ans = 0 ,x1 , x2;

        else if ( s == ")" )  a.push(giunn(s));
    }
    cout << a.top() << endl;
}
