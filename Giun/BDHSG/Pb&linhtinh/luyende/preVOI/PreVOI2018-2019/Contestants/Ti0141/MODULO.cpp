#include <bits/stdc++.h>

using namespace std;
#define ii pair<int,int>
#define f first
#define s second
#define ll long long
#define TASK "MODULO"
int n,a,b ;
ll k;
int c[25] ;
string z,tmp ;
ll _pow(int a,int b)
{
    if(b == 0) return 1 ;
    if(b == 1) return a ;
    return _pow(a,b/2)*_pow(a,b/2)*_pow(a,b%2) ;
}
void Input()
{
    cin >> a >> b ;
    cin >> n >> k ;
    ll tam = _pow(2,n) ;
    ll kk = k ;
    int cs ;
    while(tam > 0)
    {
        cs = tam%10 ;
        z= z + char(cs+'0') ;
        tam=tam/10 ;
    }
    while(kk >0)
    {
        cs=kk%10 ;
        tmp = tmp+char(cs+'0') ;
        kk=kk/10 ;
    }
    return ;
}
bool cmp(string a,string b)
{
    while(a.size() < b.size())
        a= "0"+a ;
    while(b.size() < a.size())
        b= "0"+b ;
    for(int i=0;i<a.size();i++)
    {
        if(a[i] > b[i])
            return true ;
    }
    return false ;
}
string cal(string a,string b)
{
    while(a.size() < b.size())
        a= "0"+a ;
    while(b.size() < a.size())
        b= "0"+b ;
    if(cmp(a,b) == 0)
        swap(a,b) ;
    string res ="";
    int nho = 0;
    int x,y ;
    for(int i=a.size()-1;i>=0;i--)
    {
        if(a[i] > b[i])
        {
            if(nho == 0)
                x= a[i]-'0' ;
            else{
                x= a[i]-'0'-1 ;
                nho = 0;
            }
            y = b[i]-'0' ;
            res=char(x-y+'0')+res ;
        }
        if(a[i] == b[i])
        {
            if(nho == 0)
                res =  '0' +res;
            else
            {
                res =  '9' +res ;
                nho = 1 ;
            }
        }
        if(a[i] < b[i])
        {
            x = 10+a[i]-'0' ;
            y = b[i]-'0' ;
            res=  char(x-y+'0')+res ;
            nho = 1 ;
        }
    }
    return res ;
}
void Check1()
{
    string x ;
    for(int i=1;i<=n;i++)
    {
        if(c[i] == 0)
            x=x+char(a+'0') ;
        else
            x=x+char(b+'0') ;
    }
    string ans = x ;
    while(cmp(x,z) == 1)
        x = cal(x,z) ;
    while(tmp.size() < x.size())
        tmp="0"+tmp ;
    while(x.size() < tmp.size())
        x="0"+x ;
    if(x == tmp)
    {
        cout << ans ;
        exit(0) ;
    }
}
void Check2()
{
    unsigned long long ans = 0;
    for(int i=1;i<=n;i++)
    {
        if(c[i] == 0)
            ans=ans*10+a ;
        else
            ans=ans*10+b ;
    }
    if(ans % _pow(2,n) == k)
    {
        cout << ans ;
        exit(0) ;
    }
}
void Try(int i)
{
    for(int j=0;j<=1;j++)
    {
        c[i] = j;
        if(i == n)
        {
            if(n <= 18)
                Check2() ;
            else
                Check1() ;
        }
        else
            Try(i+1) ;
    }
}

int main()
{
    freopen(TASK".INP","r",stdin) ;
    freopen(TASK".OUT","w",stdout) ;
    ios_base::sync_with_stdio(0) ;
    cin.tie(NULL) ;
    Input() ;
    if(n <= 20)
    {
        Try(1) ;
        cout << -1 ;
    }
    else
        cout << -1 ;
    return 0;
}
