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

cll maxn = 1e5 + 7, maxNode = 1e7 + 7, maPos = 30;
ll n, a[maxn], trie[maxNode][2], Nnode = 0;

void push(ll num){
    ll cur = 0;
    lpd(i, maPos, 0){
        int tmp = (num >> i) & 1;
        if(trie[cur][tmp] == -1){
            trie[cur][tmp] = ++Nnode;
        }
        cur = trie[cur][tmp];
    }
    // lf[cur] = 1;
}

ll gt(ll num){
    ll cur = 0, res = 0;
    lpd(i, maPos, 0){
        ll tmp = (num >> i) & 1;
        if(trie[cur][!tmp] != -1){
            res = (res << 1) | (!tmp);
            cur = trie[cur][!tmp];
        }
        else if(trie[cur][tmp] != -1){
            res = (res << 1) | tmp;
            cur = trie[cur][tmp];
        }
    }
    return num ^ res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // OF();
    ll cs;
    a[0] = 0;
    cin >> cs;
    while(cs--){
        Nnode = 0;
        memset(trie, -1, sizeof(trie));
        cin >> n >> a[1];
        push(0LL);
        push(a[1]);
        ll ma = 0;
        lp(i, 2, n){
            ll num;
            cin >> num;
            a[i] = num ^ a[i - 1];
            ma = max(ma, gt(a[i]));
            push(a[i]);
        }
        cout << ma << '\n';
    }
}