#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for (ll a  =b; a <= c; a++)
#define lpd(a, b, c) for (ll a  =b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void File(const string ff){
    freopen((ff + ".inp").c_str(), "r", stdin);
    freopen((ff + ".out").c_str(), "w", stdout);
}

string f = "transport";
ll ac = 0, cs = 0;

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

void sinh(){
    ofstream co;
    co.open((f + ".inp").c_str());
    ll n = Rand(1, 10), m = Rand(1, n);
    co << n << ' ' << m << endl;
    bool d[1000][1000] = {{0}};
    ll u, v, cnt = 0;
    lp(i, 1, n - 1){
        u = i, v = Rand(1, n);
        while(d[u][v] || u == v) u = Rand(1, n), v = Rand(1, n);
        d[u][v] = 1, d[v][u] = 1;
        co << u << ' ' << v << endl;
    }
    co.close();
    system(f.c_str());
    system((f + "_bruce").c_str());
}

bool cham(){
    ++cs;
    ll vl = system(("fc " + f + ".out " + f + ".ans /w").c_str());
    if(!vl) ++ac;
    return vl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand((int)time(0));
    // File("pb");
    while(1){
        cout << cs << endl;
        sinh();
        if(cham()) break;
    }
    cout << ac << '/' << cs;
}