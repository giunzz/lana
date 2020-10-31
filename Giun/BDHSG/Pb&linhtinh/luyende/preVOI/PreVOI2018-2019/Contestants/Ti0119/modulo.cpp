#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<long long, long long> ii;

const int N = 70;

map<long long, long long> dp[N];

long long a, b, n, k, power[N], mod, cnt;

long long mul(long long c, long long d) {
    return (1ll * c * d) % mod;
}

long long add(long long c, long long d) {
    return (1ll * c + 1ll * d) % mod;
}

void bt(int pos, long long m, string s) {
    if(dp[pos][m] > 0)
        return ;
    dp[pos][m]++;
    cnt++;
    if(cnt >= 10000000) {
        cout << "-1\n";
        exit(0);
    }
    if(pos == n + 1) {
        if(m == k) {
            for(int i = 0; i < s.length(); i++) {
                if(s[i] == '1')
                    cout << a;
                else
                    cout << b;
            }
            exit(0);
        }
        return ;
    }
    string t = s;
    bt(pos + 1, add(mul(mul(m, 2), 5), a), t + '1');
    bt(pos + 1, add(mul(mul(m, 2), 5), b), t + '2');
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    freopen("modulo.inp", "r", stdin);
    freopen("modulo.out", "w", stdout);
    cin >> a >> b >> n >> k;
    for(int i = 0; i < N; i++)
        dp[i].clear();
    power[0] = 1;
    for(int i = 1; i <= 63; i++)
        power[i] = power[i - 1] * 2;
    mod = power[n];
    string temp = "";
    bt(1, 0, temp);
    cout << "-1\n";
}

