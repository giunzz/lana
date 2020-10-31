#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F(i,a,b) for(int i=a;i<=b;i++)
#define FD(i,a,b) for(int i=a;i>=b;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define oo
#define int long long
int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
    while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
    return x * f;
}
void write(int x)
{
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
int a,b,n,base=1;
ll K;
int f[25];
vector<ll>v1,v2;
void ReadInPut()
{
    cin>>a>>b>>n>>K;
    F(i,1,n)base*=2;
}
void tinh()
{
    ll k=0;
    F(i,1,n)
    {
        if(f[i]==1)
        {
            k=(k*10)%base+a%base;
            k%=base;
        }
        else
        {
            k=(k*10)%base+b%base;
            k%=base;
        }
    }
    if(k==K){
        F(i,1,n)
        {
            if(f[i]==1)cout<<a;
            else  cout<<b;
        }
        exit(0);
    }
}
void snp(int i)
{
    F(j,0,1)
    {
        f[i]=j;
        if(i==n)tinh();
        else snp(i+1);
    }
}
void Solve()
{
    snp(1);
    cout<<-1;
}
main()
{
    freopen("MODULO.INP","r",stdin);
    freopen("MODULO.OUT","w",stdout);
    ReadInPut();
    if(n<=20)Solve();
    //else Solve1();
}
