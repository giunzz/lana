/**Lucky Boy**/
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 100005
#define maxm 500005
#define pii pair <int,int>
#define Task "MODULO"
template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar())) x=x*10+c-48;if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}
using namespace std;
int a,b,n;
unsigned long long k;
unsigned long long mod = 1;
map <unsigned long long,string> dd1,dd2;
map <unsigned long long,string> :: iterator it;
string add(string a,string b)
{
    string res = "";
    char c;
    int nho = 0;
    while(a.length() < b.length()) a = '0' + a;
    while(b.length() < a.length()) b = '0' + b;
    int n = a.length();
    FORD(i,n-1,0)
    {
        nho = nho + a[i] + b[i] - 2 * '0';
        c = nho % 10 + '0';
        res = c + res;
        nho /= 10;
    }
    if (nho) res = '1' + res;
    return res;
}
string sub(string a,string b)
{
    string res = "";
    int nho = 0;
    bool neg = 0;
    char c;
    while(a.length() < b.length()) a = '0' + a;
    while(b.length() < a.length()) b = '0' + b;
    if (a < b) neg = 1,swap(a,b);
    int n = a.length();
    FORD(i,n-1,0)
    {
        nho = a[i] - b[i] - nho;
        if (nho < 0)
        {
            res = (char) (nho+58) + res;
            nho = 1;
        }
        else
        {
            res=(char)(nho+48)+res;
            nho=0;
        }
    }
    while (res[0] == '0' && (int) res.length() > 1) res.erase(0,1);
    if (neg) res = '-' + res;
    return res;
}
string mul(string a,string b)
{
    string res = "";
    int nho = 0;
    char c;
    int n = a.length(),m = b.length();
    FORD(i,n+m-1,0)
        {
            FORD(j,n-1,0)
                if ((i-j<=m)&&(i-j)>=1) nho+=(a[j]-48)*(b[i-j-1]-48);
            res=(char)(nho%10+48)+res;
            nho/=10;
        }
    while (res[0] == '0' && (int) res.length() > 1) res.erase(0,1);
    return res;
}
unsigned long long MOD(string a)
{
    unsigned long long res = 0;
    for (char c : a)
    {
        res = res * 10 + (c - '0');
        res %= mod;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(Task".inp", "r",stdin);
    freopen(Task".out", "w",stdout);
    cin >> a >> b >> n >> k;
    if (n == 1)
    {
        n = 2;
        if (a % n == k) cout << a;
        else if (b % n == k) cout << b;
        else cout << -1;
        return 0;
    }
    FOR(i,1,n) mod *= 2;
    int p1 = n / 2,
        p2 = n - p1;
    FOR(i,0,(1 << p1) - 1)
    {
        string temp = "0";
        FOR(j,0,p1-1)
        {
            temp = mul(temp,"10");
            string ww = "";
            if ((i >> j) & 1) ww = ww + (char) ('0' + a);
            else ww = ww + (char) ('0' + b);
            temp = add(temp,ww);
        }
        unsigned long long du = MOD(temp);
        FOR(j,1,p2)
        {
            du = du * 10;
            du %= mod;
        }
        dd1[du] = temp;
    }
    FOR(i,0,(1 << p2) - 1)
    {
        string temp = "0";
        FOR(j,0,p2-1)
        {
            temp = mul(temp,"10");
            string ww = "";
            if ((i >> j) & 1) ww = ww + (char) ('0' + a);
            else ww = ww + (char) ('0' + b);
            temp = add(temp,ww);
        }
        unsigned long long du = MOD(temp);
        dd2[du] = temp;
    }
    for (it = dd1.begin(); it != dd1.end();++it)
    {
        pair <unsigned long long,string> temp = *it;
        unsigned long long du = (mod + k - temp.F) % mod;
        if (dd2[du] != "")
        {
            cout << temp.S << dd2[du];
            return 0;
        }
    }
    cout << -1;
    return 0;
}
