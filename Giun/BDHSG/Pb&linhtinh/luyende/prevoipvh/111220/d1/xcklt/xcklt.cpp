#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void file(const string file){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen((file + ".inp").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
}

const string los = "TRETRAU";
string a, b, c;
ll n, m;
cll maxn = 501;
ll dp[maxn][maxn];  
bool vs[maxn][maxn][maxn] = {{{0}}};

void sub1(){
    if(a == c || b == c) cout << los;
    else if(a == b) cout << 1 << '\n' << a;
    else cout << (a + b);
}

void sol(){
    lp(i, 1, n){
        lp(j, 1, m){
            if(a[i] == b[j]) dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            else
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
        }
    }
}

string ans;

bool trace(ll i, ll j, ll k){
    ll nk = k;
    if(vs[i][j][k]) return 0;
    vs[i][j][k] = 1;
    if(i == 0 && j == 0) return k != 0;
    if(a[i] == b[j]){
        if(j && dp[i][j] == dp[i][j - 1] + 1){
            nk = k;
            if(nk > 0 && b[j] == c[k]) nk = k - 1;
            if(trace(i, j - 1, nk)){
                ans.push_back(b[j]); 
                return 1;
            }
        }
        if(i && dp[i][j] == dp[i - 1][j] + 1){
            nk = k;
            if(nk > 0 && a[i] == c[k]) nk = k - 1;
            if(trace(i - 1, j, nk)){
                ans.push_back(a[i]); 
                return 1;
            }
        }
        if(i && j && dp[i][j] == dp[i - 1][j - 1] + 1){
            nk = k;
            if(nk > 0 && a[i] == c[k]) nk = k - 1;
            if(trace(i - 1, j - 1, nk)){
                ans.push_back(a[i]); 
                return 1;
            }
        }
    }
    else{
        if(j && dp[i][j] == dp[i][j - 1] + 1){
            nk = k;
            if(nk > 0 && b[j] == c[k]) nk = k - 1;
            if(trace(i, j - 1, nk)){
                ans.push_back(b[j]); 
                return 1;
            }
        }
        if(i && dp[i][j] == dp[i - 1][j] + 1){
            nk = k;
            if(nk > 0 && a[i] == c[k]) nk = k - 1;
            if(trace(i - 1, j, nk)){
                ans.push_back(a[i]); 
                return 1;
            }
        }
    }
    return 0;
}

void sub(){
    a = "0" + a;
    b = "0" + b;
    c = "0" + c;
    lp(i, 0, n) dp[i][0] = i;
    lp(i, 0, m) dp[0][i] = i;
    sol();
    bool check = trace(n, m, c.size() - 1);
    if(ans.empty() || !check) cout << los;
    else cout << ans.size() << '\n' << ans;
}

int main(){
    file("xcklt");
    cin >> a >> b >> c;
    n = a.size(), m = b.size();
    if(a.size() == b.size() && a.size() == c.size() && c.size() == 1) sub1();
    else sub();
}