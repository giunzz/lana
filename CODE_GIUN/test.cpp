#include <string>
#include <iostream> 
using namespace std;
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
     
    int tam = 0;
    for (int i=l-1; i>=0; i--)   
    {
        tam = stringToNum(a[i]) + stringToNum(b[i]) + tam;   
        s.insert(0,1,numToString(tam%10));        
        tam = tam/10;    
    }
    if (tam>0)  
    {
        s.insert(0,1,numToString(tam));
    } 
    return s;
}
 
string mulNho(char a, string b)    
{
    string s = "";
    int tam = 0;
    for (int i=b.length()-1; i>=0; i--)      
    {
        tam = stringToNum(a) * stringToNum(b[i]) + tam;
        s.insert(0,1,numToString(tam%10));
        tam = tam/10;
    }
     
    if (tam>0)
    {
        s.insert(0,1,numToString(tam));
    } 
    return s;
}
 
string mul(string a, string b)     
{
    string s = "";
    int l = a.length();
    string s1[l];
    for (int i=l-1; i>=0; i--)   
    {
        s1[i] = mulNho(a[i], b);  
        s1[i].insert(s1[i].length(), l-i-1, '0');   
        s = sum(s, s1[i]);  
    }
    return s;
}
int main()
{
    string n , m;
    cin >> n >> m ;
    cout << mul(n,m);
}
