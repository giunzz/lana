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

cll maxn = 1e3 + 7;
ll n, s, direct = 2, a[maxn][maxn], dl[] = {-1, 1, 1, -1};
pp(ll, ll) r[2], nt[] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
pp(bool, bool) d[] = {{0, 0}, {1, 1}, {0, 1}, {1, 0}};
vec(pp(ll, ll)) v[2]; 
map<pp(ll, ll), ll> rec;

#define x first 
#define y second

ll cnp(vec(pp(ll, ll)) &q, pp(ll, ll) val, bool const &br){
    ll ans = -1, l = 0, r = q.size() - 1;
    while(l <= r){
        ll mid  = (l + r) / 2;
        if(q[mid] > val){
            if(!br) ans = mid;
            r = mid - 1;
        }
        else{
            if(br) ans = mid;
            l = mid + 1;
        }
    }
    return ans;
}



int main(){
    file("robot");
    cin >> n >> r[0].x >> r[0].y >> s;
    ll ts = s;
    r[1] = {r[0].y, r[0].x};
    // ++s;
    rec[r[0]] = 1;
    // cerr << rec[pp(ll, ll)(2, 3)] << '\n';
    lp(j, 1, n) lp(i, 1, n){
        char c;
        cin >> c;
        if(c == '.') a[i][j] = 1;
        else a[i][j] = 0, v[0].emplace_back(i, j), v[1].emplace_back(j, i);
    }
    while(1){
        // cerr << direct;
        pp(ll, ll) tmp = {r[0].x + nt[direct].x, r[0].y + nt[direct].y};
        if(tmp.x < 1 || tmp.y < 1 || tmp.x > n || tmp.y > n || a[tmp.x][tmp.y]){
            break;
        }
        else direct = (direct + 3) % 4;
    }
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    map<pp(ll, ll), ll>::iterator it;
    bool ok = 1;
    ll nw = 1;
    while(s){
        // cerr << s << '\n';
        // cerr << r[0].x << ' ' << r[0].y  << ' ' << direct << '\n';
        bool t1 = d[direct].x, t2 = d[direct].y;
        ll vt = cnp(v[t1], r[t1], t2);
        // cerr << vt << ' ' << s << '\n';
        // cerr << v[t1][vt].x << ' ' << v[t1][vt].y << '\n';
        if(vt == -1 || v[t1][vt].x != r[t1].x || abs(v[t1][vt].y - r[t1].y) - 1 >= s){
            // cerr << r[0].x << ' ' << r[0].y << ' ' << s << ' ' << direct << '\n';
            if(direct == 0)
                r[0].y += s;
            else if(direct == 1)
                r[0].x -= s;
            else if(direct == 2)
                r[0].y -= s;
            else
                r[0].x += s;
            s = 0;
        }
        else{
            // cerr << 1 << '\n';
            pp(ll, ll) nr = v[t1][vt];
            nr.y += dl[direct];
            ll dis = abs(nr.y - r[t1].y);
            if(t1) swap(nr.x, nr.y);
            rec[nr] = rec[nr];
            // cerr << nr.first << ' ' << nr.second << '\n';
            it = rec.lower_bound(nr);
            // cerr << (it -> first).first << ' ' << (it -> first).second << ' ' << (it -> second) << ' ' << nw << ' ' << dis << ' ' << s << '\n';
            // cerr << rec[pp(ll, ll)(2, 2)] << '\n';
            // cerr << it -> second << '\n';
            // if((it -> first).first != nr.first || (it -> second) != nr.second){
            //     rec[nr] = 0;
            //     it = rec.lower_bound(nr);
            // }
            // cerr << 1 << '\n';
            if(it -> second && ok){
                // cerr << nr.first << ' ' << nr.second << ' ' << dis << '\n';
                ll cung = (nw - it -> second) + dis, rnd = s / cung * cung; 
                // cerr << rnd << '\n';
                s -= (rnd);
                // cerr << s << '\n';
                if(s < dis){
                    while(1){
                        // cerr << direct;
                        pp(ll, ll) tmp = {r[0].x + nt[direct].x, r[0].y + nt[direct].y};
                        if(tmp.x < 1 || tmp.y < 1 || tmp.x > n || tmp.y > n || a[tmp.x][tmp.y]){
                            break;
                        }
                        else direct = (direct + 3) % 4;
                    }
                    continue;
                }
                if(!s) break; 
                ok = 0;
            }
            s -= dis;
            it -> second = nw + dis;
            nw = nw + dis;
            r[0] = nr;
            // cerr << r[0].x << ' ' << r[0].second << '\n';
            r[1] = {r[0].y, r[0].x};
            while(1){
                // cerr << direct;
                pp(ll, ll) tmp = {r[0].x + nt[direct].x, r[0].y + nt[direct].y};
                if(tmp.x < 1 || tmp.y < 1 || tmp.x > n || tmp.y > n || a[tmp.x][tmp.y]){
                    break;
                }
                else direct = (direct + 3) % 4;
            }
            // cerr << 1;
        }
        // cerr << s << '\n';
    }
    cout << r[0].x << ' ' << r[0].y;
}