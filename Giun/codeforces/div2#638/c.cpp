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

map<char, ll> mp;
ll t, n, k, cnt, check, dem;
char c;
string s;

int main(){
    opt;
   // fi;
    cin >> t;
    for (char i = 'a'; i <= 'z'; i++) mp[i] = 0;
    while(t--){
        cnt = 1, check = 0, dem = 0;
        cin >> n >> k;
        // loop(i, 1, n){
        //     cin >> c;
        //     if(!mp[c]++) s.push_back(c);
        // }
        cin.ignore();
        getline(cin, s);
        sort(s.begin(), s.end());
        if (k == 1) {
            cout << s << "\n";
            continue;
        }
        loop(i, 0, n - 1) ++mp[s[i]];
        for(char i = 'a'; i < s[k - 1]; i++) dem += mp[i];
        if (dem > 0) {
            cout << s[k - 1] << "\n";
            continue;
        }
        if (s[k-1] != s[k]){
            loop(i, k+1, n - 1){
                if (s[i] != s[i - 1]){
                    check = 1;
                }
                ++cnt;
            }
            if(!check)
            {
                if(cnt%2)++cnt;
                cnt /= 2;
                cout << s.substr(k-1, k + cnt - 1) << "\n";
                continue;
            }
        }
        loop(i, k , n - 1) if (s[i] != s[i - 1]) check = 1;
        if (!check) {
            if ((n - k + 1) % 2) ++n;
            cout << s.substr(k - 1, (n - k + 1)/2) << "\n";
            continue;
        }  
        cout << s.substr(k-1) << "\n";
    }
}