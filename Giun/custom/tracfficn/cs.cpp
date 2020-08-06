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
const string tenfile = "tracfficn";
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
    ll n = 10, m = Rand(n, n * (n - 1) / 2), k = Rand(1, n), s = Rand(1, n), t = Rand(1, n);
    while(s == t) s = Rand(1, n), t = Rand(1, n);
    co << n << " " << m << " " << k << " " << s << " " << t << endl;
    map<ll, map<ll, bool>> g;
    lp(i, 1, n - 1){
        co << i << " " << (i + 1) << " " << Rand(1, 1000) << endl;
        g[i][i+1] = 1;
    }
    m -= (n - 1);
    ll u, v;
    lp(i, 1, m){
        u = Rand(1, n), v = Rand(1, n);
        while(u == v || g[u][v]) u = Rand(1, n), v = Rand(1, n);
        g[u][v] = 1;
        co << u << " " << v << " " << Rand(1, 1000) << endl;
    }
    g.clear();
    lp(i, 1, k){
        u = Rand(1, n), v = Rand(1, n);
        while(u == v || g[u][v]) u = Rand(1, n), v = Rand(1, n);
        g[u][v] = 1;
        co << u << " " << v << " " << Rand(1, 25) << endl;
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
