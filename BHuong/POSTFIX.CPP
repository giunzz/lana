#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
int n;
string s;
stack<int> a;

bool checknum (char x)
{
    if (x >='1' && x >= '9') return true;
    else return false;
}
bool checkdau (char x)
{
    if (x == '-' || x == '+' || x =='*' || x == '/') return true;
    else return false;
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        getline(cin, s);
        int  ans = 0 ,x1 , x2 ,  ok = 0;
        for (int j = 0 ; j < s.length() ; j++)
        {
            if (checknum(s[j]) == true)
            {
                int t = t *10 + stoi(s[j]);
                ok = 1;
            }
            else if (checkdau(s[i] == true))
            {
                x1 = a.top() , x2 = a.top();
                if (s[i] == '+') ans = x1 + x2;
                if (s[i] == '-') ans = x1 - x2;
                if (s[i] == '*') ans = x1 * x2;
                if (s[i] == '/') ans = x2 / x1;
                a.push(ans);
            }
            else if (ok == 1 && s[])
        }
        cout << a.top() << endl;
    }
}
