#include <bits/stdc++.h>
#define FOR(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define FORE(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define FF(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define FFE(i,a,b) for(int (i)=(a);(i)>(b);(i)--)
#define F first
#define S second
#define TT top()
#define FR front()
#define pb push_back
#define sz size()
#define reset(x,n,a) fill((x),(x)+(n)+1,(a))
#define mp make_pair
#define mt make_tuple
#define minimize(a,b) if(a>b) a=b;
#define maximum(a,b) if(a<b) a=b;
#define sc scanf
#define pr printf
#define ll long long
#define llmx 9223372036854775807
#define llmn -9223372036854775808
#define lmx 2147483647
#define lmn -2147483648
#define TASK "MODULO"
using namespace std;
typedef pair<int,int> pii;
void R(int &val)
{
    val=0;char c;
    do{c=getchar();} while(!isdigit(c));
    while(isdigit(c)) {val=val*10+c-48;c=getchar();}
}
char A,B;
string two,k;
string s;
int n;
void inp()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    cin>>A>>B>>n>>k;
}
bool cmp(string a,string b)
{
    while(a.length()<b.length()) a="0"+a;
    while(a.length()>b.length()) b="0"+b;
    return (a>=b);
}
string conv(int num)
{
    string res="";
    while (num!=0)
    {
        res=(char)(num%10+48)+res;
        num=num/10;
    }
    return res;
}
string add1(string a,string b){
    string res1="";
    while(a.size()<b.size()) a='0'+a;
    while(a.size()>b.size()) b='0'+b;
    int carry=0;
    FORE(i,a.size()-1,0){
        int tmp=a[i]+b[i]+carry-96;
        carry=tmp/10;
        res1=(char)(tmp%10+48)+res1;
    }
    if(carry) res1="1"+res1;
    return res1;
}
string minus1(string a,string b)
{
    string res="";
    while(a.length()<b.length()) a="0"+a;
    while(b.length()<a.length()) b="0"+b;
    long borrow=0;
    for(long i=a.length()-1;i>=0;i--)
    {
        long tmp=a[i]-b[i]-borrow;
        if(tmp<0)
        {
            tmp+=10;
            borrow=1;
        }
        else borrow=0;
        res=(char)(tmp+48)+res;
    }
    while(res.length()>1&& res[0]=='0' )
        res.erase(0,1);
    return res;
}
string mul(string a,string b)
{
    string res="";
    int n=a.length();
    int m=b.length();
    int len=n+m-1;
    int carry=0;
    for(int i=len;i>=0;i--)
    {
        int tmp=0;
        for(int j=n-1;j>=0;j--)
            if(i-j<=m && i-j>=1)
            {
                int a1=a[j]-48;
                int b1=b[i-j-1]-48;
                tmp+=a1*b1;
            }
        tmp+=carry;
        carry=tmp/10;
        res=(char)(tmp%10+48) + res;
    }
    while(res.length()>1&&res[0]=='0') res.erase(0,1);
    return res;
}
string mod1(string a,string b)
{
    string sc[11];
    sc[0]="0";
    long k;
    for(long i=1;i<=10;i++) sc[i]=add1(sc[i-1],b);
    string temp="";
    for(long i=0;i<a.length();i++)
    {
        temp=temp+a[i];
        k=1;
        while (cmp(temp,sc[k])) k++;k--;
        temp=minus1(temp,sc[k]);
    }
    return temp;
}
bool check(string p){
    for(auto i:p)
        if(!(i==A||i==B)) return 0;
    return 1;
}
bool get_bit(int val,int id) {return (val>>id)&1;}
void cal()
{
    s.resize(n);
    two="1";
    FOR(i,1,n) two=mul(two,"2");
    int n1=(1<<n)-1;
    FOR(X,0,n1)
    {
        FF(i,0,n){
            if(get_bit(X,i)) s[i]=A;
            else s[i]=B;
        }
        if(mod1(s,two)==k) {cout<<s;return;}
    }
    cout<<-1;
}
int main()
{
    inp();
    cal();
    return 0;
}
