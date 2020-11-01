#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
#define Bit(x,i) ((x>>i)&1)
using namespace std;
const int maxdigit=21;
typedef int big_num[maxdigit+1];
big_num a,b,c,r,t;
int A,B,n,n1,n2;
ll k;
void tru(big_num a,big_num b,big_num c)
{
    int nho=0;
    for(int i=maxdigit;i>=1;i--)
    {
        c[i]=a[i]-b[i]-nho;
        if(c[i]<0)
        {
            c[i]+=10;
            nho=1;
        }
        else nho=0;
    }
}
int sosanh(big_num a,big_num b)
{
    for(int i=1;i<=maxdigit;i++)
        if(a[i]<b[i]) return -1;
            else if(a[i]>b[i]) return 1;
    return 0;
}
void chia(big_num a,big_num b,big_num r)
{
    fill(r+1,r+1+maxdigit,0);
    for(int i=1;i<=maxdigit;i++)
    {
        for(int j=1;j<=maxdigit;j++) r[j]=r[j+1];
        r[maxdigit]=a[i];
        while(sosanh(r,b)>=0)
            tru(r,b,r);
    }
}
void Io()
{
    freopen("MODULO.inp","r",stdin);
    freopen("MODULO.out","w",stdout);
}
void Read()
{
    scanf("%d%d",&A,&B);
    scanf("%d%d",&n,&k);
}
void Convert(ll cur,big_num x)
{
    int cur_digit=maxdigit;
    while(cur>0)
    {
        x[cur_digit]=cur%10;
        cur/=10;
        cur_digit--;
    }
}
ll Test(big_num x)
{
    ll d=0;
    for(int i=1;i<=maxdigit;i++)
        d=d*10+x[i];
    return d;
}
void Print(big_num x)
{
    int i;
    for(i=1;i<maxdigit;i++)
        if(x[i]!=0)break;
    for(;i<=maxdigit;i++)
        printf("%d",x[i]);
    printf("\n");
}
ll Base2(int n)
{
    ll hmm=1;
    For(i,1,n)
        hmm*=2;
    return hmm;
}
void GanACSub1()
{
    Convert(Base2(n),b);
    Convert(k,t);
    For(x,0,(1<<n)-1)
    {
        big_num cur;
        fill(cur+1,cur+1+maxdigit,0);
        For(i,1,n)
        {
            if(Bit(x,i-1)==1)cur[maxdigit-i+1]=A;
            else
                cur[maxdigit-i+1]=B;
        }
        chia(cur,b,r);
        if(sosanh(r,t)==0)
        {
            Print(cur);
            exit(0);
        }
    }
    cout<<-1;
}
void Test()
{
    ll du=Base2(n);
    For(x,0,(1<<n)-1)
    {
        ll cur=0;
        For(i,1,n)
        {
            if(Bit(x,i-1)==1)cur=cur*10+A;
            else
                cur=cur*10+B;
        }
        if(cur%du==k)
        {
            cout<<cur;
            exit(0);
        }
    }
    cout<<-1;
}
int main()
{
    Io();
    Read();
    if(n<=17)Test();
    else
    {
        if(n<=20)GanACSub1();
        else
            cout<<-1;
    }
}
