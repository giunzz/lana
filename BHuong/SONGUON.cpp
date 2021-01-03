#include<bits/stdc++.h>
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
using namespace std;
#define ll long long
string m;
int ok = 0;
bool check(ll y , ll x)
{
    ll s = y;
    while ( y != 0)
    {
        s += y % 10;
        y /= 10;
    }
    if (s == x) return true;
    else return false;
}
void sol1()
{
    ll x = stoi(m);
    for (int i = 90 ; i >= 1; i--)
    {
        if (check(x-i,x) == true ) 
        {
            ok = 1;
            cout << x-i;
            return ;
        }
    }
}
int stringToNum(char c){return c - '0';}
char numToString(int n){return (char)(n+48);}
string tru (string a , string b)
{
    int nho = 0 , s ;
    string c = "";
    while (a.length() < b.length()) a = '0' + a;
    while (b.length() < a.length()) b = '0' + b;
    for (int i = a.length()-1 ; i >= 0 ; i--)
    {
        s = stringToNum(a[i]) - stringToNum(b[i]) - nho;
        if (s < 0) s += 10 , nho = 1;
        else nho = 0;
        c = to_string(s) + c;
    }
    while (c.length() > 0 && c[0] == '0') c.erase(0,1);
    return c;
}
inline bool check2(string x, int y)
{
    int k = 0;
    for (int i = 0 ; i < x.length() ; i++)
    {
        k += x[i]-'0';
    }
    if (k == y) return true;
    else return false;
}

void sol2()
{
    for (int i = 2000 ; i > 0 ; i--)
    {
        string t = to_string(i);
        if (check2(tru(m,t), i) == true)
        {
            ok = 1;
            cout << tru(m,t);
            return ;
        }
    }
}
int main()
{
    giuncute;
    freopen("SONGUON.inp","r",stdin);
    freopen("SONGUON.out","w",stdout);
    cin >> m;
    if (m.length() < 10) sol1();
    else sol2();
    if (!ok) cout << 0;
}