#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REV(i, r, l) for (int i = r; i >= l; i--)
#define SET(x, val) memset(x, val, sizeof(x))
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pp pop_back

const int inf = 1e9 + 7;
const int esf = 1e-9;
const int N = 1e4 + 7;

int n ;
int cnt = 1;
int f[N][N] , a[N][N];

void hoanvi(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}
void sort_matrix(int m[N][N],int d,int c)
{
    for(int i=0;i<c*d-1;i++)
        for(int j=i+1;j<c*d;j++)
            if(m[i/c][i%c]>m[j/c][j%c])
                hoanvi(m[i/c][i%c],m[j/c][j%c]);
}
void print_matrix(int x[N][N])
{
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < n ; j++) cout << x[i][j] << " ";
        cout << endl;
    }
}

int main() {
    fileInput("giun");
    fast;
    cin >> n ;
    for (int i = 0 ; i <= n ; i++)
        for (int j = 0 ; j <= n ; j++) cin >> f[i][j];
    sort_matrix(f,n,n);
    //print_matrix(f);
    for (int i = 1; i <= 2 * n - 1; i++) {
        if (i <= n) {
            if (i % 2 != 0) {
                for (int j = 1; j <= i; j++) {
                    cerr << i - j + 1 << " " << j << "; ";
                    f[i - j + 1][j] = cnt++;
                }
            } else {
                for (int j = i; j >= 1; j--) {
                    cerr << i - j + 1 << " " << j << "; ";
                    f[i - j + 1][j] = cnt++;
                }
            }
            cerr << endl;
        } else {
            if (i % 2 == 0) {
                for (int j = n; j >= i - n + 1; j--) {
                    cerr << i - j + 1 << " " << j << "; ";
                    f[i - j + 1][j] = cnt++;
                }
            } else {
                for (int j = i - n + 1; j <= n; j++) {
                    cerr << i - j + 1 << " " << j << "; ";
                    f[i - j + 1][j] = cnt++;
                }
            }
            cerr << endl;
        }
    }
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            if (f[i][j] < 10) cout << " ";
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    return (0);
}
👴🏼👴🏼
    return (0);
}
