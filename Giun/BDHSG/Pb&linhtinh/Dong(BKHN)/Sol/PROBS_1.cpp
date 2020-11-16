#include <bits/stdc++.h>
#define Mask(n) (1 << (n))
#define Bit(x, i) (((x) >> (i)) & 1)
#define Mod 1000000007
#define M 31
#define N 20

using namespace std;

string n;
int m;
int k;
bool d[M][6][N][2];
long long f[M][6][N][2];

void reup(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void enter(){
    reup();
    cin >> m;
    cin >> k;
}

void init(){
    while(m > 0){
        char c = (m % 2) + '0';
        n = c + n;
        m = m / 2;
    } 
    m = n.length();
    n = '0' + n;
}

int check(int isless, int s){
    int res = isless;
    for(int i = 1; i <= k - 1; ++i){
        bool biti = Bit(s, i) > 0;
        bool bitpre = Bit(s, i - 1) > 0;
        bool tb = Bit(res, i - 1) > 0;
        if(tb)
            continue;
        if(biti < bitpre)
            return -1;
        else 
            if(biti > bitpre)
                res |= Mask(i - 1);
    }
    return res;
}

void module(long long &a){
    if(a >= Mod)
        a %= Mod;
}

long long magic(int i, int remember, int isless, bool ismorezero){
    if(i > m)
        return (remember == 0) && (isless == Mask(k - 1) - 1) && (ismorezero);
    long long &res = f[i][remember][isless][ismorezero];
    if(d[i][remember][isless][ismorezero])
        return res;
    d[i][remember][isless][ismorezero] = 1;
    res = 0;
    bool uu;
    for(int s = 0; s < Mask(k); ++s){
        uu = ismorezero;
        if(Bit(s, 0))
            uu = 1; 
        int ok = check(isless, s);
        if(ok == -1)
            continue;
        for(int nho = 0; nho < k; ++nho){
            int t = __builtin_popcount(s) + nho;
            if(t % 2 == n[i] - '0' && t / 2 == remember)
                res += magic(i + 1, nho, ok, uu);
        }
        module(res);
    }
    return res;
}

void solve(){
    cout << magic(1, 0, 0, 0);
}

int main(){
    //freopen("file.inp", "r", stdin);
    //freopen("file.out", "w", stdout);
    enter();
    init();
    solve();
    return 0;
}