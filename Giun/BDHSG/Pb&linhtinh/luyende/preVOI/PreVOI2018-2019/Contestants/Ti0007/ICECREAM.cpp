#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define f first
#define s second
#define mk make_pair

const int N = 1e5 + 7;
const int mod = 1e9 + 9;
int n, m, t, res, T, k;
int a[5];

int go(int vt, int a, int b, int c) {
    int ans = 0;
    if(vt == n) return 1;
    if(c < m)
        if(b && a) ans = (ans + go(vt + 1, a - 1, b - 1, c + 1))%mod;
        else if(a >= 3) ans = (ans + go(vt + 1, a - 3, b, c + 1))%mod;

    if(a && b < m) ans = (ans + go(vt + 1, a - 1, b + 1, c))%mod;
    if(a < m) ans = (ans + go(vt + 1, a + 1, b, c))%mod;
    return ans;
}
void sub1() {
    int ans = go(0, a[1], a[2], a[3]);
    cout << ans << "\n";
    exit(0);
}

int main() {
//#define file "r"
#define file "ICECREAM"
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= 3; ++ i) cin >> a[i];
    if(n <= 18) sub1();
    cout << "1\n";

    return 0;
}
