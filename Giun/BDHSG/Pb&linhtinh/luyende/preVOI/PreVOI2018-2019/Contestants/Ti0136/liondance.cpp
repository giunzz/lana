#include <bits/stdc++.h>
using namespace std;
const long maxn=4e2+5;
long n,m,i,j,k,dt;
long l[maxn],r[maxn],f[maxn][maxn];
string s[maxn][maxn],sl[maxn],sr[maxn],sa[maxn],sb[maxn],de;
string chuyen(long k)
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
    if(a<b) {swap(a,b);}
    long muon=0;
    for(long i=a.length()-1;i>=0;i--)
    {
        long tmp=a[i]-b[i]-muon;
        if(tmp<0) {tmp+=10;muon=1;}
        else muon=0;
        res=(char)(tmp+48)+res;
    }
    while(res.length()>1&&res[0]=='0') res.erase(0,1);
    return res;
}
long so(string a)
{
    long res=0;
    for(long i=0;i<a.length();i++)
        res=res*10+(a[i]-48);
    return res;
}
bool cmp(string a,string b)
{
    long d=0,ht=0;
    a=a+" ";
    b=b+" ";
    if(a[0]==' ') a.erase(0,1);
    if(b[0]==' ') b.erase(0,1);
    for(long i=0;i<a.length();i++)
        if(a[i]==' ') d++,sa[d]=a.substr(ht,i-ht),ht=i+1;
    d=0,ht=0;
    for(long i=0;i<b.length();i++)
        if(b[i]==' ') d++,sb[d]=b.substr(ht,i-ht),ht=i+1;
    for(long i=1;i<=d;i++)
    {
        if(so(sa[i])>so(sb[i])) return 1;
        else if(so(sa[i])<so(sb[i])) return 0;
    }
    return 0;
}
bool cmp1(string a,string b)
{
    while(a.length()<b.length()) a="0"+a;
    while(a.length()>b.length()) b="0"+b;
    return a<=b;
}
bool ktra(string a,string b,string s)
{
    long h=s.length();
    if(s[h-1]==' ') s.erase(h-1,1);
    string su;
    for(long i=h-1;i>=0;i--)
        if(s[i]==' ') {su=s.substr(i+1,h-i);break;}
    string u=sub(a,su);
    string v=sub(b,su);
    if(so(u)<=dt && so(v)<=dt) return 1;//{cout << "ok" << '\n';return 1;}
    return 0;
}
void in(string a)
{
    long d=0,ht=0;
    a=a+" ";
    if(a[0]==' ') a.erase(0,1);
    for(long i=0;i<a.length();i++)
        if(a[i]==' ') d++,sa[d]=a.substr(ht,i-ht),ht=i+1;
    cout << d << '\n';
    for(long i=1;i<=d;i++) cout << so(sa[i]) << " ";
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("liondance.inp","r",stdin);
    freopen("liondance.out","w",stdout);
    cin >> n >> dt;
    for(i=1;i<=n;i++) cin >> l[i];
    for(i=1;i<=n;i++) cin >> r[i];
    for(i=1;i<=n;i++) sl[i]=chuyen(l[i]);
    for(j=1;j<=n;j++) sr[j]=chuyen(r[j]);
    de=chuyen(dt);
    s[0][0]="";s[0][1]="";s[1][0]="";
    f[0][0]=0;f[0][1]=0;f[1][0]=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
    {
        if(f[i][j-1]>f[i-1][j]) s[i][j]=s[i][j-1],f[i][j]=f[i][j-1];
        else if(f[i][j-1]<f[i-1][j]) s[i][j]=s[i-1][j],f[i][j]=f[i-1][j];
        else
        {
            if(cmp(s[i-1][j],s[i][j-1])) f[i][j]=f[i-1][j],s[i][j]=s[i-1][j];
            else f[i][j]=f[i][j-1],s[i][j]=s[i][j-1];
        }
        if(l[i]==r[j])
        {
            if(f[i-1][j-1]>=1)
            {
                if(f[i-1][j-1]+1>f[i][j])
                {
                    if(ktra(sl[i],sr[j],s[i-1][j-1]))f[i][j]=f[i-1][j-1]+1,s[i][j]=s[i-1][j-1]+" "+sl[i];
                    else
                    {
                        string tmp=s[i-1][j-1];
                        if(cmp(tmp,s[i][j])) s[i][j]=tmp,f[i][j]=f[i-1][j-1];
                    }
                }
                else
                if(f[i-1][j-1]+1==f[i][j])
                {
                    if(ktra(sl[i],sr[j],s[i-1][j-1]))
                    {
                        string tmp=s[i-1][j-1]+" "+sl[i];
                        if(cmp(tmp,s[i][j])) s[i][j]=tmp;
                    }
                }
            }
            else
            {
                f[i][j]=f[i-1][j-1]+1,s[i][j]=s[i-1][j-1]+" "+sl[i];
            }
        }
    }
    in(s[n][n]);
}
