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
//_________$$$_____$$$$__________$$$___$$$$$$$
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
#define maxn 2005
#define maxm 10000005
#define maxc 1000000007
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define pii pair<int, int>
#define fort(i, a, b) for(int i = (a); i <= (b); i++)
#define ford(i, a, b) for(int i = (a); i >= (b); i--)
#define Task "teaworld"
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

int n, m, k, sx, sy, sz, demy, demz, res;
int ke[16][maxn], sl[16];
struct ball
{
    int x, y, z, r;
}balls[maxn];

struct sto
{
    int x, y, z, e;
}store[20];

ll dis(int x, int y, int p, int q)
{
    return 1ll*(x-p) * (x-p) + 1ll*(y - q) * (y-q);
}

bool check(sto p, ball q)
{
    if(dis(sx, sy, q.x,q.y) <= q.r*q.r && dis(p.x,p.y, q.x,q.y) > q.r*q.r) return 1;
    if(dis(sx, sy, q.x,q.y) > q.r*q.r && dis(p.x,p.y, q.x,q.y) <= q.r*q.r) return 1;


    if(dis(sx, sy, q.x,q.y) > q.r*q.r && dis(p.x,p.y, q.x,q.y) > q.r*q.r)
    {
        int a = p.y - sy;
        int b = -p.x + sx;
        int c = a * (- sx) - b*sx;
        if(a*q.x+b*q.y + c == 0)
        {
            if(q.x < sx && q.x > p.x) return 1;
            if(q.x > sx && q.x < p.x) return 1;
        }
        else if(1ll*q.r*q.r*(a*a+b*b) >= abs(a*q.x + b * q.y+c) * abs(a*q.x + b * q.y+c) && ((q.x < sx && q.x > p.x) || (q.x > sx && q.x < p.x) || (q.y < sy && q.y > p.y) || (q.y > sy && q.y < p.y)))
            return 1;
    }

    return 0;
}

int dd[maxn];

void ok1()
{
    fort(i, 1, n)
        fort(j, 1, m)
            if(check(store[i], balls[j]))
                ke[i][++sl[i]] = j;
    fort(i, 0, (1 << n) - 1)
    {
        int dem = 0, tong = 0;
        fort(j, 1, n) if( (i >> (j- 1)) & 1)
        {
            tong += store[j].e;
            fort(l, 1, sl[j])
            {
                int v = ke[j][l];
                if(dd[v] != i)
                {
                    dem++;
                    dd[v] = i;
                }
                if(dem > k) break;
            }
            if(dem > k) break;
        }
        if(dem <= k) res = max(res, tong);
    }
    cout <<res;
}

void setup()
{
    cin >> m >> n >> k;
    fort(i, 1, m)
    {
        cin >> balls[i].x >> balls[i].y >> balls[i].z >> balls[i].r;
        demy += (balls[i].y == 0);
        demz += (balls[i].z == 0);
    }
    fort(i, 1, n)
    {
        cin >> store[i].x >> store[i].y >> store[i].z >> store[i].e;
        demy += (store[i].y == 0);
        demz += (store[i].z == 0);
    }
    cin >> sx >> sy >> sz;
    demy += (sy == 0);
    demz += (sz == 0);
    if(demz == m+n+1)
        ok1();
}

void work()
{

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
