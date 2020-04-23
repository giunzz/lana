#include <bits/stdc++.h>
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
//opt = optimize 
#define fin(tenfile) freopen(tenfile, "r", stdin)
#define fout(tenfile) freopen(tenfile, "w", stdout)
#define loop(variable, valuegan, valuebehonbang) for(int variable = valuegan; variable <= valuebehonbang; variable++)
#define loopd(variable, valuegan, valuelonhonbang) for(int variable = valuegan; variable >= valuelonhonbang; variable--)
#define loopdk(variable, valuegan, conditions, thaydoi) for(int variable = valuegan; conditions; thaydoi) 

using namespace std;
const int cnv = INT_MAX;
int l[105][105], x, y;
vector<int> tv;

void nhap(){
    char c;
    loop(i, 1, y){
        loop(j, 1, x){
            cin >> c;
            if (c == '*') l[i][j] = INT_MAX - 100;
            else l[i][j] = -1;
        }
    }    
}

void loang(int yl, int xl){
    if (!yl || yl > y || !xl || xl > x) return;
    if (l[yl + 1][xl] != -1 && (yl + 1) <= y){
        if (l[yl + 1][xl] + 1 < l[yl][xl]){
            l[yl][xl] = l[yl + 1][xl] + 1;
        }
    }
    if (l[yl][xl + 1] != -1 && (xl + 1) <= x){
        if (l[yl][xl + 1] + 1 < l[yl][xl]){
            l[yl][xl] = l[yl][xl + 1] + 1;
        }
    }
    if (l[yl - 1][xl] != -1 && (yl - 1) > 0){
        if (l[yl - 1][xl] + 1 < l[yl][xl]){
            l[yl][xl] = l[yl - 1][xl] + 1;
        }
    }
    if (l[yl][xl - 1] != -1 && (xl - 1) > 0){
        if (l[yl][xl - 1] + 1 < l[yl][xl]){
            l[yl][xl] = l[yl][xl - 1] + 1;
        }
    }
    if (l[yl][xl] != l[yl + 1][xl] + 1 && l[yl][xl] + 1 < l[yl + 1][xl]) loang(yl + 1, xl);
    if (l[yl][xl] != l[yl][xl + 1] + 1 && l[yl][xl] + 1 < l[yl][xl + 1]) loang(yl, xl + 1);
    if (l[yl][xl] != l[yl - 1][xl] + 1 && l[yl][xl] + 1 < l[yl - 1][xl]) loang(yl - 1, xl);
    if (l[yl][xl] != l[yl][xl - 1] + 1 && l[yl][xl] + 1 < l[yl][xl - 1]) loang(yl, xl - 1);
}
//0 trai
//1 len
//2 phai 
//3 xuong
void truyvet(int yl, int xl, int yc, int xc){
    if (yl == yc && xl == xc){
        loopd(i, tv.size() - 1, 0) cout << tv[i];
        cout << endl;
    }
    if (l[yl + 1][xl] + 1 == l[yl][xl]) {
        tv.push_back(1);
        truyvet(yl + 1, xl, yc, xc);
        tv.pop_back();
    }
    if (l[yl][xl + 1] + 1 == l[yl][xl]) {
        tv.push_back(0);
        truyvet(yl, xl + 1, yc, xc);
        tv.pop_back();
    }
    if (l[yl - 1][xl] + 1 == l[yl][xl]) {
        tv.push_back(3);
        truyvet(yl - 1, xl, yc, xc);
        tv.pop_back();
    }
    if (l[yl][xl - 1] + 1 == l[yl][xl]) {
        tv.push_back(2);
        truyvet(yl, xl - 1, yc, xc);
        tv.pop_back();
    }
}

int main(){
    int x1, y1, x2, y2;
    opt;
    fin("test.inp");
    fout("test.out");
    cin >> y >> x >> y1 >> x1 >> y2 >> x2;
    nhap();
    l[y1][x1] = 0;
    loang(y1 + 1, x1);
    loang(y1, x1 + 1);
    loang(y1 - 1, x1);
    loang(y1, x1 - 1);
    truyvet(y2, x2, y1, x1);
}