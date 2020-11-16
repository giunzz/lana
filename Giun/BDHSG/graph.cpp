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

cll maxn = 1e5 + 7;
ll n, d[maxn], pre[maxn];

// struct Node{
//     vector<ll> next;
//     ll cnt;
//     Node(ll q){
//         next.resize(q, -1);
//         cnt = q;
//     }
// };

// vector<Node> trie;

// void push(ll num){
//     Node tmp(num);
//     ll cur = 0;
//     if(trie.empty()){
//         trie.push_back(num);
//     }
//     else{
//         for(ll nt : trie[cur].next){

//         }
//     }
// }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // OF();
    ll cs;
    pre[0] = 0;
    cin >> cs;
    while(cs--){
        cin >> n;
        lp(i, 1, n){
            cin >> d[i];
        }
        sort(d + 1, d + 1 + n, greater<ll>());
        // lp(i, 1, n) cerr << d[i] << ' ';
        lp(i, 1, n) pre[i] = pre[i - 1] + d[i];
        // cerr << pre[n];
        if(pre[n] & 1){
            cout << "NO\n";
            continue;
        } 
        // lp(i, 1, n) cerr << pre[i] << ' ';
        ll j = n, i =1;
        bool ok = 1;
        while(i <= n){
            while(i < j && d[j] > i){
                --j;
            }
            ll sum1 = pre[i], sum2 = i * (i - 1) + (pre[n] - pre[j]) + (j - i) * i;
            if(sum1 > sum2){
                cout << "NO\n";
                ok = 0;
                break;
            }
            if(j == i) j = i + 1;
            ++i;
        }
        if(ok) cout << "YES\n";
    }
}