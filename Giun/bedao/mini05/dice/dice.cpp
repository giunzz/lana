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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    File("dice");
    ll a[] = {3, 6, 4, 1}, n;
    cin >> n;
    cout << a[n % 4];
}