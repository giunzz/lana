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

string s, op;
vec(string) opvt;
map<char, ll> d;
ll n, sl = 0;
char q;

int main(){
    opt;
    fi;
    cin >> n >> s;
    s = '0' + s;
    for (char i = 'a'; i <= 'z'; i++)
        cin >> d[i], sl += d[i];
    opvt.resize(n + 1);
    loop(i, 1, n){
        q = s[i];
        while(!d[q] && q <= 'z') ++q;
        if (q > 'z') {
            loopd(j, i, 1)
                if(opvt[j] != ""){
                    cout << opvt[j];
                    return 0;
                }
            cout << "-1";
            return 0;
        }
        if (q != s[i]) {
            op.push_back(q);
            cout << op;
            return 0;
        }
        --d[q++];
        while(!d[q] && q <= 'z') ++q;
        if (q > 'z') {
            opvt[i] = "";
        }
        else {
            op.push_back(q);
            opvt[i] = op;
            op.pop_back();
        }
        op.push_back(s[i]);
    }
    if(op.length() >= n) cout << op;
    else{
        loopd(i, n, 1){
            if(opvt[i] != ""){
                cout << opvt[i];
                return 0;
            }
    }
    cout << "-1";
    }
}