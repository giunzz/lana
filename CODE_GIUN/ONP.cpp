#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
int n;
string s ;
stack<char> a;
int pri (char o)
{
    if (o == '^') return 5;
    if (o == '*') return 4;
    if (o == '/') return 3;
    if (o == '+') return 2;
    if (o == '-') return 1;
    return -1;
}
bool OPT (char c )
{
    if ( c == '*' || c == '/' || c == '+' || c == '-' ||  c == '^') return true;
    return false;
}
bool compare (char x , char y)
{
    if (pri(x) >=  pri(y)) return true;
    else return false;
}
int main()
{
    giuncute;
    //freopen("giun1.inp","r",stdin);
    //freopen("giun1.out","w",stdout);
    cin >> n;
    while (n--)
    {
        cin >> s;
        for (int i = 0 ; i < (int) s.length() ; i++)
        {
            if (s[i] >='a' && s[i] <= 'z') cout << s[i];
            else if (s[i] == '(') a.push(s[i]);
            else if (s[i] == ')')
            {
                while (a.top() != '(')
                {
                    cout << a.top();
                    a.pop();
                }
                a.pop();
            }
            else if (OPT(s[i]) == true )
                { 
                    if (OPT(a.top()) == true ) 
                    {
                        if (!a.empty() && compare(s[i],a.top()) == true) 
                        {
                            cout << a.top();
                            a.pop();
                        }
                    }
                    else a.push(s[i]);
                }            
        }
        while (!a.empty()) cout << a.top() ,a.pop();
        cout << endl;
    }
}
