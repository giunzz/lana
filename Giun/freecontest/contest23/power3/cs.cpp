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

string f = "pb";
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
    // File("pb");
    while(1){
        sinh();
        if(cham()) break;
    }
    cout << ac << '/' << cs;
}