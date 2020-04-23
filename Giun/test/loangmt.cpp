#include <bits/stdc++.h>
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
//opt = optimize 
#define fin(tenfile) freopen(tenfile, "r", stdin)
#define fout(tenfile) freopen(tenfile, "w", stdout)
#define in(variable) cin >> variable
#define out(variable) cout << variable << " "
#define outl(variable) cout << variable << "\n"
#define err(variable) cerr << variable << " "
#define errl(variable) cerr << variable << "\n"
#define loop(variable, valuegan, valuebehonbang) for(int variable = valuegan; variable <= valuebehonbang; variable++)
#define loopd(variable, valuegan, valuelonhonbang) for(int variable = valuegan; variable >= valuelonhonbang; variable--)
#define loopdk(variable, valuegan, conditions, thaydoi) for(int variable = valuegan; conditions; thaydoi) 
#define ll long long
#define cint const int
#define cll const long long
using namespace std;
cint cnv = INT_MAX;
int y, x, a[105][105] = {{0}}, x1, y1, x2, y2, lo[105][105];

void nhap(){
    char c;
    loop(i, 1, y){
        loop(j, 1, x){
            cin >> c;
            if (c == '*') lo[i][j] = INT_MAX;
            else lo[i][j] = -1;
        }
    }    
}

void loang(int yl, int xl){
    if (!yl || yl > y || !xl || xl > x) return;
    if (lo[yl + 1][xl] != -1 && (yl + 1) <= y){
        if (lo[yl + 1][xl] + 1 < lo[yl][xl]){
            lo[yl][xl] = lo[yl + 1][xl] + 1;
        }
    }
    if (lo[yl][xl + 1] != -1 && (xl + 1) <= x){
        if (lo[yl][xl + 1] + 1 < lo[yl][xl]){
            lo[yl][xl] = lo[yl][xl + 1] + 1;
        }
    }
    if (lo[yl - 1][xl] != -1 && (yl - 1) > 0){
        if (lo[yl - 1][xl] + 1 < lo[yl][xl]){
            lo[yl][xl] = lo[yl - 1][xl] + 1;
        }
    }
    if (lo[yl][xl - 1] != -1 && (xl - 1) > 0){
        if (lo[yl][xl - 1] + 1 < lo[yl][xl]){
            lo[yl][xl] = lo[yl][xl - 1] + 1;
        }
    }
    if (lo[yl][xl] != lo[yl + 1][xl] + 1) loang(yl + 1, xl);
    if (lo[yl][xl] != lo[yl][xl + 1] + 1) loang(yl, xl + 1);
    if (lo[yl][xl] != lo[yl - 1][xl] + 1) loang(yl - 1, xl);
    if (lo[yl][xl] != lo[yl][xl - 1] + 1) loang(yl, xl - 1);
}

int main(){
    opt;
    fin("test.inp");
    fout("test.out");
    cin >> y >> x >> y1 >> x1 >> y2 >> x2;
    nhap();
    lo[y1][x1] = 0;
    loang(y1 + 1, x1);
    loang(y1, x1 + 1);
    loang(y1 - 1, x1);
    loang(y1, x1 - 1);
    loop(i, 1, y){
        loop(j, 1, x){
            cerr << lo[i][j] << "\t";
        }
        cerr << endl;
    }
}