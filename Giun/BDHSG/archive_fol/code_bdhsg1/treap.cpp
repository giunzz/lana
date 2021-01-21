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

struct Node{
    int y;
    int sz;
    int val; 
    Node *l, *r;
};

typedef Node* pNode;

Node *new_node(ll val){
    pNode result = new Node;
    result -> y = rand();
    result -> sz = 1;
    result -> val = val;
    result -> l = result -> r = nullptr;
    return result;
}

ll get_sz(pNode t){
    if(t == nullptr) return 0;
    return t -> sz;
}

void upd_sz(pNode t){
    if(t == nullptr) return;
    t -> sz = 1 + get_sz(t -> l) + get_sz(t -> r);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    
}