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
const string tenfile = "ac2";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ofstream co;
ifstream ci;
string name=tenfile, no, ni, na, nb;
ll ac = 0, cs = 0;
ll n, g, k, a[100];

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

void Sinh(){
    co.open((ni).c_str());
    co << 1 << endl;
    n = 10, g = Rand(1, 10), k = Rand(1, 10);
    co << n << " " << g << " " << k << endl;
    lp(i, 1, 10) {a[i] = Rand(1, 10); co << a[i] << " ";}
    co.close();
    st(name); 
    //st(nb);
}

struct stc{
    ll mi = INT_MAX, ma = INT_MIN;
}gg[100];

void cham(){
    ++cs;
    ci.open("ac2.out");
    // ll vl = st("fc " + no + " " + na + " /w");
    ll vl = 1, ans[n + 3], tmp = 1;
    string s;
    ci >> s;
    if(s != "IMPOSSIBLE") ans[1] = stoi(s), tmp = 2, vl = 0;
    lp(i, tmp, n) ci >> ans[i];
    if(vl){
        vl = 0;
        lp(i, 1, n) gg[ans[i]] = {min(gg[ans[i]].mi, a[i]), max(gg[ans[i]].ma, a[i])};
        lp(i, 1, g){
            if(abs(gg[i].ma - gg[i].mi) > k) vl = 1;
        }
    }
    ci.close();
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
