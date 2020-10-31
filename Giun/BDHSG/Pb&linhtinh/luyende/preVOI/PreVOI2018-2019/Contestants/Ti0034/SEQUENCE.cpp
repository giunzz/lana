#include <bits/stdc++.h>

using namespace std;
#define fname "SEQUENCE"
#define For(i, a, b) for(int i = a; i <= b; i++)
#define FOr(i, a, b) for(int i = a; i < b; i++)
#define FOR(i, a, b) for(int i = a; i >= b; i--)
const int N = 3005;
typedef int64_t ll;
const ll inf = 1e15;
int n, m, k, top;
ll a[N], b[N], q[N], res[2*N], cur[2*N], dsa[N][N], dsb[N][N];
ll f[N][N], g[N][N];
void tao(){
    srand(time(NULL));
    freopen (fname".inp", "w", stdout);
    n = 10; m = 6; k = 5;
    cout << n << ' ' << m << ' '<< k << '\n';
    For (i, 1, n) cout <<rand()%10+1<< ' ';
    cout << '\n';
    For (i, 1, m) cout <<rand()%10+1<< ' ';
}
int main(){
    //tao();
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(fname".inp", "r")){
        freopen (fname".inp", "r", stdin);
        freopen (fname".out", "w", stdout);
    }
    cin >> n >> m >> k;
    For (i, 1, n) cin >> a[i];
    For (i, 1, m) cin >> b[i];
    For (i, 1, n){
        top = 0;
        q[++top] = a[1];
        For (j, 2, n){
            while (top > 0 && q[top] > a[j] && n-j+1+top > i) top--;
            q[++top] = a[j];
        }
        For (j, 1, i) dsa[i][j] = q[j];
        f[i][i] = -inf;
        FOR (j, i-1, 1)
            if (dsa[i][j] == dsa[i][j+1]) f[i][j] = f[i][j+1];
            else f[i][j] = q[j+1];
    }
    For (i, 1, m){
        top = 0;
        q[++top] = b[1];
        For (j, 2, m){
            while (top > 0 && q[top] > b[j] && m-j+1+top > i) top--;
            q[++top] = b[j];
        }
        For (j, 1, i) dsb[i][j] = q[j];
        g[i][i] = -inf;
        FOR (j, i-1, 1)
            if (dsb[i][j] == dsb[i][j+1]) g[i][j] = g[i][j+1];
            else g[i][j] = q[j+1];
    }
    For (i, 1, k) res[i] = inf;
    int lim = min(k, n);
    For (len, 1, lim){
        int i = 1, j = 1, cnt = 0;
        int A = len, B = k-len;
        if (B > m) continue;
        while (i <= A && j <= B){
            if (dsa[A][i] == dsb[B][j]){
                if (f[A][i] < g[B][j]){
                    cur[++cnt] = dsa[A][i];
                    i++;
                }
                else{
                    cur[++cnt] = dsb[B][j];
                    j++;
                }
                continue;
            }
            if (dsa[A][i] < dsb[B][j]){
                cur[++cnt] = dsa[A][i];
                i++;
            }
            else{
                cur[++cnt] = dsb[B][j];
                j++;
            }
        }
        while (i <= A){
            cur[++cnt] = dsa[A][i];
            i++;
        }
        while (j <= B){
            cur[++cnt] = dsb[B][j];
            j++;
        }
        For (x, 1, k){
            if (cur[x] < res[x])
                goto line;
            if (cur[x] > res[x]) break;
        }
        continue;
        line:;
        For (x, 1, k) res[x] = cur[x];
    }
    For (i, 1, k) cout << res[i] << ' ';
}
