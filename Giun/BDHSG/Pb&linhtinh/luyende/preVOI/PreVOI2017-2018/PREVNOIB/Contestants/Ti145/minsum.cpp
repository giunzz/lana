// MR.J
#include<bits/stdc++.h>
#define maxn
#define maxC 1000000000
#define MOD 1000000007
#define mp make_pair
#define PB push_back
#define F first
#define S second
#define pii pair<int, int>
#define ll long long
#define rep(i, a, b) for(int i=(a) ; i<=(b) ; ++i)
#define repd(i, a, b) for(int i=(a) ; i>=(b) ; --i)
#define Task "minsum"
using namespace std;
int T, a, b;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> a >> b;
        int xx = __gcd(a, b);
        cout << a/xx << ' ' << b/xx << '\n';
    }

    return 0;
}
