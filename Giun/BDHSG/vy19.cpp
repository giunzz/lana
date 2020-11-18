#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
// #define Fname "dady"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

ll n, m;

struct Node{
    ll key, pri;
    Node *l = nullptr, *r = nullptr;
};

typedef Node* pNode;

pNode get_newNode(ll &val, ll &pri){
    pNode res = new Node;
    res -> key = val, res -> pri = pri;
    return res;
}

pNode rotateR(pNode &p){
    pNode x = p -> l, t = x -> r;
    x -> r = p;
    p -> l = t;
    return x;
}

pNode rotateL(pNode &p){
    pNode x = p -> r, t = x -> l;
    x -> l = p;
    p -> r = t;
    return x;
}

pNode pushNode(pNode root, ll &val, ll &pri){
    pNode tmp = get_newNode(val, pri);
    if(root == nullptr) root = tmp;
    else{
        if(root -> key > val){
            root -> l =  pushNode(root -> l, val, pri);
            if(root -> pri > root -> l -> pri){
                root = rotateR(root);
            }
        }
        else if(root -> pri < val){
            root -> r = pushNode(root -> r, val, pri);
            if(root -> pri < root -> r -> pri){
                root = rotateL(root);
            }
        }
    }
    return root;
}

pNode getNode(pNode root, ll &val, ll &pri){
    // pNode res = root;
    if(root == nullptr) return root;
    if(root -> pri > pri) return root;
    if(root -> key == val){
        return root;
    }
    else if(root -> key < val){
        pNode tmp = getNode(root -> r, val, pri);
        if(tmp == nullptr) return root;
        else return tmp;
    }
    else{
        pNode tmp = getNode(root -> l, val, pri);
        if(tmp -> pri <= pri && tmp -> key >= val && tmp != nullptr) return tmp;
        else return root; 
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> m;
    char c;
    ll a, b;
    pNode root = nullptr;
    lp(i, 1, m){
        cin >> c >> a >> b;
        if(c == 'M') {
            //push
            root = pushNode(root, b, a);
        }
        else {
            pNode res = getNode(root, b, a);
            // if(res != nullptr) cerr << res -> key << ' ' << res -> pri << '\n';
            if(res != nullptr && res -> key >= b && res -> pri <= a) cout << res -> key << '\n';
            else cout << -1 << '\n';
        }
        if(root != nullptr) cerr << root -> key << ' ' << root -> pri << ' ' << i << '\n';
    }
}