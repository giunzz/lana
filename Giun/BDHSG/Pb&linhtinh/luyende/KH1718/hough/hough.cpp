#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
using namespace std;

void file(const string file){
    freopen((file + ".inp").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
}

ll n, m;
vec(ll) a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    file("hough");
    cin >> n >> m;
    ll num;
    lp(i, 1, n) {cin >> num; a.push_back(num);}
    sort(a.begin(), a.end());
    lp(i, 1, m){
        cin >> num;
        ll vt = lower_bound(a.begin(), a.end(), num) - a.begin();
        while(vt >= 0 && (vt == a.size() || a[vt] >= num)) --vt;
        cout << (vt + 1) << endl;
    }
}