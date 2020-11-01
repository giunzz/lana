    /*Design by Dinh Viet Anh(JOKER)*/
//_____________________________________$$$$$__
//___________________________________$$$$$$$$$
//___________________________________$$$____$
//___________________________$$$____$$$$
//_________________________$$$$$$$__$$$$$$$$$$$
//_______________________$$$$$$$$$___$$$$$$$$$$$
//_______________________$$$____$_____$$$$$$$$$$
//________________$$$$__$$$$_________________$$$
//_____________$__$$$$__$$$$$$$$$$$_____$____$$$
//__________$$$___$$$$___$$$$$$$$$$$__$$$$__$$$$
//_________$$$$___$$$$$___$$$$$$$$$$__$$$$$$$$$
//____$____$$$_____$$$$__________$$$___$$$$$$$
//__$$$$__$$$$_____$$$$_____$____$$$_____$
//__$$$$__$$$_______$$$$__$$$$$$$$$$
//___$$$$$$$$$______$$$$__$$$$$$$$$
//___$$$$$$$$$$_____$$$$___$$$$$$
//___$$$$$$$$$$$_____$$$
//____$$$$$$$$$$$____$$$$
//____$$$$$__$$$$$___$$$
//____$$$$$___$$$$$$
//____$$$$$____$$$
//_____$$$$
//_____$$$$
//_____$$$$
#include <bits/stdc++.h>
#define maxn 1000005
#define maxm 10000005
#define maxc 1000000007
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define pii pair<int, int>
#define fort(i, a, b) for(int i = (a); i <= (b); i++)
#define ford(i, a, b) for(int i = (a); i >= (b); i--)
#define Task "minsum"
#define stop1 {cout << "-1\n"; return;}
#define stop2 {cout << "NO\n"; return;}
#define stop3 {cout << "YES\n"; return;}
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long

template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar())) x=x*10+c-48;if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}

using namespace std;

int T, a, b;
ll aa, bb;
ll q[maxn], dem;
ll tich;

void setup()
{
    cin >> T;
}

void dequy(int id, ll ti)
{
    if(id > dem)
    {
        if(aa + bb > ti + tich / ti)
            aa = ti, bb = tich/ti;
        return;
    }
    dequy(id+1, ti * q[id]);
    dequy(id+1, ti);
}

void work()
{
    while(T--)
    {
        cin >> a >> b;
        int gcd = __gcd(a,  b);
        a /= gcd;
        b /= gcd;
        aa = 1;bb=1;
        fort(i, 2, sqrt(a)) if(a % i == 0)
        {
            int dema = 0;
            while(a % i == 0)
            {
                dema++;
                a /= i;
            }
            if(dema % 2)
            {
                aa *= i;
                q[++dem] = i;
            }
        }
        if(a > 1)
        {
            aa *= a;
            q[++dem] = a;
        }
        fort(i, 2, sqrt(b)) if(b % i == 0)
        {
            int demb = 0;
            while(b % i == 0)
            {
                demb ++;
                b /= i;
            }
            if(demb % 2)
            {
                bb *= i;
                q[++dem] = i;
            }
        }
        if(b > 1)
        {
            bb *= b;
            q[++dem] = b;
        }

        tich = aa* bb;
        dequy(1, 1);

        cout << aa << " " << bb << "\n";

        dem = 0;
    }
}

void sinh()
{
    freopen(Task".inp", "w", stdout);
    srand(time(0));
    cout << "8\n";
    fort(i, 1, 8)
    {
        cout << rand() % 1000000000+1000000 << " " << rand() % 1000000000+1000000 << '\n';
    }
}

int main()
{
    fast
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    setup();
    work();
    return 0;
}
