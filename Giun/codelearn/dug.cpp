#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define fin(tenfile) freopen(tenfile, "r", stdin)
#define fout(tenfile) freopen(tenfile, "w", stdout)
#define in(variable) cin >> variable
#define out(variable) cout << variable << " "
#define outl(variable) cout << variable << "\n"
#define err(variable) cerr << variable << " "
#define errl(variable) cerr << variable << "\n"
#define loop(variable, valuegan, valuebehonbang) for(long long variable = valuegan; variable <= valuebehonbang; variable++)
#define loopd(variable, valuegan, valuelonhonbang) for(long long variable = valuegan; variable >= valuelonhonbang; variable--)
#define loopdk(variable, valuegan, conditions, thaydoi) for(long long variable = valuegan; conditions; thaydoi) 
#define pp(typevalue) pair<typevalue, typevalue>
#define vec(typevalue) vector<typevalue>
#define vec2(typevalue) vector<vector<typevalue>>
#define vecite(typevalue) vector<typevalue>::iterator
using namespace std;
cii maxt = INT_MAX/1e2;

vector<int> bfsDistancesUnweightedGraph(vector<vector<bool>> mat, int n)
{
    int t = mat.size() - 1, bd[15][15];
    vec(ii) ans;
    loop(i, 0, t){
        loop(j, 0, t){
            bd[i][j] = ((mat[i][j]) ? 1 : maxt);
        }
    }
    loop(k, 0, t){
        loop(i, 0, t){
            loop(j, 0, t){
                if ((bd[i][k] + bd[k][j]) < bd[i][j])
                    bd[i][j] = bd[i][k] + bd[k][j];
            }
        }
    }
    loop(i, 0, t){
        ans.push_back((i != n) ? bd[n][i] : 0);
    }
    return ans;
}

int main(){
    opt;
    fin("i.inp");
    fout("o.out");
    vec2(bool) mat{{0, 0, 1}, {0, 0, 1}, {1, 1, 0}};
    int n = 0;
    vec(int) ans = bfsDistancesUnweightedGraph(mat, n);
    for (vecite(int) i = ans.begin(); i < ans.end(); i++){
        cerr << *i << " ";
    }
}