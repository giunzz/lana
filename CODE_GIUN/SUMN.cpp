#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long
string n  , m ;
ll ans = 0 , t = 0 ;

int stringToNum(char c)     
{
    return c - '0';
}
char numToString(int n)     
{
    return (char)(n+48);
}
void chuanHoa(string &a, string &b) 
{
    int l1 = a.length(), l2 = b.length();
    if (l1 >= l2)
    {
        b.insert(0, l1-l2, '0');   
    }
    else
    {
        a.insert(0, l2-l1, '0');    
    }
}
string sum(string a, string b)  
{
    string s = "";
    chuanHoa(a,b);      
    int l = a.length();
    int temp = 0;
    for (int i=l-1; i>=0; i--)   
    {
        temp = stringToNum(a[i]) + stringToNum(b[i]) + temp;    
        s.insert(0,1,numToString(temp%10));         
        temp = temp/10;     
    }
    if (temp>0)  
    {
        s.insert(0,1,numToString(temp));
    } 
    return s;
}
string NTS(int meo)
{
    string bubu ="";
    char t ;
    while (meo != 0 )
    {
        t = (char)(meo % 10 +48);
        bubu += t;
        meo = meo / 10;
    }
    reverse(bubu.begin(), bubu.end()); 
    return bubu;
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i =  0 ; i < (int) n.length() ; i++) t += stringToNum(n[i]);
    m = NTS(t);
    cout << sum(n,m);
}
