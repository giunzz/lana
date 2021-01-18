#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define fin(tenfile) freopen(tenfile, "r", stdin)
#define fout(tenfile) freopen(tenfile, "w", stdout)
#define errl(variable) cerr << variable << "\n"
#define loop(variable, valuegan, valuebehonbang) for(long long variable = valuegan; variable <= valuebehonbang; variable++)
#define loopd(variable, valuegan, valuelonhonbang) for(long long variable = valuegan; variable >= valuelonhonbang; variable--)
#define loopdk(variable, valuegan, conditions, thaydoi) for(long long variable = valuegan; conditions; thaydoi) 
#define pp(type) pair<type, type>
#define mp make_pair
#define fi first
#define se second
#define vec(type) vector<type>
#define vecite(type) vector<type>::iterator
using namespace std;
string s, ans;
int n, a, b, len = INT_MIN;
vec(vec(int)) c;

void dp(){
    int j; --n;
    loop(k, 1, n){
        loop(i, 0, n - k){
            j = i + k;
            c[i][j] = max(c[i][j - 1], c[i + 1][j]);
            if (s[i] == s[j]) {
                c[i][j] = max(c[i + 1][j - 1] + 2, c[i][j]);
                if(c[i][j] == (c[i + 1][j - 1] + 2) && c[i][j] > len){
                    len = c[i][j], a = i, b = j;
                }
            }
        }
    }
}

int main(){
    opt;
    fin("f.inp");
    fout("f.out");
    getline(cin, s);
    n = s.length();
    c.resize(n);
    loop(i, 0, n - 1) c[i].resize(n), c[i][i] = 1;
    //cerr << c[0][1];
    dp(); 
    while (a < b){
        if (s[a] == s[b]) {
            ans.push_back(s[a]);
            ++a, --b;
        }
        else if (c[a][b] == c[a + 1][b]) ++a;
        else if (c[a][b] == c[a][b - 1]) --b;
    }
    cout << ans;
    if (a == b) cout << s[a];
    reverse(ans.begin(), ans.end());
    cout << ans;
}