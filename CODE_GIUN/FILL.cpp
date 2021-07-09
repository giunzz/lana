#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
const ll maxn = 1e6 + 7 ;
using namespace std;
string a,b,c;
ll x , y ;

bool check (string x)
{
    for (int i = 0 ; i < x.length() ; i++)
        if (x[i] == '?') return true;
    return false;
}

char tinh (string  u , string sum)
{
    ll s = 0 ;
    for (int i =  0 ; i < u .size() ; i++)
        if (u[i] != sum[i] ) return sum[i];
    return s;
}
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
    reverse(tmp.begin() , tmp.end());
    return tmp ;
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
    freopen("giun.inp" , "r",stdin);
    freopen("giun.out", "w" , stdout);
    cin >> a >> b >> c;
    if (check(a) == false && check(b) == false) 
    {
        x = SL(a) , y = SL(b);
        ll sum = x + y;
        string sum1 = iS(sum);
        cout << tinh(c , sum1);
    }
    else if (check(a) == false && check(c) == false)
    {
        x = SL(a) , y = SL(c);
        ll sum = y - x;
        string sum1 = iS(sum);
        cout << tinh(b , sum1 );
    }
    else if (check(b) == false && check(c) == false)
    {
        x = SL(b) , y = SL(c);
        ll sum = y - x;
        string sum1 = iS(sum);
        cout << tinh(b,sum1);
    }
}    
