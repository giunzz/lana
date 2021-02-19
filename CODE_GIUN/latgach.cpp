#include <bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long 
ll t , n ;
string f[(int) 1e5+7];
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
void fibo()
{
    f[1] = "1" , f[2] = "2";
    for (int i = 3 ; i <= 100 ; i++) 
    {
        f[i] = sum(f[i-1],f[i-2]);
        //cerr << f[i] << " ";
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> t;
    fibo();
    for(int i = 1 ; i <= t ; i++) cin >> n , cout << f[n] << endl;
}