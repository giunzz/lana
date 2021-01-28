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
ll POW (int a,int b)
{
    if (b == 0) return 1;
    ll baby = POW(a,b/2);
    ll res = baby*baby;
    if (b%2) return res*a;
    else return res;
}

int main()
{
    giuncute;
    freopen("POSTFIX.inp","r",stdin);
    freopen("POSTFIX.out","w",stdout);
    while (cin >> s)
    {
        int  ans = 0 ,x1 , x2;
        if (checkdau(s) == true)
        {
            x1 = a.top() , a.pop() , x2 = a.top() , a.pop();
            if (s == "+") ans = x1 + x2;
            if (s == "-") ans = x2 - x1;
            if (s == "*") ans = x1 * x2;
            if (s == "/") ans = x2 / x1;
            if (s == "^") ans = POW(x2,x1);
            a.push(ans);
        }
        else a.push(giunn(s));
    }
    cout << a.top() << endl;
}
