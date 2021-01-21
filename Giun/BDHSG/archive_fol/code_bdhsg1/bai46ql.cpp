#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define loop(variable, valuegan, valuebehonbang) for(ll variable = valuegan; variable <= valuebehonbang; variable++)
#define loopd(variable, valuegan, valuelonhonbang) for(ll variable = valuegan; variable >= valuelonhonbang; variable--)
#define loopdk(variable, valuegan, conditions, thaydoi) for(ll variable = valuegan; conditions; thaydoi) 
#define pp(type, type1) pair<type, type1>
#define vec(type) vector<type>
#define vecite(type) vector<type>::iterator
using namespace std;
const string tenfile = "f";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

string chankobuonnghiten, ans;
vec(ii) ansvt;
ii tt;

void quaylui(int vitri){
    bool checkkyty[500] = {0};
    if(ansvt.empty()) tt = 0;
    else tt = ansvt.back() + 1;
    loop(i, tt, chankobuonnghiten.length() - 1){
        if (checkkyty[chankobuonnghiten[i]]) continue;
        ansvt.push_back(i); ans.push_back(chankobuonnghiten[i]);
        checkkyty[chankobuonnghiten[i]] = 1;
        cout << ans << "\n";
        quaylui(vitri + 1);
        ansvt.pop_back(); ans.pop_back();
    }
}

int main(){
    opt;
    fi;
    getline(cin, chankobuonnghiten);
    quaylui(0);
}