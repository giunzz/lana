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
const string tenfile = "transpo";
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
    ll n = Rand(1e4, 1e5), m = Rand(n - 1, min((ll)2e5, n * (n - 1) / 2));
    vec(ll) per(n + 1);
    lp(i, 1, n) per[i] = i;
    random_shuffle(per.begin() + 1, per.end());
    map<pp(ll, ll), bool> mp;
    co << n << ' ' << m << '\n';
    lp(v, 2, n){
        ll u = Rand(1, v - 1);
        co << per[u] << ' ' << per[v] << ' ' << Rand(1, 1e9) << '\n';
        mp[{u, v}] = mp[{v, u}] = 1;
    }
    lp(i, n, m){
        ll u = Rand(1, n), v = Rand(1, n);
        while(u == v || mp[{u, v}]) u = Rand(1, n), v = Rand(1, n);
        co << per[u] << ' ' << per[v] << ' ' << Rand(1, 1e9) << '\n'; 
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
