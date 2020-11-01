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

const int maxn = 4005;

int n,delta,a[maxn];
int L[maxn];
int R[maxn];
int m,ans[maxn];

bool in(int sl) {
    int top = 1;
    rep(i,1,n) if (R[i] == L[a[top]]) {
        top++;
    }
    return (top > sl);
}

void Solve(int sl) {
    if (!in(sl)) return;
    m = sl;
    rep(i,1,sl) if (L[ans[i]] != L[a[i]]){
        if (L[ans[i]] < L[a[i]]) {
            rep(i,1,sl) ans[i] = a[i];
        }
        break;
    }
}

void DFS(int i,int sl) {
    rep(j,a[i-1]+1,n-sl+i) if (abs(L[j]-L[a[i-1]])<=delta || i == 1) {
        a[i] = j;
        if (i == sl) {
            Solve(sl);
        } else DFS(i+1,sl);
    }
}

void Xuli(int sl) {
    a[0] = 0;
    L[0] = 0;
    rep(i,1,sl) ans[i] = 0;
    DFS(1,sl);
}

#define task "liondance"
main() {
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin >> n >> delta;
    rep(i,1,n) cin >> L[i];
    rep(i,1,n) cin >> R[i];
    per(i,n,1) {
        Xuli(i);
        if (m) {
            cout << m <<'\n';
            rep(i,1,m) cout << L[ans[i]] <<' ';
            break;
        }
    }
}
//cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC <<" s.\n";
