#include <bits/stdc++.h>
#define fto(i,a,b) for (int i=a; i<=b; i++)
#define fdto(i,a,b) for (int i=a; i>=b; i--)
using namespace std;
long long n, k, m;
int a, b;
void nhap ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("modulo.inp", "r", stdin);
    freopen("modulo.out", "w", stdout);
    cin >> a >> b;
    cin >> n >> k;
    m=(1<<n);
}
int get (int x, int i)
{
    return (x>>i)&1;
}
void xuli()
{
    bool ok=false;
    fto (i,0,m-1) {
        long long s=0;
        fdto (j,n-1,0) if (get(i,j)) s=s*10+b; else s=s*10+a;
        if (s%m==k) {
            cout << s << '\n';
            return;}
    }
    if (!ok) cout << -1;
}
int main()
{
    nhap();
    if (n<=18) xuli(); else cout << -1;
    return 0;
}

/*string cong (string a, string b)
{
    while (a.length() > b.length()) b='0'+b;
    while (a.length() < b.length()) a='0'+a;
    int nho=0;
    string s="";
    fdto (i,a.length()-1,0)
    {
        int x=a[i]-'0', y=b[i]-'0';
        int c=x+y+nho;
        nho=c/10; c%=10;
        char z=(char)c+'0';
        s=z+s;
    }
    if (nho>0) {char z=(char)nho+'0';s=z+s;}
    return s;
}
string nhanbe (string a, int x)
{
    string s=""; int nho=0;
    fdto (i,a.length()-1,0)
    {
        int y=a[i]-'0',  c=x*y+nho; nho=c/10; c%=10;
        char z=(char) c+'0';
        s=z+s;
    }
    if (nho>0) {char z=(char)nho+'0';s=z+s;}
    return s;
}
string nhanlon (string a, string b)
{
    int dem=0;
    string s="";
    if (a.length()<b.length()) swap(a,b);
    fdto (i,b.length()-1, 0)
    {
        int x=b[i]-'0';
        string y=nhanbe(a,x);
        fto (i,1,dem) y+='0';
        dem++;
        s=cong(s,y);
    }
    return s;
}
long long chuyen (string a)
{
    long long s=0;
    fto (i,0,a.length()-1)
    {
        int x=a[i]-'0';
        s=s*10+x;
    }
    return s;
}
string doi (long long x)
{
    string s="";
    while (x)
    {
        int tg=x%10; char z=(char)tg+'0';
        s=z+s; x/=10;
    }
    return s;
}
*/
