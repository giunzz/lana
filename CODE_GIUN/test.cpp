#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
const ll maxn = 3e3 +  7;
using namespace std;
ll n , t , x[maxn] , ok = 0;
string a , b , c  ;

void quaylui(ll vt)
{
    if (vt == a.size() + 1) 
    {
        string tmp ="";
        for (int i = 0 ; i < (int)a.size() ; i++)
        {
            if (x[i] == 1) tmp += a[i];
            if (x[i] == 2) tmp += b[i];
        }
        if (tmp == c) ok = 1;
        if (tmp[0] == 'N' && tmp[1] == 'Q' && tmp[2] == 'J')cerr << tmp << endl;
    }
    else 
    {
        for (int i = 0 ; i <= 2 ; i++)
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
    freopen("giun.inp" ,"r",stdin);
    freopen("giun.out", "w" ,stdout);
    cin >> t;
    while (t --)
    {
        cin >> a >> b >> c;
        quaylui(0);
        if (ok == 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}
