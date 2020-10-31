#include <bits/stdc++.h>

using namespace std;
ifstream fi("modulo.inp");
ofstream fo("modulo.out");
int a,b,n;
int64_t k;
string s="";
int64_t pw=1;
bool done=false;
int64_t tg1=0;
void xuli1(int x)
{
    if (x==n+1)
    {
        if (tg1==k) fo<<s,done=true;
        return;
    }
    if (done==true) return;
    int64_t tg2;
    for (int i=a;i<=b;i+=b-a)
    {
        s=s+char(i+48);
        tg2=tg1;
        tg1=(tg1*10+i)%pw;
        xuli1(x+1);
        tg1=tg2;
        s=s.substr(0,s.size()-1);
    }
}
int main()
{
    fi>>a>>b>>n>>k;
    if (a>b) swap(a,b);
    if (n<=20)
    {
        for (int i=1;i<=n;i++)
            pw=pw*2;
        xuli1(1);
        if (done==false) fo<<-1;
    }
    else
    {
        if (a%2==b%2 && a%2!=k%2) fo<<-1;
    }
    return 0;
}
