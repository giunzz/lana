#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
using namespace std;

void file(const string file){
    freopen((file + ".inp").c_str(), "r", stdin);
    freopen((file + ".ans").c_str(), "w", stdout);
}

cll maxn = 1e3 + 7;
ll n, m, a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    file("hough");
    cin >> n >> m;
    lp(i, 1, n) cin >> a[i];
    ll num, cnt;
    lp(i, 1, m){
        cnt = 0;
        cin >> num;
        lp(j, 1, n) if(a[j] < num) ++cnt;
        cout << cnt << endl;
    }
}