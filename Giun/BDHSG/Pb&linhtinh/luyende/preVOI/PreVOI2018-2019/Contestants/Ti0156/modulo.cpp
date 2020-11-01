#include<map>
#include<cstdio>
#include<string>
#include<stdlib.h>
#include<iostream>
using namespace std;
const int limit=1048577;
struct inf
{
    bool existed;
    string str;
    inf(bool a=false,string b="")
    {
        existed=a;
        str=b;
    }
};
struct infor 
{
    string str;
    long long val;
    infor(long long a=0,string b="")
    {
        val=a;
        str=b;
    }
};
map<long long,inf>save;
map<long long,bool>appeared;
long long a,b,n,k,counter;
unsigned long long int power=1,ten=1;
infor modval[limit];
void cal(int ord,long long mod,string res)
{
    if (ord>n && mod==k)
    {
        (res!="")?cout<<res:cout<<"0";
        exit(0);
    }
    if (ord>n) return;
    cal(ord+1,((mod*10)%power+a%power)%power,res+char(a+48));
    cal(ord+1,((mod*10)%power+b%power)%power,res+char(b+48));
}
void sub1()
{
    for (int i=1;i<=n;i++) power*=2;
    cal(1,0,"");
    cout<<-1;
}
void repair()
{
    for (int i=1;i<=n;i++) power*=2;
    for (int i=1;i<=n/2+n%2;i++) ten=(ten*10)%power;
}
void cal1(int begin,int end,long long mod,string str)
{
    if (begin>end)
    {
        if (end==n)
        {
            inf &tmp=save[mod];
            tmp=inf(true,str);
        }
        else 
        {
            bool &tmp=appeared[mod];
            if (!tmp)
            {
                tmp=true;
                modval[++counter]=infor(mod,str);
            }
        }
        return;
    }
    cal1(begin+1,end,((mod*10)%power+a%power)%power,str+char(a+48));
    cal1(begin+1,end,((mod*10)%power+b%power)%power,str+char(b+48));
}
void sub2()
{
    
    repair();   
    cal1(1,n/2,0,"");
    cal1(n/2+1,n,0,"");
    int range=n/2+n%2;
    for (int i=1;i<=counter;i++)
    {
        long long tmp=modval[i].val;
        for (int i=1;i<=range;i++) tmp=(tmp*10)%power;
        tmp=k-tmp;
        if (tmp<0) tmp+=power;
        inf tt=save[tmp];
        if (tt.existed)
        {
            cout<<modval[i].str<<tt.str;
            exit(0);
        }
    }   
    cout<<-1;
}
int main()
{
    freopen("modulo.inp","r",stdin);
    freopen("modulo.out","w",stdout);
    cin>>a>>b;
    cin>>n>>k;
    if (n<=20) sub1();
    else if (n<=40) sub2();
    else cout<<-1;

}