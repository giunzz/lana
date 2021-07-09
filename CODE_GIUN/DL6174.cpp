#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
const ll maxn = 1e6 + 7 ;
using namespace std;
ll x , y ;

char numToString(int k){
    return (char)(k+48);
}

string iS (ll s)
{
    string tmp = "";
    int x ;
    while (s != 0)
    {
        x = s % 10 ;
        char v = numToString(x);
        tmp = tmp + v;
        s /= 10;
    }
    sort(tmp.begin() , tmp.end());
    return tmp ;
}

int dao(int k)
{
    int b = 0;
    while (k != 0 )
    {
        b = b * 10 + k % 10;
        k /= 10;
    }
    return b;
}
int stringToNum(char c)     
{
    return c - '0';
}
ll SL (string l)
{
    reverse(l.begin() , l.end());
    ll k = 10 ;
    ll s = stringToNum(l[0]);
    //cerr << s << endl;
    for (int i = 1 ; i < l.length() ; i++)
    {
        s = s + stringToNum(l[i]) * k;
        k *= 10;
      //  cerr << s << endl;
    }
    
    return s;
}

int main()
{
    freopen("DL6174.inp" , "r",stdin);
    freopen("DL6174.out", "w" , stdout);
    cin >> x ;
    ll ans = 1 ;
    while (x != 6174)
    {
        y = dao(x);
        string s1 = iS(x);
        string s2 = iS(x);
        sort(s2.rbegin() , s2.rend() );
        x = SL(s1);
        y = SL(s2);
        //cerr << s1  << " " << s2 << " " << y - x << endl;
        x = y - x;
        ans ++;
    }
    cout << ans;
}