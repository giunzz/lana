#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define lpdk(a, b, c, d) for(ll a = b; c; d) 
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define MOD 1e9 + 7
#define fi first
#define se second
using namespace std;
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

int main(int argc, char **argv){
    if(argc == 2) {
        string a(argv[1]);
        system(("gt -l " + a  + " && gt -h " + a).c_str());
    }
    if(argc == 3){
        string a(argv[1]), b(argv[2]);
        system(("gt -l " + a +  " && gt -h " + a + " -m " + b).c_str());
    }
}