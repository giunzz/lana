#include<bits/stdc++.h>
using namespace std;
#define ll long long
stack<ll> a;
string s;

void giuncute()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int prioritize(string x)
{
    if (x == "(") return 0;
    else if (x == "+" || x == "-") return 1;
    else if (x == "x" || x == ":" ) return 2;
}

bool check (char x)
{
    if (x == '(' || x == ')' || x == '+' || x == '-' || x == 'x' || x == ':') return true;
    return false;
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> s;
    cerr << s ;
    for (int i = 0 ; i < s.length() ; i++)
    {
        if ( (check(s[i]) == true) && (check(s[i+1]) == true)) s.insert(i," ");
    }
    cout << s;
}