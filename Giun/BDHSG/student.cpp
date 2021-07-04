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

// key = b, prior = a, heap giam

struct Node{
    ll key, prior, id;
    Node *left = nullptr, *right = nullptr, *par = nullptr;
    Node(ll _key, ll _prior, ll _id, Node *_par) : key(_key), prior(_prior), id(_id), par(_par){}
};

cll mxn = 2e5 + 7;
Node *p[mxn];

#define upd_par x -> par = par_node, node -> par = x

Node *rot_right(Node *node){
    Node *x = node -> left, *t = x -> right, *par_node = node -> par;
    x -> right = node;
    node -> left = t;
    upd_par;
    if(t != nullptr) t -> par = node;
    return x;
}

Node *rot_left(Node *node){
    Node *x = node -> right, *t = x -> left, *par_node = node -> par;
    x -> left = node;
    node -> right = t;
    upd_par;
    if(t != nullptr) t -> par = node;
    return x;
}

Node *insert(Node *root, ll key, ll prior, ll id, Node *par){
    if(!root) return p[id] = new Node(key, prior, id, par);
    if(key <= root -> key){
        root -> left = insert(root -> left, key, prior, id, root);
        if(root -> prior < root -> left -> prior)
            root = rot_right(root);
    } else{
        root -> right = insert(root -> right, key, prior, id, root);
        if(root -> prior <= root -> right -> prior)
            root = rot_left(root);
    }
    return root;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    char c;
    ll a, b, tot = 0;
    Node *root = nullptr, *tmp = nullptr;
    EACHCASE{
        cin >> c;
        if(c == 'D'){
            cin >> a >> b;
            root = insert(root, b, a, ++tot, nullptr);
        } else{
            cin >> a;
            tmp = p[a] -> par;
            while(tmp != nullptr && tmp -> key < p[a] -> key) tmp = tmp -> par;
            if(tmp == nullptr) cout << "NE\n";
            else cout << tmp -> id << '\n';
        }
    }
}