#include <bits/stdc++.h>

#define rep(i,a,b) for (int i = a,_b = b;i <= _b;++i)
#define per(i,a,b) for (int i = a,_b = b;i >= _b;--i)
#define fore(i,c) for (__typeof(c) i = c.begin();i!=c.end();i++)

#define i64 long long
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
const int maxn = 3003;

int n,m,k;
int a[maxn],b[maxn];
int ansa[maxn],ansb[maxn];
int fans[maxn*2],sans[maxn*2];

void Findmina(int sl) {
    if (sl == 0) return ;
    ansa[1] = a[1];
    int now = 1;
    rep(i,2,m) {
        bool ok = true;
        rep(j,1,now) if (ansa[j] > a[i]) {
            if (j +(m-i) >= sl) {
                ansa[j] = a[i];
                now = j;
                ok = false;
                break;
            }
        }
        if (ok) ansa[++now] = a[i];
    }
}

void Findminb(int sl) {
    if (sl == 0) return ;
    ansb[1] = b[1];
    int now = 1;
    rep(i,2,n) {
        bool ok = true;
        rep(j,1,now) if (ansb[j] > b[i]) {
            if (j +(n-i) >= sl) {
                ansb[j] = b[i];
                now = j;
                ok = false;
                break;
            }
        }
        if (ok) ansb[++now] = b[i];
    }
}

void Update_ans(int x,int y) {
    int na = 1,nb = 1;
    rep(i,1,k) {
        if (ansa[na] != ansb[nb]) {
            if (ansa[na] < ansb[nb]) {
                sans[i] = ansa[na++];
            } else {
                sans[i] = ansb[nb++];
            }
        } else {
            if (ansa[na+1] < ansb[nb+1]) {
                sans[i] = ansa[na++];
            } else {
                sans[i] = ansb[nb++];
            }
        }
    }
    rep(i,1,k) if (fans[i] != sans[i]) {
        if (fans[i] > sans[i]) {
            rep(j,1,k) fans[j] = sans[j];
        }
        break;
    }
}

void Solve() {
    rep(i,1,k) fans[i] = maxn;
    rep(i,0,k) {
        int j = k - i;
        if (i > m || j > n) continue;
        Findmina(i); ansa[i+1] = 2*maxn;
        Findminb(j); ansb[j+1] = 2*maxn;
        Update_ans(i,j);
    }
    rep(i,1,k) cout << fans[i] <<' ';
}

#define task "sequence"
main() {
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin >> m >> n >> k;
    rep(i,1,m) {
        cin >> a[i];
    }
    rep(i,1,n) {
        cin >> b[i];
    }
    Solve();
}
//cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC <<" s.\n";
