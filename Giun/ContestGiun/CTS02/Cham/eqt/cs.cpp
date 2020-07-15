#include <bits/stdc++.h>
#include <windows.h>
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
const string tenfile = "eqt";

ofstream co;
string name=tenfile, no, ni, na, nb;
ll ac = 0, cs = 0;
ll del, t, n;

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

void Sinh(bool tt){
    co.open((ni).c_str());
    if(tt){
        t = 10;
    }
    else {
        t = 1e5;
    }
    co << t << endl;
    lp(i, 1, t){
        if(tt) n = Rand(1e4, 1e6), del = Rand(1, 1e2);
        else n = Rand(1e7, 1e9), del = Rand(1e5, 1e9);
        co << n << " " << del << endl;
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
    lp(i, 1, 2){
        if (i & 1) Sinh(1);
        else Sinh(0);
        cham();
    }
    cout << "ac: " << ac << "/" << cs;
}
