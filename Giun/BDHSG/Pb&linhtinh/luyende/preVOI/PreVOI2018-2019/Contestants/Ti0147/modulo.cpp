#include<bits/stdc++.h>
#define rep(i, a, b) for(int i=(a) ; i<=(b) ; ++i)
#define pii pair<int, int>
#define F first
#define S second
#define PB push_back
#define mp make_pair
#define Task "modulo"
using namespace std;
int a, b, n, k, mod;

void check(string s) {
    int xx=0;
    rep(i, 0, s.size()-1) {
        xx=(xx*10+s[i]-'0')%mod;
    }
    if(xx==k) { cout << s; exit(0); }
}

void trau(int u, string s) {
    if(u==n+1) {
        check(s);
        return;
    }
    char x=a+'0';
    string s1=s+x;
    trau(u+1, s1);
    x=b+'0';
    s1=s+x;
    trau(u+1, s1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> a >> b >> n >> k;
    if(n<=20) {
        mod=(1ll<<n);
        trau(1, "");
        return cout << -1, 0;
    }
    return 0;
}
