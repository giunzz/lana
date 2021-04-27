#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long
string n  , m ;
int STN(char c) {return c - '0';}
char NTS(int n) {return (char)(n+48);}
string sum(string a, string b)  
{
    string s = "";
    if (a.length() > b.length())  b = '0'+ b;
    else if (a.length() < b.length())  a= '0'+a;
    int l = a.length() , temp = 0;
    for (int i = l-1 ; i >= 0 ; i--)
    {
        temp = STN(a[i]) + STN(b[i]) + temp;    
        s.insert(0,1,NTS(temp%10));         
        temp = temp/10;     
    
    }
    if (temp>0) s.insert(0,1,NTS(temp));
    return s;
}
string nhanNho(char a, string b)    
{
    string s = "";
    int temp = 0;
    for (int i = b.length()-1; i >= 0; i--)      
    {
        temp = STN(a) * STN(b[i]) + temp;
        s.insert(0,1,NTS(temp%10));
        temp = temp/10;
    }
    if (temp > 0) s.insert(0,1,NTS(temp));
    return s;
}
string nhan(string a, string b)  
{
    string s = "";
    int l = a.length();
    string s1[l];
    for (int i = l-1 ; i >= 0 ; i--) 
    {
        s1[i] = nhanNho(a[i], b);   
        s1[i].insert(s1[i].length(), l-i-1, '0');   
        s = sum(s, s1[i]);  
    }
    return s;
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> m ;
    cout << nhan(n,m);
}
