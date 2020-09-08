#include <bits/stdc++.h>
#define ll long long 
#define cll const long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define fname "f"
using namespace std;

cll maxn = 1e5 + 7;
ll a[maxn];
priority_queue<pp(ll, ll)> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen(fname".inp", "r", stdin);
    // freopen(fname".out", "w", stdout);
    ll query, n, ans;
    cin >> query;
    while(query--){
        ans = 0;
        while(q.size()) q.pop();
        cin >> n;
        lp(i, 1, n)
            cin >> a[i];
        lp(i, 1, n)
            if(a[i] > 0) q.push({a[i], i});
            else
                while(!q.empty() && q.top().first && a[i]){
                    ll tmp = q.top().first, vtmp = q.top().second;
                    q.pop();
                    ll Min = min(-a[i], tmp); 
                    a[i] += Min, tmp -= Min;
                    a[vtmp] = tmp;
                    q.push({tmp, vtmp});
                }
        lp(i, 1, n)
            if(a[i] > 0) break;
            else ans += -a[i];
        cout << ans << endl;
    }
}