#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
const ll maxn = 3e3 +  7;
using namespace std;
ll n , t , x[maxn] , ok = 0;
string a , b , c , s ;

void quaylui(ll vt)
{
    if (vt == s.size()) 
    {
        string tmp ="";
        for (int i = 0 ; i < s.size() ; i++)
            if (x[i] == 1) tmp += s[i];
        if (tmp == c) ok = 1;
    }
    else 
    {
        for (int i = 0 ; i <= 1 ; i++)
        {
            x[vt] = i;
            quaylui(vt + 1);
            if (ok == 1) {break;}
        }
    }
}

int main()
{
    giuncute;
    freopen("ac1.inp" ,"r",stdin);
    freopen("ac1.out", "w" ,stdout);
    cin >> t;
    while (t --)
    {
        cin >> a >> b >> c;
        s = "";
        ll dd[maxn] ={0} , d1[maxn] ={0};
        for (int i = 0 ; i < c.size() ; i++)
        {
            for (int j = 0 ; j < a.size() ; j++)
            {
                if (dd[j] == 1) continue;
                if (a[j] == c[i]) s += a[j] , dd[j] = 1;
            }
        }
        for (int i = 0 ; i < c.size() ; i++)
        {
            for (int j = 0 ; j < b.size() ; j++)
            {
                if (d1[j] == 1 ) continue;
                if (b[j] == c[i] && a[j] != b[j]) s += b[j] , d1[j] = 1;
            }
        }
        for (int i = 0 ; i < c.size() ; i++) x[i] = 0;
        ok = 0;
        cerr << s << endl;
        if (s == "") cout << "NO" << endl;
        else 
        {
            quaylui(0);
            if (ok == 0) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }
}
