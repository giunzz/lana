#include <bits/stdc++.h>
using namespace std;
long n,m,i,j,k,a1,b1,aa,bb;
long long h,t;
string d,s,sk,a,b,sn,res;
bool ok=0;
string chuyen(long long k)
{
    string res="";
    while(k>0)
    {
        res=(char)(k%10+48)+res;
        k=k/10;
    }
    return res;
}
string sub(string a,string b)
{
    string res="";
    while(a.length()<b.length()) a="0"+a;
    while(a.length()>b.length()) b="0"+b;
    bool neg=0;
    if(a<b) {swap(a,b);neg=1;}
    long muon=0;
    for(long i=a.length()-1;i>=0;i--)
    {
        long tmp=a[i]-b[i]-muon;
        if(tmp<0) {tmp+=10;muon=1;}
        else muon=0;
        res=(char)(tmp+48)+res;
    }
    while(res.length()>1&&res[0]=='0') res.erase(0,1);
    if(neg==1) res="-"+res;
    return res;
}
string mul(string a,string b)
{
    string res="";
    long n=a.length();
    long m=b.length();
    long len=n+m-1; long carry=0;
    for(long i=len;i>=0;i--)
    {
        long tmp=0;
        for(long j=n-1;j>=0;j--)
            if(i-j<=m && i-j>=1)
            {
                long a1=a[j]-48;
                long b1=b[i-j-1]-48;
                tmp+=a1*b1;
            }
        tmp+=carry;
        carry=tmp/10;
        res=(char)(tmp%10+48)+res;
    }
    while(res.length()>1&&res[0]=='0') res.erase(0,1);
    return res;
}
string add(string a,string b)
{
    string res="";
    while(a.length()<b.length()) a="0"+a;
    while(a.length()>b.length()) b="0"+b;
    long nho=0;
    for(long i=a.length()-1;i>=0;i--)
    {
        long tmp=a[i]+b[i]-96+nho;
        nho=tmp/10;
        tmp=tmp%10;
        res=(char)(tmp+48)+res;
    }
    if(nho==1) res="1"+res;
    return res;
}
bool cmp(string a,string b)
{
    while(a.length()<b.length()) a="0"+a;
    while(a.length()>b.length()) b="0"+b;
    return a>=b;
}
string mod(string a,string b)
{
    string hold="",kb[15];
    kb[1]=b;kb[0]="";
    for(long i=2;i<=11;i++)
        kb[i]=add(kb[i-1],b);
    for(long i=0;i<a.length();i++)
    {
        hold=hold+a[i];
        long q=1;
        while(q<=9&&cmp(hold,kb[q])==1) q++;
        q--;
        hold=sub(hold,kb[q]);
    }
    return hold;
}
void capnhat()
{
    string ss=sub(res,sk);
    if(((long)ss[n-1]-48)%2==1) return;
    if(mod(ss,sn)=="0") {ok=1;cout << res;exit(0);}
}
void Try(long i)
{
    for(long j=0;j<=1;j++)
    {

        if(j==0) res=res+a;
        if(j==1) res=res+b;
        if(i==n) capnhat();
        else Try(i+1);
        res.erase(res.size()-1,1);

    }
}
void capnhat1()
{
    if((t-k)%h==0) {cout << t;ok=1;exit(0);}
}
void Try1(long i)
{
    for(long j=1;j<=2;j++)
    {
        if(j==1) t=t*10+a1;
        if(j==2) t=t*10+b1;
        if(i==n) capnhat1();
        else Try1(i+1);
        if(j==2) t=(t-b1)/10;
        if(j==1) t=(t-a1)/10;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("modulo.inp","r",stdin);
    freopen("modulo.out","w",stdout);
    cin >> aa >> bb;
    cin >> n >> k;
    a1=aa;
    b1=bb;
    a=chuyen(aa);
    b=chuyen(bb);
    long long pp=k;
    sk=chuyen(pp);
    h=1<<n;
    sn=chuyen(h);
    if(n<=18)
    {
        t=0;
        Try1(1);
        if(ok==0) cout << "-1";
    }
    else if(n<=28)
    {
        res="";
        Try(1);
        if(ok==0) cout << "-1";
    }
    else cout << "-1";
}
