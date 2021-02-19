#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
int n;
string s , t;
stack<int> a;
int pri (char o)
{
    if (o == 'x' || o == ':') return 2;
    else if ( o == '+' || o == '-') return 1;
    else if ( o == '(') return 0;
}
bool OPT (char c)
{
    if (c == '(' || c == ')' || c == 'x' || c == ':' || c == '+' || c == '-') return true;
    return false;
}
vector <string> posfix;
void changefix (string g)
{
    char c = g[0],x;
    if (OPT(c) == false) posfix.push_back(t);
    else
    {
        if (c == '(') a.push(x);
        else if (c == 'x' || c == ':' || c == '+' || c == '-' )
        {
            while (!a.empty() && pri(c) <= pri(a.size()) )
            {
                //posfix.push_back(a.size()) ;
                a.pop();
            }
            a.push(c);
        }
        else while (c != ')')
        {
            x = a.top();
         //   if (x != '(') posfix.push_back(x);
        }

    }
}
bool checkdau (string x)
{
    if (x == "-" || x == "+" || x == "x" || x == ":" ) return true;
    else return false;
}
void sol(string s)
{
    int i = 0 ;
    string k = " " + s[0];
    while ( i < s.length())
    {
        if ( s[i] == ' ')
        {
            int  ans = 0 ,x1 , x2;
            if (OPT(k) == true)
            {
                x1 = a.top() , a.pop() , x2 = a.top() , a.pop();
                if (k == "+") ans = x1 + x2;
                if (k == "-") ans = x2 - x1;
                if (k == "x") ans = x1 * x2;
                if (k == ":") ans = x2 / x1;
                a.push(ans);
            }
//            else a.push(s);
            k = " ";
        }
        else k += s[i];
        i++;
    }
    cout << a.top() << endl;
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> s ;
    cerr << s;
    string s1;
    for (int i = 0 ; i < s.length() ; i++)
    {
        if (OPT(s[i]) == true ) s1 += s[i] + " ";
        else s1 += " ";// s.insert(i+1, " ");
         cerr << s1 << endl;
    }
    cerr << s;
    for (int i = 0 ; i < s.length() ; i++)
    {
        if (s[i] != ' ') t += s[i];
        else
        {
            changefix(t);
            t = " ";
        }
    }
    sol(s);
    while (!a.empty()) cout << a.top() , a.pop();

}

