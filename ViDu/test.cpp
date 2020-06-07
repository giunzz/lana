/*#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);

int  a , b , n , dem[12] ;

void fastscan(int &number) 
{ 
    bool negative = false; 
    register int c; 
    number = 0; 
    c = getchar(); 
    if (c == ' ') fastscan(number);
    if (c=='-') 
    { 
        negative = true; 
        c = getchar(); 
    } 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
    if (negative) 
        number *= -1; 
}

int main()
{
    balabalo;
    for (int giun = 1 ; giun <= 500 ; giun++)
    {
        fastscan(a) ; 
        fastscan(b);
        //cin >> a >> b ;
        cerr << a << " " << b << endl;
        if ( a == 0 && b == 0 ) return 0;
        else 
            {
                for (int i = 0 ; i <= 10 ; i++) dem[i] = 0;
                int i = min(a,b);
                while ( i <= max(a,b) )
                {  
                    int j = i;
                    while (j != 0 )
                    {
                        dem[j % 10 ]+= 1;
                        j = j / 10;
                    }
                    i++;  
                }
                for (int i = 0 ; i < 10 ; i++) cout << dem[i] << " ";
                cout << endl;
            }
    }
}*/

#include <bits/stdc++.h>
using namespace std;

const int base = 1000000000; const int base_digits = 9;

#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
using namespace std;

int stringToNum(char c) {return c - '0';}

char numToString(int n) {return (char)(n+48);}

void chuanHoa(string &a, string &b) 
{
    int l1 = a.length(), l2 = b.length();
    if (l1 >= l2) b.insert(0, l1-l2, '0');    
    else a.insert(0, l2-l1, '0');    
}
string sum(string a, string b) 
{
    string s = "";
    chuanHoa(a,b);    
    int l = a.length();
    int nho = 0;
    for (int i = l - 1; i > 0 ; i--)  
    {
        nho = stringToNum(a[i]) + stringToNum(b[i]) + nho;   
        s.insert( 0,1,numToString(nho % 10) );         
        nho /=  10;     
    }
    if (nho > 0)  s.insert(0,1,numToString(nho));
    return s;
}

void remove0( vector<int> &v)
{
    while (v[v.size() - 1] == 0 && v.size() > 1)
    {
        v.pop_back();
    }
}

void addnit(string a , vector<int> &v)
{
    for (int i = a.length() - 1 ; i >= 0 ; i--)
    {
        v.push_back(a[i] -'0');
    }
    remove0(v)
}

void print_ans( vector<int> v)
{
    for (int i = v.size() - 1 ; i >= 0 ; i--) cout <<v[i];
}

int main()
{
        string s1 , s2;
        freopen("giun.inp","r",stdin);
        freopen("giun.out","w",stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cin >> s1 >> s2;
        if (s1  < 0 && )
        cout << sum(s1,s2);
        return 0;
    
}