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
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

struct quang{
    ll db = 0, nd, sl = 0; 
    bool operator<(const quang &a) const{
        return sl < a.sl || (sl == a.sl && nd < a.nd);
    }
};

cll maxn = 2e5 + 7;
ll n, k = 0, ans = 0;
bool dC[maxn] = {0}, d[maxn] = {0}, chose[maxn] = {0}; 
vec(pp(ll, ll)) g[maxn], preg[maxn];
quang gc[maxn];
priority_queue<pp(quang, ll)> pq;

void init(){
    ll v, c;
    lp(u, 1, n){
        cin >> v >> c;
        // cerr << u  << ' ' << v << ' ' << c << '\n';
        g[u].push_back({c, v});
        preg[v].push_back({c, u});
    }
}

#define pos second
#define cost first

#define fi first
#define se second

ll res;
vec(ll) vl;

pp(ll, ll) dfs(ll &u, ll const &r){
    ll tmp = 0, tmp1 = 0;
    for(pp(ll, ll) &v : preg[u]){
        if(dC[v.pos]) continue;
        d[v.pos] = 1;
        tmp += dfs(v.pos, r).fi; //so thanh pho do vao
        tmp1 += v.cost; //so tien hien co
    }
    if(tmp1 < g[u].back().cost && u != r)  tmp += g[u].back().cost - tmp1;
    return {tmp, tmp1};
}

void getCycle(ll const &r){
    vl.clear();
    ll u = r;
    while(!dC[u]){
        pp(ll, ll) v = g[u].back();
        vl.push_back(u);
        dC[u] = 1;
        u = v.pos;
    }
    lp(i, 0, vl.size() - 1){
        u = vl[i];
        if(preg[u].size() > 1){
            pp(ll, ll) tmp = dfs(u, u);
            gc[u].db = tmp.se;
            ans += tmp.fi;
        }
        if(gc[u].db >= g[u].back().cost) gc[u].db -= g[u].back().cost, g[u].back().cost = 0;
        ll prePos = vl[i? (i - 1) : (vl.size() - 1)];
        gc[u].nd = g[u].back().cost - gc[u].db - g[prePos].back().cost;
        if(i == vl.size() - 1){
            u = vl[0];
            prePos = vl[i];
            gc[u].nd = g[u].back().cost - gc[u].db - g[prePos].back().cost;
        }
        // cerr << u << ' ' << gc[u].db << ' ' << gc[u].nd << '\n';
    }
    // if(r == 2) for(ll u : vl){
    //     cerr << u << ' ' << gc[u].db << ' ' << gc[u].nd << '\n';
    // }
}

ll process(ll &u, ll const &r){     
    // cerr << u << '\n';
    pp(ll, ll) v = g[u].back();
    if(v.pos == r){
        if(g[u].back().cost + gc[g[u].back().pos].db >= g[r].back().cost){
            gc[u].sl = gc[r].sl + 1;
        }
        else{
            gc[u].sl = 1;
        }
        pq.push({gc[u], u});
        return 0;
    }
    if(g[u].back().cost + gc[v.pos].db < g[v.pos].back().cost){
        gc[u].sl = 1;
        pq.push({gc[u], u});
        return v.pos;
    }
    ll tmp = process(v.pos, r);
    gc[u].sl = gc[v.pos].sl + 1;
    pq.push({gc[u], u});
    return tmp;
}

void findCycle(ll &r){
    // while(pq.size()) pq.pop();
    ll u = r;
    res = 0;
    while(g[u].size()){
        pp(ll, ll) v = g[u].back();
        if(d[v.pos]){
            // cerr << v.pos << ' ';
            getCycle(v.pos);
            if(vl.size()){
                ll tmp = vl[0];
                while(tmp) tmp = process(tmp, vl[0]); 
                if(v.pos == 2) for(ll &i : vl){
                    cerr << i << ' ' << g[i].back().pos << ' ' << gc[i].db << ' ' << gc[i].nd << ' ' << gc[i].sl << '\n';
                }

                while(pq.size()){
                    pp(quang, ll) tmp1 = pq.top();
                    pq.pop();
                    if(chose[tmp1.se] || tmp1.fi.db != gc[tmp1.se].db) continue;
                    // cerr << tmp1.se << ' ' << tmp1.fi.sl << ' ' << tmp1.fi.nd << ' ' << tmp1.fi.db << '\n';
                    ll tu = tmp1.se;
                    if(gc[tu].db < g[tu].back().cost) ans += (g[tu].back().cost - gc[tu].db);
                    while(gc[tu].sl != 1){
                        chose[tu] = 1;
                        tu = g[tu].back().pos;
                    }
                    ll tv = g[tu].back().pos;
                    chose[tu] = 1;
                    gc[tv].db += g[tu].back().cost;
                    pq.push({gc[tv], tv});
                }
                // cerr << ans << ' ';
            }
            break;
        }
        d[v.pos] = 1;
        u = v.pos;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    init();
    lp(i, 1, n)
        if(!d[i]){
            findCycle(i); 
        }
    cout << ans;
}