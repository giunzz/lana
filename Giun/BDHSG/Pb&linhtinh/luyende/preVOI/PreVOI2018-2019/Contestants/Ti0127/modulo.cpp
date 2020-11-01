#include <bits/stdc++.h>
#define int long long
using namespace std;
int a,b,n,k;
string gia,base,k1;
bool cmp(string a,string b)
{
    while(a.size()<b.size())
        a="0"+a;
    while(b.size()<a.size())
        b="0"+b;
        return a>=b;
}
string add(string a,string b)
{
    while(a.size()<b.size())
        a="0"+a;
    while(b.size()<a.size())
        b="0"+b;
    string res="";
    int tmp=0,carry=0;
    for(int i=a.size()-1;i>=0;i--)
    {
        tmp=a[i]+b[i]-96+carry;
        carry=tmp/10;
        tmp=tmp%10;
        res=(char)(tmp+48)+res;
    }
    if(carry)res="1"+res;
    return res;
}
string sub(string a,string b)
{
    while(a.size()<b.size())
        a="0"+a;
    while(b.size()<a.size())
        b="0"+b;
    string res="";
    bool neg=0;
    if(a<b) swap(a,b),neg=1;
    int tmp=0,borrow=0;
    for(int i=a.size()-1;i>=0;i--)
    {
        tmp=a[i]-b[i]-borrow;
        if(tmp<0)
            tmp+=10,
            borrow=1;
        else borrow=0;
        res=(char)(tmp+48)+res;
    }
    while(res.size()>1&&res[0]=='0')
        res.erase(0,1);
    if(neg)
        res="-"+res;
    return res;
}
string mul(string a,string b)
{
    int n=a.size();
    int m=b.size();
    int len=m+n-1;
    string res="";
    int carry=0;
    for(int i=len;i>=0;i--)
    {
        int tmp=0;
        for(int j=n-1;j>=0;j--)
        if(i-j>=1&&i-j<=m)
        {
            int a1=a[j]-48;
            int b1=b[i-j-1]-48;
            tmp+=a1*b1;
        }
        tmp+=carry;
        carry=tmp/10;
        tmp=tmp%10;
        res=(char)(tmp+48)+res;
    }
     while(res.size()>1&&res[0]=='0')
        res.erase(0,1);
    return res;
}
string sotoxau(int i)
{
    string res="";
    while(i>0)
    {
        res=(char)(i%10+48)+res;
        i=i/10;
    }
    return res;
}
string mod(string a,string b)
{
    string hold="";
    string kb[11];
    int k;
    kb[0]="0";
    for(int i=1;i<=10;i++)
        kb[i]=add(b,kb[i-1]);
    for(int i=0;i<a.size();i++)
    {
        hold=hold+a[i];
        k=1;
        while(cmp(hold,kb[k]))
            k++;
        k--;
        hold=sub(hold,kb[k]);
    }
    return hold;
}
void cnkl()
{
    if(mod(gia,base)==k1)
    {
        cout<<gia;
        exit(0);
    }
}
void Try(int i)
{
    for(int j=1;j<=2;j++)
    {
        if(j==1)
            gia=gia+(char)(a+48);
        if(j==2)
            gia=gia+(char)(b+48);
        if(i>=n)
            cnkl();
        else Try(i+1);
        gia.erase(gia.size()-1);
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("modulo.inp","r",stdin);
    freopen("modulo.out","w",stdout);
    cin>>a>>b;
    cin>>n>>k;
    k1=sotoxau(k);
    if(n>=27)
    {
        cout<<-1;
        return 0;
    }

    base=sotoxau((1<<n));
    Try(1);
    cout<<-1;
    return 0;
}
