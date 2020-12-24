#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void OF(const string f){
    freopen((f + ".inp").c_str(), "r", stdin);
    freopen((f + ".out").c_str(), "w", stdout);
}

#define point pp(ll, ll)
#define x first
#define y second

ll n[2], m[2];
vec(point) p[2];
vec(pp(ll, ll)) g[2];

ll area(point &a, point &b, point &c){
    point ab = {b.x - a.x, b.y - a.y}, bc = {c.x - b.x, c.y - b.y};
    return ab.x * bc.y - ab.y * bc.x;
}

ll ccw(point a, point b, point c){
    ll tmp = area(a, b, c);
    if(tmp > 0) return 1;
    else if(tmp < 0) return -1;
    else return 0;
}

bool check(point p0, point p1, pp(ll, ll) s, bool pos){
    point t0 = p[pos][s.first], t1 = p[pos][s.second];
    // if(p0 == p[0][4] && p1 == p[1][1] && s == make_pair(2LL, 4LL)) cerr << '\t' << t1.x << ' ' << t1.y << ' ' << pos << ' ' << (t0 == p0 || t1 == p0) << '\n'; 
    if(pos) {if(t0 == p1 || t1 == p1) return 1;}
    else if(t0 == p0 || t1 == p0) return 1;
    ll tmp;
    // cerr << p0.x << ' ' << p0.y << ' ' << p1.x << ' ' << p1.y << ' ' << s.first << ' ' << s.second << ' ' << pos << '\n';
    return((tmp = ccw(p0, t0, t1)) == ccw(p1, t0, t1) && tmp) || ((tmp = ccw(t0, p0, p1)) == ccw(t1, p0, p1) && tmp);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF("highway");
    ll cs;
    cin >> cs;
    while(cs--){
        lp(i,0, 1) p[i].clear(), g[i].clear();
        lp(i, 0, 1){
            cin >> n[i] >> m[i];
            lp(j, 1, n[i]){
                ll u, v;
                cin >> u >> v;
                p[i].push_back({u, v});
            }
            lp(j, 1, m[i]){
                ll u, v;
                cin >> u >> v;
                g[i].push_back({u - 1, v - 1});
            }
        }
        // lp(i, 0, 1) cerr << p[i].size() << ' ' << g[i].size() << '\n';
        // cerr << p[0][g[0][2].x].x << ' ' << p[0][g[0][2].x].y <<  ' ' << ccw(p[0][4], p[0][2], p[0][4])<<'\n';
        // cerr << p[0][4].x << ' '<< p[0][4].y << '\n';
        bool test = 0;
        lp(i, 0, n[0] - 1) lp(j, 0, n[1] - 1){
            if(test) break;
            bool ok = 0;
            lp(q, 0, 1) lp(k, 0, m[q] - 1){
                // cerr << 1;
                // cerr << i << ' ' << j << ' ' << k << ' ' << q << '\n';
                // if(i == 4 && j == 1 && !check(p[0][i], p[1][j], g[q][k], q)) cerr << q << ' ' << g[q][k].x << ' ' << g[q][k].y << '\n';
                if(!check(p[0][i], p[1][j], g[q][k], q)) ok = 1;
            }
            if(!ok) {
                cout << (i + 1) << ' ' << (j + 1) << '\n';
                test = 1;
            }
        }
        if(!test) cout << 0 << '\n';
    }
}