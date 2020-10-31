#include <bits/stdc++.h>
#define int long long
#define ii pair <int, int>
#define X first
#define Y second

using namespace std;

int N, M ,A,B,C;
main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ICECREAM.INP", "r", stdin);
    freopen("ICECREAM.OUT", "w", stdout);
    	cin >> N >> M;
    	cin >> A >> B >> C;
    	cout << max(A  + B + C, A * B * C);
}
