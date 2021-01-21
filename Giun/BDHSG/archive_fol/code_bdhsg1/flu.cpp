#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 1501;
ll k, m, n, d[maxn] = {0};
vec(ll) a, tg;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> k >> m >> n;
    // cerr << k << ' ' << n << ' ' << m;
    vec(ll) tmp;
    lp(i, 1, n){
        ll num;
        cin >> num;
        a.push_back(num);
        tg.push_back(num);
        // tmp.push_back(num);
        d[num] = 1;
    }
    vec(ll) b;
    lp(day, 2, 1500){
        // cerr << day;
        b.clear();
        // cerr << day;
        lp(i, 0, a.size() - 1){
            // if(tmp.empty()) break;
            lp(j, 0, tg.size() - 1){
                ll num = (a[i] * tg[j]) % m;
                if(d[num]) continue;
                else{
                    d[num] = day;
                    b.push_back(num);
                }
            }
        }
        // cerr << day;
        // lp(i, 0, a.size() - 1){
        //     tmp.push_back(a[i]);
        //     lp(j, i, a.size() - 1){
        //         ll num = (a[i] * a[j]) % m;
        //         if(d[num]) continue;
        //         else{
        //             d[num] = day;
        //             b.push_back(num);
        //         }
        //     }
        // }
        if(b.empty()) break;
        else{
            a.clear();
            a = b;
        }
    }
    set<ll> res;
    if(k == 1){
        lp(i, 0, m - 1) if(d[i] == 1) cout << i << ' ';
    }
    else{
        lp(i, 0, m - 1) lp(j, i, m - 1){
            if(d[i] && d[j] && d[i] < k && d[j] < k){
                res.insert((i * j) % m);
            }
        }
    }
    for(auto i : res) cout << i << ' ';
    // lp(i, 0, m - 1) cerr << i << ' ' << d[i] << '\n';
}