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
ll n, a[maxn];
vec(ll) a[maxn];

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
    OF();
    ll cs;
    cin >> cs;
    while(cs--){
        cin >> n;
        lp(i, 1, n){
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n, greater<ll>());
        lp(i, 1, n){
            push(a[i]);
        }
    }
}