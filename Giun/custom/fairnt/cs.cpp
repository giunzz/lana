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
const string tenfile = "fairnt";
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

void Sinh(){
    co.open((ni).c_str());
    bool dk[107] = {0};
    map<ll, map<ll, bool>> g;
    ll n = 200, m = min(Rand(n - 1, n * (n - 1) / 2), (ll)1e5);
    ll k = min(Rand(1, n), (ll)100), s, ak[207], cnt = 0;
    lp(i, 1, n) ak[i] = Rand(1, k), cnt += !dk[ak[i]], dk[ak[i]] = 1;
    s = Rand(1, cnt);
    co << n << " " << m << " " << k << " " << s << endl;
    m -= (n - 1);
    lp(i, 1, n) co << ak[i] << " ";
    co << endl;
    lp(i, 1, n - 1){
        co << i << " " << i + 1 << endl;
        g[i][i + 1] = 1;
        g[i + 1][i] = 1;
    }
    lp(i, 1, m){
        ll u = Rand(1, n);
        ll v = Rand(1, n);
        while(u == v || g[u][v] || g[v][u]) u = Rand(1, n), v = Rand(1, n);
        co << u << " " << v << endl;
        g[u][v] = 1, g[v][u] = 1;
    }
    co.close();
    st(name); st(nb);
}

void cham(){
    ++cs;
    ll vl = st("fc " + no + " " + na + " /w");
    if(!vl) ++ac;
}   

int main(){
    srand((int)time(0));
    // cout << "name: ";
    // cin >> name;
    no = name + ".out";
    ni = name + ".inp";
    na = name + ".ans";
    nb = name + "_bruce";
    lp(i, 1, 100){
        Sinh();
        cham();
    }
    cout << "ac: " << ac << "/" << cs;
}


// 6 11 6 4
// 3 5 4 3 2 5 
// 1 2
// 2 3
// 3 4
// 4 5
// 5 6
// 1 6
// 5 1
// 1 3
// 2 5
// 2 4
// 6 3
