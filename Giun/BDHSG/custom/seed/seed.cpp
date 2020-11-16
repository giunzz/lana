#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "seed"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 1e6;
ll n, bs = 0, trie[maxn][2], j[maxn][2], Nnode = 1;
bool lf[maxn] = {0};
string s;

void push(ll num){
    // cerr << num << ' ';
    ll cur = 0;
    lpd(i, s.size() - 1, 0){
        if(trie[cur][(num >> i) & 1] == -1){
            // cerr << ((num >> i) & 1);
            // lf[cur] = 0;
            trie[cur][(num >> i) & 1] = Nnode;
            Nnode++;
        }
        cur = trie[cur][(num >> i) & 1];
        // cerr << ((num >> i) & 1);
    }
    // cerr << num << ' ' << cur << '\n';
    // cerr << '\n';
    lf[cur] = 1;
}

void gene(ll pos, ll tt){
    // cerr << pos << ' ' << tt << '\n';
    if(pos == s.size()){
        // cerr << tt << ' ';
        push(tt);
        // cerr << 1;
        return;
    }
    ll ntt;
    if(s[pos] == '*'){
        lp(i, 0, 1){
            ntt = tt | ((i * 1LL) << (s.size() - 1 - pos));
            // cerr << (tt | (1 << pos)) << '\n';
            gene(pos + 1, ntt);
            // cerr << tt << ' ';
        }
    }
    else gene(pos + 1, tt);
}

ll find_j(ll stt, ll v, ll cnt){
    ll sttp = (stt << 1LL) | v, ncnt = cnt + 1;
    // cerr << stt << ' ' << sttp << ' ' << cnt << '\n';
    while(ncnt){
        // cerr << 1;
        sttp = sttp & ~(1LL << (ncnt-- - 1));
        bool ok = 1;
        ll c = 0;
        lpd(j, ncnt - 1, 0){
            if(trie[c][(sttp >> j) & 1LL] > -1){
                c = trie[c][(sttp >> j) & 1LL];
            }
            else{
                ok = 0;
                break;
            }
        // if(stt == 3) cerr << sttp << ' ' << ncnt << ' ' << c << ' ' << ok << '\n';
        }
        if(ok) return c;
    }
    return 0;
}

void dfs(ll i, ll stt, ll cnt){
    lp(v, 0, 1){
        if(trie[i][v] > -1){
            j[i][v] = trie[i][v];
            dfs(trie[i][v], (stt << 1) | v, cnt + 1);
        }
        else
            j[i][v] = find_j(stt, v, cnt);
    }
}

vec(vec(ll)) f;

ll sol(ll pos, ll node){
    if(pos > n) return 1;
    if(f[pos][node] > -1) return f[pos][node];
    ll cnt = 0;
    lp(v, 0, 1){
        if(!lf[j[node][v]]){
            cnt += sol(pos + 1, j[node][v]);
        }
    }
    f[pos][node] = cnt;
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // OF();
    cin >> n >> s;
    // cerr << s << '\n';
    lp(i, 0, s.size() - 1){
        if(s[i] == '1'){
            bs = bs | (1LL << (s.size() - 1 - i));
            // cerr << i << ' ' << bs << '\n';
        }
    }
    // cerr << bs << '\n';
    memset(trie, -1, sizeof(trie));
    memset(j, -1, sizeof(j));
    gene(0, bs);
    // cerr << lf[5];
    // cerr << Nnode;
    dfs(0, 0, 0);
    f.resize(n + 3);
    for(auto &v : f) v.resize(Nnode + 3);
    lp(i, 0, n) lp(j, 0, Nnode) f[i][j] = -1;
    // cerr << j[4][0];
    // lp(i, 0, 5){
    //     lp(z, 0, 1){
    //         cerr << i << ' ' << z << ' ' << j[i][z] << '\n'; 
    //     }
    // }
    cout << (1LL << n) - sol(1, 0);
}