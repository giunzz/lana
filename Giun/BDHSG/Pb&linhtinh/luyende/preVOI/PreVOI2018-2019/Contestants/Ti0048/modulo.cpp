#include<bits/stdc++.h>
using namespace std;
unsigned long long a,b,n,k,kl,n2=1;
#define int long long
int cmp(string a,string b)
{
    while(a.length()<b.length()) a="0"+a;
    while(b.length()<a.length()) b="0"+b;
    if(a<b)return 1;
    return 0;
}
string add(string a,string b)
{
    string res="";
    while(a.length()<b.length()) a="0"+a;
    while(b.length()<a.length()) b="0"+b;
    int nho=0;
    for(int i=a.length()-1;i>=0;i--)
    {
     int  tmp=nho+a[i]+b[i]-96;
     if(tmp>9) {nho=1;res=char(tmp+38)+res;}
     else {nho=0;res=char(tmp+48)+res;}
    }
    if(nho==1) res="1"+res;
    return res;
}
string sub(string a,string b)
{
    string res="";
    while(a.length()<b.length()) a="0"+a;
    while(b.length()<a.length()) b="0"+b;
    int nho=0,nef=0;
    if(cmp(a,b)) nef=1,swap(a,b);
    for(int i=a.length()-1;i>=0;i--)
    {
     int  tmp=a[i]-b[i]-nho;
     if(tmp<0) {nho=1;res=char(tmp+58)+res;}
     else {nho=0;res=char(tmp+48)+res;}
    }
    while(res.length()>1&&res[0]=='0') res.erase(0,1);
    if(nef==1) res="-"+res;
    return res;
}
string mul(string a,string b)
{
    string res="";
    int n=a.length();
    int m=b.length();
    int len=n+m-1;
    int nho=0;
    for(int i=len;i>=0;i--)
    {
        int tmp=0;
        for(int j=n-1;j>=0;j--)
            if(i-j<=m&&i-j>=1)
        {
            int a1=a[j]-48;
            int b1=b[i-j-1]-48;
            tmp+=a1*b1;
        }
        tmp+=nho;
        nho=tmp/10;
        res=char(tmp%10+48)+res;
    }
    while(res.length()>1&&res[0]=='0') res.erase(0,1);
    return res;
}
string sauxo(long long n2)
{
    string mu="";
    while(n2>0)
    {
        mu=char(n2%10+48)+mu;
        n2/=10;
    }
    return mu;
}
bool kt(string s)
{
    int m=s.size();
    for(int i=0;i<m;i++)
        if((int)(s[i]-48)!=a&&(int)(s[i]-48)!=b)return 0;
        return 1;
}

void sub1(int i)
{
    for(int j=0;j<=1;j++)
    {
        if(j==0) kl=kl*10+a;
        else kl=kl*10+b;
        if(i==n) {if(kl%n2==k){cout<<kl;exit(0);}}
        else sub1(i+1);
        kl/=10;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
     freopen("modulo.inp","r",stdin);
     freopen("modulo.out","w",stdout);
    cin>>a>>b;
    cin>>n>>k;
    for(int i=1;i<=n;i++) n2=n2*2;
    if(n<=19) {sub1(1);cout<<-1;return 0;}
    string mu=sauxo(n2);
    int hk=1e12;
    for(int i=hk-30000;i<=hk+20000;i++)
    {
        string res=mul(mu,sauxo(i));
        res=add(res,sauxo(k));
        if(kt(res)&&res.size()==n) {cout<<res;return 0;}
    }
    cout<<-1;
    return 0;
}
