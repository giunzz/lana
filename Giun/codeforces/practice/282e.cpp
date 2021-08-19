#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "f"
using namespace std;

template <typename T> inline void Read(T &x){
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do
    {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
}

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

struct node{
    ll _next[2];
    node(){
        _next[0] = _next[1] = -1;
    } 
};

cll mxn = 1e5 + 7, mxnode = 4e6 + 3, mxbit = 40;
ll n, tot = 0, ans = 0;
node trie[mxnode];
bitset<mxbit> pre_xor[mxn];

void insert_bit(bitset<mxbit> &num){
    ll cur = 0;
    lpd(i, 39, 0)
        cur = trie[cur]._next[num[i]] == -1 ? (trie[cur]._next[num[i]] = ++tot) : trie[cur]._next[num[i]];
}

bitset<mxbit> get_bit(bitset<mxbit> num){
    ll cur = 0;
    bitset<mxbit> res;
    lpd(i, 39, 0){
        if(~trie[cur]._next[num[i]]){
            res[i] = num[i], cur = trie[cur]._next[num[i]];
        } else{
            res[i] = !num[i], cur = trie[cur]._next[!num[i]];
        }
    }
    return res;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n){
        ll tmp; cin >> tmp;
        pre_xor[i] = tmp;
        pre_xor[i] ^= pre_xor[i - 1];
    }
    insert_bit(pre_xor[0]);
    lp(i, 1, n){
        insert_bit(pre_xor[i]);
        ans = max(ans, (ll)(get_bit(~(pre_xor[n] ^ pre_xor[i])) ^ pre_xor[n] ^ pre_xor[i]).to_ullong());
        // cerr << i << ' ' << get_bit(~(pre_xor[n] ^ pre_xor[i])) << '\n';
    }
    cout << ans;
}