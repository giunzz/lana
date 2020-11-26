#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void file(const string file){
    freopen((file + ".inp").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
}

cll maxq = 3e5 + 7;
ll q, k, a[maxq] = {0};
vec(pp(ll, pp(ll, ll))) w;

// struct fenwick{
//     int n;
//     vec(ll) f;
//     fenwick(ll _n) : n(_n), f(n + 1, 0) {}
//     void set(int i, ll c){
//         for(; i >= 1; i -= (i & -i)) f[i] += c;
//     }
//     ll get(int j, int i){
//         ll res = 0;
//         while(i >= j){
//             if(i - (i & -i) >= j) res += f[i], i -= (i & (-i));
//             else res += a[i];
//         }
//         return res;
//     }
// };

struct segment{
    int n;
    vec(pp(ll, ll)) st;
    segment(ll _n) : n(_n), st(4*(n + 1), {0, 0}) {}
    void set(ll l, ll r, ll id, ll pos, ll val){
        // cerr << l << ' ' << r << ' ' << id << ' ' << pos << ' ' << val << '\n';
        st[id].first += val;
        if(l == r && l == pos) {st[id].second = 1; return;}
        ll mid = (l + r) >> 1;
        if(pos <= mid){
            set(l, mid, id << 1, pos, val);
        } else set(mid + 1, r, (id << 1) | 1, pos, val);
        st[id].second = st[id << 1].second + st[(id << 1) | 1].second;
    }
    ll erase(ll l, ll r, ll id){
        if(l == r){ll tmp = st[id].first; st[id] = {0, 0}; return tmp;}
        ll tmp;
        if(st[(id << 1) | 1].first){
            st[id].first -= (tmp = erase((l + r) >> 2 + 1, r, (id << 1) | 1));
            --st[id].second;
        } 
        else{
            st[id].first -= (tmp = erase(l, (l + r) >> 2, (id << 1)));
            --st[id].second;
        }
        return tmp;
    }
    ll get(ll l, ll r, ll id, ll t){
        if(l == 1 && r == n && st[id].second <= k) return st[id].first;
        if(st[id].second == t) return st[id].first;
        ll mid = (l + r) >> 1;
        if(st[(id << 1) | 1].second >= t){
            return get(mid + 1, r, (id << 1) | 1, t);
        }
        return get(l, mid, id << 1, t - st[(id << 1) | 1].second) +
            get(mid + 1, r, (id << 1) | 1, st[(id << 1) | 1].second);
    }
};

int main(){
    file("dnprevoib");
    ll cs;
    cin >> cs;
    ll sub = 3;
    cin >> q >> k;
    w.resize(q + 1);
    set<ll> cmp;
    lp(i, 1, q){
        string s;
        ll a, b;
        cin >> s;
        if(s == "eat") w[i].first = 0;
        else{
            cin >> a >> b;
            cmp.insert(a);
            w[i].first = 1, w[i].second = {a, b};
        }
    }
    vector<ll> tmp(cmp.begin(), cmp.end());
    cmp.clear();
    ll n = tmp.size() + 2;
    segment st(n);
    lp(i, 1, q){
        if(w[i].first){
            w[i].second.first = lower_bound(tmp.begin(), tmp.end(), w[i].second.first) - tmp.begin() + 1;
            st.set(1, n, 1, w[i].second.first, w[i].second.second);
            cerr << 1;
        }
        else{
            st.erase(1, n, 1);
        }
        cout << st.get(1, n, 1, k) << '\n';
    }
    // lp(i, 1, q){
    //     cerr << w[i].first << ' ' << w[i].second.first << ' ' << w[i].second.second << '\n';
    // }
}