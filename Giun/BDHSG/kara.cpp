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

struct quang{
    ll next['z' - 'a' + 1];
    bool leaf = 0;

    quang(){
        fill(begin(next), end(next), -1);
    }
};

ll n, m;
vec(quang) trie[2];

void addstring(ll t, string s){
    ll v = 0;
    for(char i : s){
        ll c = i - 'a';
        if(trie[t][v].next[c] == -1){
            trie[t][v].next[c] = trie[t].size();
            trie[t].emplace_back();
        }
        trie[t][v].leaf = 0;
        v = trie[t][v].next[c];
    }
    trie[t][v].leaf = 1;
}

cll maxn = 2e5 + 7;
ll dp[maxn]['z' - 'a' + 1] = {{0}};

ll dfs(ll p, ll t, ll pre){
    if(p == -1 || trie[t][p].leaf) return !t;
    bool ok = !t;
    lp(i, 0, 'z' - 'a'){
        if(trie[t][p].next[i] == -1) continue;
        ll tmp = dfs(trie[!t][pre].next[i], !t, trie[t][p].next[i]);
        if(tmp == t) ok = t;
    }
    return ok;
}

string name[] = {"Alice", "Bob"};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    lp(i, 0, 1) trie[i].emplace_back();
    cin >> n;
    lp(i, 1, n){
        string s;
        cin >> s;
        addstring(0, s);
    }
    cin >> m;
    lp(i, 1, m){
        string s;
        cin >> s;
        addstring(1, s);
    }
    ll tmp;
    bool ans = 1;
    lp(i, 0, 'z' - 'a'){
        if(trie[0][0].next[i] == -1) continue;
        tmp = dfs(trie[1][0].next[i], 1, trie[0][0].next[i]);
        if(!tmp) ans = 0;
    }
    cout << name[ans];
}
