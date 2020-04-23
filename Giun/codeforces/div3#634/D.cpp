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
const string tenfile = "f";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ii t;
string s;

int main(){
    opt;
    fi;
    cin >> t;
    cin.ignore();
    while(t--){
        loop(i, 0, 8){
            getline(cin, s);
            //if (s[(i % 3) * 3 + i / 3] == '9') s[(i % 3) * 3 + i / 3] = s[(i % 3) * 3 + 1 + i / 3];
            //else s[(i % 3) * 3 + i / 3] = '9';
            //if (((i % 3) * 3 + i / 3) == 8) s[(i % 3) * 3 + i / 3] = s[7];
            //else s[(i % 3) * 3 + i / 3] = s[(i % 3) * 3 + 1 + i / 3];
            loop (i, 0, 8) if (s[i] == '1') s[i] = '2';
            cout << s << "\n";
            s.clear();
        }
    }
}