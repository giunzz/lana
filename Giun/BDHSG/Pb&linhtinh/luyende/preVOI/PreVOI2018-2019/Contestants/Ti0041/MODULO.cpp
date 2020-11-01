#include <bits/stdc++.h>
#define task "MODULO"
#define nmax 1000006
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
int a,b,n;
unsigned long long k, s = 1;
string st = "" , mod ="" , res ="";
string operator +(string a, string b)
{
    int la = a.length(), lb = b.length();
    if (lb > la) return b + a;
    int nho = 0;
    string res(a);
    while(la)
    {
        la--;
        lb--;
        nho = (int(a[la] - '0') + (lb >= 0? int(b[lb] - '0') : 0)) + nho;
        res[la] = char(nho % 10 + '0');
        nho /= 10;
    }
    while (nho)
    {
        if (la) la--;
        else {
            res = "1" + res;
            return res;
        }
        int tmp = nho + res[la];
        res[la] = (res[la] - '0') + (nho % 10);
        nho = tmp;
        nho /= 10;
    }
    return res;
}
string change(unsigned long long x)
{
    string u ="";
    while(x)
    {
        int nho = x %10;
        u = u + char(nho +'0');
        x/=10;
    }
    return u;
}
int demso (string t)
{
    return t.length();
}
bool check(string t)
{
    for (int i = 0 ; i < t.length(); i++)
        if (int(t[i] - '0') != a && int (t[i] - '0') != b) return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin >> a >> b;
    cin >> n >> k;
    if (n == 0)
    {
        cout << -1;
        exit(0);
    }
    for (int i = 1; i <= n; i++) s = s * 2;
    st = change(s);
    mod = change(k);
    res = "0";
    for (int i = 1; i <= 1e9; i++)
    {
        if (demso(res + mod) > n){
            cout << -1;
            exit(0);
        }
        if ((demso(res + mod) == n) && check(res + mod)){
            cout << res + mod;
            exit(0);
        }
        res = res + st;
    }
    cout << -1;
}
