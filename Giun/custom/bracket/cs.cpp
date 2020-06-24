#include <bits/stdc++.h>
#define ii int
#define ll long long
#define sr string
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(obj1, obj2, obj3) for(ll obj1 = obj2; obj1 <= obj3; obj1++)
#define lpd(obj1, obj2, obj3) for(ll obj1 = obj2; obj1 >= obj3; obj1--)
#define pp(obj1, obj2) pair<obj1, obj2>
#define vec(obj1) vector<obj1>
#define vecite(obj1) vector<obj1>::iterator
#define fi first
#define se second
#define mp(obj1, obj2) map<obj1, obj2>
#define st(obj) system((obj).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "bracket";
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

void sinh(){
    co.open((ni).c_str());
    lp(i,1,15)
    if(Rand(0, 1)) co << "(";
    else co << ")";
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
    lp(i, 1, 5){
        sinh();
        cham();
    }
    cout << "ac: " << ac << "/" << cs;
}
