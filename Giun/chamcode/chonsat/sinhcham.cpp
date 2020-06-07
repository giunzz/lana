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

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

ll n, num, ans, slans, bl, ac =0, bl1 ;
vec(ll) a;
map<ll, ll> d;

int main(){
    srand((int)time(0));
    opt;
    // file;
    ifstream ci;
    ofstream co, log;
    log.open("score.log");
    lp(i, 1, 100){
        slans = -1, ans = -1;
        a.clear();
        d.clear();
        log << "Test " << i << ": ";
        co.open("chonsat.inp");
        n = Rand(2, 100);
        co << n << endl;
        lp(i, 1, n){
            num = Rand(1, 10);
            if(!d[num]++) a.push_back(num);
            co << num << " ";
        }
        sort(a.begin(), a.end());
        lpd(i, a.size() - 1, 0){
            if(d[a[i]] > slans) slans = d[a[i]], ans = a[i];
        
        }
        co.close();
        system("chonsat.exe");
        ci.open("chonsat.out");
        ci >> bl >> bl1;
        if (bl == slans && bl1 == ans) {log << "AC\n"; ++ac;}
        else log << "WA\n";
        co.close();
    }
    cerr << slans << " " << ans;
    log << endl << "AC: " << ac << "/100";
}
