#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for (ll a  =b; a <= c; a++)
#define lpd(a, b, c) for (ll a  =b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void File(const string ff){
    freopen((ff + ".inp").c_str(), "r", stdin);
    freopen((ff + ".out").c_str(), "w", stdout);
}

inline ll loud(ll n, ll k){
    // sau k lan duoi -> k + 1 nhom nguoi
    ++k;
    ll nhom = n / k, du = n % k; //a a (a + 1) (a + 1)           a
    ll s = k * nhom * (nhom + 1) / 2 + du * (nhom + 1); // 1 + 2 + 3 + .. + a + (a + 1) = a*(a+1)/2 + (a+1)
    return s;
}

cll maxm = 107, maxk = 507;
ll n, m, k, a[maxm] = {0}, f[maxm][maxk], s = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    File("f");
    cin >> n >> m >> k;
    ll tmp;
    lp(i, 1, n){
        cin >> tmp;
        ++a[tmp];
    }
    lp(i, 0, m)
        lp(j, 0, k) f[i][j] = LLONG_MAX;
    f[0][0] = 0;
    lp(i, 1, m){
        lp(j, 0, k){
            lp(z, 0, j){
                if(f[i - 1][z] == LLONG_MAX) break;
                f[i][j] = min(f[i][j], f[i - 1][z] + loud(a[i], j - z));
            }
        }
    }
    cout << f[m][k];
}
