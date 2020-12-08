#include <bits/stdc++.h>
#define ll short
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

class EllysFlags{
    private:
    int maxMask = (1 << 20) + 7;
    ll n, m;
    vec(vec(vec(ll))) f;
    vec(vec(ll)) b, e;
    public:
    int getMax(vec(string) a);
    ll sol(ll i, ll j, int mask);
};

ll EllysFlags::sol(ll i, ll j, int mask){
    if(i >= n) return 0;
    if(j >= m) return sol(i + 1, 0, mask);
    if(f[i][j][mask] != -1) return f[i][j][mask];
    ll res = 0;
    if(b[i][j] == 0){
        e[i][j] = 3;
        res = max(res, sol(i, j + 1, (mask >> 2) | (e[i][j] << ((m - 1) << 1))));
    }
    if(b[i][j] == 0 || b[i][j] == 1){
        e[i][j] = 0;
        if(i > 0 and e[i - 1][j] == 3) ++e[i][j];
        if(j > 0 and e[i][j - 1] == 3) ++e[i][j];
        res = max(res, sol(i, j + 1, (mask >> 2) | (e[i][j] << ((m - 1) << 1))));
    }
    if(b[i][j] == 0 || b[i][j] == 2){
        ll tmp = 0;
        if(i > 0 and e[i - 1][j] != 3) tmp += e[i - 1][j];
        if(j > 0 and e[i][j - 1] != 3) tmp += e[i][j - 1];
        res = max(res, (short)(sol(i, j + 1, (mask >> 2) | (e[i][j] << ((m - 1) << 1))) + tmp));
    }
    return f[i][j][mask] = res;
}

int EllysFlags::getMax(vec(string) a){
    this -> n = a.size(), this -> m = a.back().size();
    f.assign(n + 7, vec(vec(ll))(m + 7, vec(ll)(maxMask, -1)));
    b.assign(n + 7, vec(ll)(m + 7));
    e.assign(n + 7, vec(ll)(m + 7, 0));
    char t;
    lp(i, 0, n - 1) lp(j, 0, m - 1) 
        if((t = a[i][j]) == 'W'){b[i][j] = 0;} 
        else if(t == 'G'){b[i][j] = 1;}
        else b[i][j] = 2;
    return sol(0, 0, 0);
}   

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    EllysFlags tmp;
    try{
        cout << tmp.getMax({"WGWWR","GRGRG","RWGRW","GGWGR"});  
    }
    catch(const exception& e){
        cerr << e.what() << '\n';
    }
}