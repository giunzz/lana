//khai bao mo dau
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
#define loop(variable, valuegan, valuebehonbang) for(ll variable = valuegan; variable <= valuebehonbang; variable++)
#define loopd(variable, valuegan, valuelonhonbang) for(ll variable = valuegan; variable >= valuelonhonbang; variable--)
#define loopdk(variable, valuegan, conditions, thaydoi) for(ll variable = valuegan; conditions; thaydoi) 
#define pp pair<long long, long long>
#define vec vector<long long>
#define vec2 vector<vector<long long>>
#define ll long long
#define cint const int
#define cll const long long
using namespace std;
//khai bao hang ctrinh goc
cll maxd = INT_MAX;
class codesol{
    private:
    //khai bao bien ctrinh goc (bien toan cuc) va cac ham xu ly khac main
ll n, m, k, dt[107][107] = {{0}}, d[107][107], t[107][107], dem = 0;

void enter(){
    ll x, y, l;
    loop(i, 1, m){
        cin >> x >> y >> l;
        dt[x][y] = l; 
        dt[y][x] = l;
    }
    loop(u, 1, n){
        loop(v, 1, n){
            if (u == v) d[u][v] = 0;
            else {
                d[u][v] = (dt[u][v]) ? dt[u][v] : maxd;
            }
            t[u][v] = (dt[u][v]) ? v : 0;
        }
    }
}

void floy(){
    loop(k, 1, n){
        loop(i, 1, n){
            loop(j, 1, n){
                if (d[i][j] > (d[i][k] + d[j][k])){
                    d[i][j] = d[i][k] + d[j][k];
                    t[i][j] = t[i][k];
                }
            }
        }
    }
}

vector<ll> trace(ll u, ll v){
    vector<ll> path;
    do{
        path.push_back(u);
        u = t[u][v];
    } while(path.back() != v);
    return path;
}

void xuat(){
    vector<ll> ans;
    vector<ll>::iterator ii;
    loop(i, 1, n){
        loop(j, 1, n){
            if (d[i][j] == k) ++dem;
        }
    }
    cout << dem << endl;
    loop(i, 1, n){
        loop(j, 1, n){
            if (d[i][j] == k){
                ans = trace(i, j);
                for (ii = ans.begin(); ii < ans.end(); ii++){
                    cout << *ii << " ";
                }
                cout << endl;
                ans.clear();
            }
        }
    }
}
    public:
    //ham main doi thanh run them index path, chuyen input file open thanh path
void run(char duongdan[]){
    //int t1 = clock();
    opt;
    fin(duongdan);
    fout("pathk.out");
    cin >> n >> m >> k;
    enter();       
    floy();
    xuat();
}
};