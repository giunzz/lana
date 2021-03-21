#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for (ll a  =b; a <= c; a++)
#define lpd(a, b, c) for (ll a  =b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;
#define ff "a"

void File(){
    freopen(ff".inp", "r", stdin);
    freopen(ff".ans", "w", stdout);
}

cll maxn = 1e5+7;
ll n, k, a[maxn], ans = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    File();
    cin >> n >> k;
    lp(i, 1, n) cin >> a[i];
    ll tmp, tmp1, tmp2;
    a[0] = INT_MAX;
    priority_queue<pp(ll, ll), vec(pp(ll, ll)), greater<pp(ll, ll)>> q;
    while(1){
        // tmp = INT_MAX;
        // lp(i, 1, n) tmp = min(tmp, a[i]);
        // lp(i, 1, n){
        //     a[i] -= tmp;
        //     q.push({a[i], i});
        // }
        // while(q.size() && q.top().first != a[q.top().second]) q.pop();
        // if(q.empty()) break;
        // a[q.top().second] += tmp * k;
        // ans += tmp;
        // q.push({a[q.top().second], q.top().second});
        sort(a + 1, a + 1 + n);
        if(a[1] <= 0) {--ans; break;}
        tmp = 1; --a[1];
        lp(i, 2, n) if(a[1] == --a[i]) ++tmp;
        lp(i, 1, n) cerr << a[i] << ' ';
        cerr << endl;
        if(tmp){
            tmp1 = k / tmp;
            if(!tmp1) tmp1 = 1, tmp = k;
            cerr << tmp << ' ' << tmp1 << endl;
            lp(i, 1, tmp - 1) a[i] += tmp1;
            a[tmp] += k - (k / tmp * (tmp - 1));
        }
        else a[1] += k; 
        ++ans;
        lp(i, 1, n) cerr << a[i] << ' ';
        cerr << endl << endl;
    }
    cout << ans;
}