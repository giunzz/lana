#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for (ll a  =b; a <= c; a++)
#define lpd(a, b, c) for (ll a  =b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;
#define ff "a"

void File(){
    freopen(ff".inp", "r", stdin);
    freopen(ff".out", "w", stdout);
}

cll maxn = 207;
ll a[maxn], n, k, b[maxn] = {0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // File();
    cin >> n >> k;
    lp(i, 1, n) cin >> a[i];
    if(k == n){
        cout << "YES\n" << n << endl;
        lp(i, 1, n){
            cout << i << ' ' << i << endl << -a[i] << endl;
        }
        return 0;
    }
    if(k == 1){
        bool ok = 1;
        ll s, d;
        lp(i, 1, n) {
            if(a[i] > 0) {
                if(ok) s = a[i], ok = 0, d = i;
                else s = __gcd(s, abs(a[i]));
            }
        }
        if(ok) cout << "YES\n0";
        else{
            if(s <= n){
                lp(i, d,  min(d + s - 1, n)){
                    b[i] = a[i];
                }
            } 
            lp(i, 1, n){
                if(a[i] != b[i]){
                    cout << "NO";
                    return 0;
                }
            }
            cout << "YES\n1\n"<< d << ' ' << d + s -1 << endl; 
            lp(i, d, d + s -1){
                cout << -b[i] << ' ';
            }
        }
        return 0;
    }
    if(k == 2){
        // em khong biet lam
        return 0;
    }
    cout << "YES\n3\n";
    cout << "1 " << (n - 1) << endl;
    lp(i, 1, n - 1){
        b[i] = (a[i] % n) * (n - 1);
        a[i] += b[i];
        cout << b[i] << ' ';
    }
    b[n] = -a[n];
    a[n] += b[n];
    cout << '\n' << n << ' ' << n << '\n' << b[n] << "\n1 " << n << endl;
    lp(i, 1, n){
        cout << -a[i] << ' ';
    }
    // doan nay em code hoi ngu :< 
}