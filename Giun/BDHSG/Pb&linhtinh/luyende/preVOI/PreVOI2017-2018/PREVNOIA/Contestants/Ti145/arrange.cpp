// MR.J
#include<bits/stdc++.h>
#define maxn 100005
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
#define Task "arrange"
using namespace std;
int n, a[maxn], tt[maxn], ht[maxn], tr, b[maxn];
ll sum;

void calc1()  {
    ll ans = 0;
    int tb = sum/n;
    bool ok = 0;
    rep(i, 1, n) {
        ans += tr;
        if(a[i] > tb) tr += (a[i] - tb), a[i] = tb;
        else {
            int add = min(tr, tb - a[i]);
            a[i] += add;
            if(add > 0) ok = 1;
            tr -= add;
        }
    }
    tr = 0;
    if(!ok) ans = 0, swap(a, b);
    repd(i, n, 1) {
        ans += tr;
        if(a[i] > tb) tr += a[i] - tb, a[i] = tb;
        else {
            int add = min(tr, tb - a[i]);
            a[i] += add;
            tr -= add;
        }
    }
    cout << ans;
}

void calc2() {
    int tb = sum/n;
    bool ok = 0;
    ll ans1 = 0, ans2 = 0;
    int dem1 = 0;
    rep(i, 1, n) {
        ans1 += tr;
        if(a[i] > tb + 1) tr += (a[i] - tb - 1), a[i] = tb + 1, ++dem1;
        else {
            int add = min(tr, tb - a[i]);
            a[i] += add;
            if(add > 0) ok = 1;
            tr -= add;
            if(a[i] >= tb) ++dem1;
        }
    }
    tr = 0;
    ans2 = ans1;
    if(!ok || dem1 == n) ans2 = 0, swap(a, b);
    repd(i, n, 1) {
        ans2 += tr;
        if(a[i] > tb + 1) tr += a[i] - (tb + 1), a[i] = tb + 1;
        else {
            int add = min(tr, tb - a[i]);
            a[i] += add;
            tr -= add;
        }
    }
    if(dem1 == n) cout << min(ans1, ans2);
    else cout << ans2;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n;
    rep(i, 1, n) {
        cin >> a[i];
        b[i] = a[i];
        sum += a[i];
    }
    if(sum % n == 0) calc1();
    else calc2();
    return 0;
}
