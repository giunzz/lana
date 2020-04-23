#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define er(variable) cerr << variable << " "
#define erl(variable) cerr << variable << "\n"
#define loop(variable, valuegan, valuebehonbang) for(long long variable = valuegan; variable <= valuebehonbang; variable++)
#define loopd(variable, valuegan, valuelonhonbang) for(long long variable = valuegan; variable >= valuelonhonbang; variable--)
#define loopdk(variable, valuegan, conditions, thaydoi) for(long long variable = valuegan; conditions; thaydoi) 
#define pp(type, type1) pair<type, type1>
#define vec(type) vector<type>
#define vecite(type) vector<type>::iterator
using namespace std;
const string tenfile = "SC1";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

const string giai[] = {"Giai_dac_biet", "Giai_nhat", "Giai_nhi", "Giai_ba", "Giai_tu", "Giai_nam", "Giai_sau", "Giai_bay", "Giai_tam"};
ll t, sg = LLONG_MAX;
string ve, cg, g;

int main(){
    opt;
    fi;
    cin >> t;
    while(t--){
        cin >> ve;
        //cerr << ve << endl;
        loop(i, 0, 8){
            cin >> g >> cg;
            if (i == 0 && ve == cg) sg = min(sg, i);
            if (i >= 1 && i <= 4 && ve.substr(1) == cg) sg = min(sg, i);
            if (i >= 5 && i <= 6 && ve.substr(2) == cg) sg = min(sg, i);
            if (i == 7 && ve.substr(3) == cg) sg = min(sg, i);
            if (i == 8 && ve.substr(4) == cg) sg = min(sg, i);
            g.clear(), cg.clear(); 
        }
        if (sg == LLONG_MAX) cout << "NONE\n";
        else cout << giai[sg] << "\n";
        sg = LLONG_MAX;
        ve.clear();
    }
}