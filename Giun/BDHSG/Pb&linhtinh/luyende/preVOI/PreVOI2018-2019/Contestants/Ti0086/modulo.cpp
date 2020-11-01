#include <bits/stdc++.h>

#define rep(i,a,b) for (int i = a,_b = b;i <= _b;++i)
#define per(i,a,b) for (int i = a,_b = b;i >= _b;--i)
#define fore(i,c) for (__typeof(c) i = c.begin();i!=c.end();i++)

#define i64 long long
#define ui64 unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back

#define All(x) x.begin(),x.end()
#define rAll(x) x.rbegin(),x.rend()
#define SZ(x) (int) x.size()

#define DEBUG(X) { cerr << #X << " = " << (X) << endl; }
#define PR(A,l,r) {cerr << #A << " = "; rep(_,l,r) cerr << A[_] <<' '; cerr << endl;}
#define fast_io ios_base :: sync_with_stdio(false),cin.tie(0)

using namespace std;

i64 Read() {i64 x = 0; char c = getchar(); bool neg = false;while (c!='-' && (c < '0' || c > '9')) c=getchar(); if (c=='-') neg=true, c = getchar();while (c>='0' && c<='9') x = x*10+c-'0',c=getchar();if (neg) x = -x; return x;}
void Write(i64 x) {if (x < 0) {putchar('-'); Write(-x); return;};if (x > 9) Write(x/10);putchar(x % 10 + '0');}

ui64 A[2],n,k,MO,now;

void DFS(int i) {
    rep(j,0,1) {
        now = now * 10 + A[j];
        if (i == n) {
            if (now % MO == k) {
                cout << now ;
                exit(0);
            }
        } else DFS(i+1);
        now = (now - A[j]) / 10;
    }
}

#define task "modulo"
main() {
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin >> A[0] >> A[1] >> n >> k; MO = (1 << n);
    DFS(1);
    cout << -1;
}
//cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC <<" s.\n";
