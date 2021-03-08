#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
#define mp(a, b) map<a, b>
#define setE(a, b) fill_n(a, sizeof(a)/sizeof(a[0]), b)
#define st(a) system((a).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "daotau";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ofstream co;
string name=tenfile, no, ni, na, nb;
ll ac = 0, cs = 0;

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

cll mxn = 1e6 + 7, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
unordered_map<ll, unordered_map<ll, ll>> mtx;
bool g[mxn] = {0};

void init(){
    ll x = 0, y = 0, d = 0;
    lp(i, 1, 1e6){
        mtx[x][y] = i;
        lp(del, 0, 3) 
            if(mtx[x + dx[del]][y + dy[del]] && mtx[x][y] - mtx[x + dx[del]][y + dy[del]] > 1){
                g[i] = 1;
            }
        if(i != 1 && !mtx[x + dx[(d + 1) % 4]][y + dy[(d + 1) % 4]]) (++d) %= 4;
        x += dx[d], y += dy[d];
    }
}

unordered_map<ll, bool> d;
void Sinh(){
    co.open((ni).c_str());
    ll n = Rand(2, 1e6), k = Rand(1, 1e5);
    co << n << endl << k << endl;
    lp(i, 1, k){
        ll u = Rand(4, 1e6);
        while(!g[u] || d[u]) u = Rand(4, 1e6);
        d[u] = 1;
        co << u << '\n';
    }
    co.close();
    st(name); st(nb);
}

bool cham(){
    ++cs;
    ll vl = st("fc " + no + " " + na + " /w");
    if(!vl) ++ac;
    return vl;
}   

int main(){
    srand((int)time(0));
    // cout << "name: ";
    // cin >> name;
    no = name + ".out";
    ni = name + ".inp";
    na = name + ".ans";
    nb = name + "_bruce";
    init();
    lp(i, 1, 100){
        cerr << "Test " << i << endl;
        Sinh();
        if(cham()) break;
    }
    cout << "ac: " << ac << "/" << cs;
}
