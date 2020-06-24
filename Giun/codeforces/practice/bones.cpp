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
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ll cnt[(ll)1e6] = {0}, s1, s2, s3, ans = -1, d = 0;

int main(){
    opt;
    // file;
    cin >> s1 >> s2 >> s3;
    lp(a, 1, s1){
        lp(b, 1, s2){
            lp(c, 1, s3){
                if(++cnt[a + b + c] > d){
                    ans = a + b + c;
                    d = cnt[a + b + c];
                } 
                if(cnt[a+b+c] == d && (a + b + c) < ans) ans = a + b + c;
            }
        }
    }
    cout << ans;
}
