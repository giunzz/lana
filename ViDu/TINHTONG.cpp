/*#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(obj1, obj2, obj3) for(ll obj1 = obj2; obj1 <= obj3; obj1++)
#define lpd(obj1, obj2, obj3) for(ll obj1 = obj2; obj1 >= obj3; obj1--)
#define lpdk(obj1, obj2, obj3, obj4) for(ll obj1 = obj2; obj3; obj4) 
#define pp(obj1, obj2) pair<obj1, obj2>
#define vec(obj1) vector<obj1>
#define vecite(obj1) vector<obj1>::iterator
#define fi first
#define se second
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

vec(ll) a[2];
bool d[2] = {0};
string num, b[2];

void xuly(string &n, ll id){
    if(n[0] == '-') {d[id] = 1; n.erase(n.begin());}
    reverse(n.begin(), n.end());
    while(n.size() > 1 && n.back() == '0') n.pop_back();
    while(!n.empty()) {b[id].push_back(n.back()); a[id].push_back(n.back() - '0'); n.pop_back();}
}

int main(){
    opt;
    // file;
    cin >> num; xuly(num, 0);
    cin >> num; xuly(num, 1);

}*/

/*vector<int> v1 , v2 , v3;
string s1 , s2;
int d = 0;
void remove0( vector<int> &v)
{
    while (v[v.size() - 1] == 0 && v.size() > 1)
     {
         v.pop_back();
     }
 }
 void addnit(string a , vector<int> &v)
 {
     for (int i = a.length()-1; i >= 0 ; i--)
    {
        if (a[i] =='-') d++;
        else v.push_back(a[i] -'0');
     }
     remove0(v);
 }

 void print_ans( vector<int> v)
 {
          for (int i = v.size() - 1 ; i >= 0 ; i--) cout << v[i] ;
 }

 void cong ( vector<int> v1 , vector<int> v2 , vector<int> &v3 )
 {
     v3.clear();
     int l = v1.size() > v2.size() ? v1.size() : v2.size();
     v1.resize(l) , v2.resize(l);
     int nho = 0 , t ;
     for (int i = 0 ; i < l ; i++)
    {
         t = v1[i] + v2[i] + nho;
         v3.push_back( t % 10 );
         nho = t / 10;
     }
     if (nho > 0 ) v3.push_back(t);
 }

 // v1 > v2
 void tru ( vector<int> v1 , vector<int> v2 , vector<int> &v3 )
 {
     v3.clear();
     int l = v1.size();
     v2.resize(l);
  int nho = 0 ;
     for (int i = 0 ; i < l ; i++)
     {
         if ( v1[i] < v2[i] + nho )
         {
             v3.push_back(v1[i] - v2[i] - nho + 10);
             nho = 1;
         }
         else 
         {
             v3.push_back(v1[i] - v2[i] - nho);
             nho = 0;
         }
         remove0(v3);
     }
 }
 int main()
 {
         int ds1 = 0 , ds2 = 0;
         giuncute;
         balabalo;
         cin >> s1 >> s2;
         if (s1[0] =='-') ds1 = 1;
         if (s2[0] =='-') ds2 = 1;
         addnit( s1 , v1);
         addnit( s2 , v2);
         print_ans(v1) ; cout << endl;
         print_ans(v2) ; cout << endl;
         if ( d == 2) 
         {
                         cong( v1 , v2 , v3);
             cout <<'-';
             print_ans(v3);
         }
         else if (d == 1 )
         {
             if  ( (v1[v1.size() -1 ]) <  (v2[v2.size() -1 ]) )
             {
                     if (ds1 == 1 )
                     {
                         tru(v2 , v1 , v3); 
                         print_ans(v3);
                     }
                     else 
                     {
                         tru(v2 , v1 , v3);
                         cout<<'-';
                         print_ans(v3);
                     }
             }
             else
             {
                 if (ds2 == 1)
                 {
                     tru(v1 , v2 , v3); 
                     print_ans(v3);
                 }
                 else 
                 {
                     tru(v1 , v2 , v3);
                     cout<<'-';
                     print_ans(v3);
                 }
             } 
         }
         else 
         {
             cong( v1 , v2 , v3);
             print_ans(v3);
         }       
         return 0;    
 }*/

#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

string a,b,c ;
char d1 , d2 , d ;

int stringToNum(char c) {return c - '0';}

char numToString(int n) {return (char)(n+48);}

string SUM (string  a , string b )
{
    int n = a.length();
    c = "";
    for (int i = 0 ; i < n ; i++ ) c += '0';
    int nho = 0;
    for (int i = n - 1  ; i > 0 ; i--)
    {
        nho = stringToNum(a[i]) + stringToNum(b[i]) + nho;   
        c.insert( 0,1,numToString(nho % 10) );         
        nho /=  10; 
    }
    if (nho > 0)  c.insert(0,1,numToString(nho));
    return c;
}

string TRu (string a , string b )
{
    int n = a.length();
    c="";
    for (int i = 0 ; i < n ; i++ ) c += '0';
    int nho = 0;
    for (int i = n - 1 ; i > 0 ; i--)
    {
        int x = stringToNum(a[i]) , y = stringToNum(b[i]);
        if ( x < (y + nho ))
        {
            int z = x + 10 - ( y + nho );
            c[i] = numToString ( z );
            nho = 1;
        }
        else 
        {
            z =  x-(y + nho);
			c[i] = numToString(z);
			nho = 0; 
        }
    }
    return c;    
}


int main ()
{
    balabalo;
    giuncute;
    cin >> a >> b;
    if (a[0] == '-')
    {
        d1 ="-";
        a = copy(a , 2 , len)
    }
    else dau = 0;
    if (b[0] == '-')
    {
        d2 = "-";
    }
    else d2 = 0;
    while (a.length() != b.length() ) do
		{
            if ( a.length() < b.length() ) a += "0";
            else b += "0";
        }
    a += "0" , b += "0";
    if ( d1 == d2 )
    {
        d = d1;
        c = sum(a,b);
    }
    else 
    {
        if( a == b )
        {
            c = "0";
            d = 0;
        }
        else if ( a > b )
        {
            c = TRu(a,b);
            d = d1;
        }
        else 
        {
            c = TRu(a , b);
            
        }

    }
}














