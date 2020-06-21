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

ll sochu1, sochu2, d1, d2, ac = 0;
string ans, bailam;

int main(){
    srand((int)time(0));
    opt;
    // file;
    freopen("score.log", "w", stdout);
    ofstream co;
    ifstream as, bl;
    lp(i, 1, 1000){
        cout << "Test " << i << ": ";
        co.open("tinhtong.inp");
        if(i <= 400){
            sochu1 = Rand(20, 99);
            sochu2 = Rand(sochu2, 100);
        }
        else if(i <= 800){
            sochu2 = Rand(20, 99);
            sochu1 = Rand(sochu2, 100);
        }
        else{
            sochu1 = Rand(20, 100);
            sochu2 = sochu1;
        }
        if(Rand(1, 100) % 2) co << "-";
        lp(i, 1, sochu1) co << Rand(0, 9);
        co << "\n";
        if(Rand(1, 100) % 2) co << "-";
        lp(i, 1, sochu2) co << Rand(0, 9);
        co.close();
        system("cham.exe");
        ll ts = clock();
        system("tinhtong.exe");
        ll te = clock();
        if(te - ts > 1000) cout << "TLE\n";
        else{
            cout << te - ts << "ms\n";
            as.open("ans.out");
            bl.open("tinhtong.out");
            as >> ans;
            bl >> bailam;
            if (ans == bailam) {cout << "AC\n"; ++ac;}
            else cout << "WA\n"; 
            as.close(); bl.close();
        }
    }
    cout << endl << "AC: " << ac << "/100 tests";
}
