#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(obj1, obj2, obj3) for(ll obj1 = obj2; obj1 <= obj3; obj1++)
#define lpd(obj1, obj2, obj3) for(ll obj1 = obj2; obj1 >= obj3; obj1--)
#define lpdk(obj1, obj2, obj3, obj4) for(ll obj1 = obj2; obj3; obj4) 
#define pp(obj1, obj2) pair<obj1, obj2>
#define vec(obj1) vector<obj1>
#define vecite(obj1) vector<obj1>::iterator
#define fi first
#define se second
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ofstream co; ifstream ci;
ll m;

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

bool cham(){
    ci.open("fcan3.out");
    map<ll, ll> d;
    ll cong = 0, n, ok = 1, num, num1 = 0;
    ci >> n;
    lp(i, 1, n){
        ci >> num;
        if(num < num1) ok = 0;
        cong += num;
        ++d[num];
        if (d[num] >= 3) ok = 0;
        num1 = num;
    }
    if(cong != m) ok = 0;
    ci.close();
    return ok;
}

int main(){
    srand((int) time(0));
    opt;
    // file;
    freopen("Score.log", "w", stdout);
    cout << "FCAN3\n";
    ll AC = 0;
    lp(i, 1, 100){
        cerr << "Test " << i << ": Dang cham\n";
        cout << "Test " << i << ": ";
        co.open("fcan3.inp");
        if(i <= 40){
            m = Rand(1, 1e3);
            co << m;
        }
        else if(i <= 80){
            m = Rand(1e4, 1e6);
            co << m;
        }
        else {
            m = Rand(1e7, 1e9);
            co << m;
        }
        co.close();
        ll t = clock();
        system("fcan3.exe");
        ll te = clock();
        if(te - t <= 1e3){
            cout << te - t << "ms\n";
            if(cham()) {cout << "AC\n"; ++AC;}
            else cout << "WA\n";
        }
        else cout << "TLE\n";
    }
    cout<< endl << "AC: " << AC << "/100 Tests";
}
