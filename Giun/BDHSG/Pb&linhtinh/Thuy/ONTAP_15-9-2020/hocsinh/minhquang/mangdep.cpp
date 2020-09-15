#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for (ll a  =b; a <= c; a++)
#define lpd(a, b, c) for (ll a  =b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

ll nen[45];

void init(){
    nen[4] = 1, nen[8] = 2, nen[15] = 3, nen[16] = 4, nen[23] = 5, nen[42] = 6;
}

void File(const string ff){
    freopen((ff + ".inp").c_str(), "r", stdin);
    freopen((ff + ".out").c_str(), "w", stdout);
}

cll maxn = 1e6 + 7;
ll n, a[maxn], d[7] = {0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    File("mangdep");
    init();
    cin >> n;
    ll tmp;
    lp(i, 1, n){
        cin >> tmp;
        a[i] = nen[tmp];
        if(d[a[i] - 1]){
            --d[a[i] - 1], ++d[a[i]];
        }
        if(a[i] == 1) ++d[a[i]];
    }
    //lp(i, 1, 6) cerr << d[i] << ' ';
    cout << (n - d[6] * 6);
}
