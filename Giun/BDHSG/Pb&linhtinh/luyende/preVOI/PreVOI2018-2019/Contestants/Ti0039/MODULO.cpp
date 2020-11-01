//TNA
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define nmax 70
#define oo 1000000007
#define pii pair<int, int>
#define ll long long
#define Task "MODULO"

using namespace std;
int a[10], n;
ll p, k;

ll Pow(int n){
    if(n == 0) return 1;
    if(n == 1) return 2;
    ll res = Pow(n >> 1);
    res *= res;
    if(n & 1) res *= 2;
    return res;
}

void DFS(ll u, int d){
    if(d == n){
        if(u % p == k){
            cout << u;
            exit(0);
        }
        return;
    }
    for(int i = 1;i < 3; i++)
        DFS(u * 10 + a[i], d + 1);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> a[1] >> a[2] >> n >> k;
    p = Pow(n);
    DFS(0, 0);
    cout << -1;
    return 0;
}
