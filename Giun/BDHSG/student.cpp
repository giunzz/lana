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

struct event{
    bool type = 0;
    ll pos;
};

struct add{
    ll a, b, id;
};

cll mxn = 2e5 + 3;
ll ori[mxn], m, tot = 0;
event ev[mxn];
add data[mxn];

struct segment{
    ll ST[mxn * 4] = {0}; // max in range
    void update(ll id, ll l, ll r, ll pos, ll val){
        if(pos < l || pos > r) return;
        if(l == r) {ST[id] = val; return;}
        ll mid = (l + r) >> 1;
        update(id << 1, l, mid, pos, val); 
        update(id << 1 | 1, mid + 1, r, pos, val);
        ST[id] = max(ST[id << 1], ST[id << 1 | 1]);
    }   
    ll get(ll id, ll l, ll r, ll val, ll pos){
        if(ST[id] < val || (l == r && pos > 0)) return 1e18;
        if(l == r) return l;
        ll mid = (l + r) >> 1;
        if(mid - l + 1 <= pos) return get(id << 1 | 1, mid + 1, r, val, pos - (mid - l + 1));
        if(pos <= 0 && ST[id << 1] > val) return get(id << 1, l, mid, val, pos);
        if(ST[id << 1] >= val)
            return min(get(id << 1, l, mid, val, pos), get(id << 1 | 1, mid + 1, r, val, pos - (mid - l + 1)));
        return get(id << 1 | 1, mid + 1, r, val, pos - (mid - l + 1));
    }
    void update(ll pos, ll val){update(1, 1, tot, pos, val);}
    ll get(ll val, ll pos){return get(1, 1, tot, val, pos);}
};

bool cpr_b(add &a, add &b){
    return (a.b == b.b) ? a.a < b.a : a.b < b.b;
}

bool cpr_id(add &a, add &b){
    return a.id < b.id;
}

void init(){
    char c;
    lp(i, 1, m){
        cin >> c;
        if(c == 'D'){
            cin >> data[++tot].a >> data[tot].b;
            data[tot].id = tot;
            ev[i].type = 1;
            ev[i].pos = tot;
        } else{
            cin >> ev[i].pos;
        }
    }
    sort(data + 1, data + tot + 1, cpr_b);
    lp(i, 1, tot) data[i].b = i, ori[i] = data[i].id;
    sort(data + 1, data + 1 + tot, cpr_id);
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> m;
    init();
    segment st;
    lp(i, 1, m){
        if(ev[i].type){
            st.update(data[ev[i].pos].b, data[ev[i].pos].a);
        } else{
            ll res = st.get(data[ev[i].pos].a, data[ev[i].pos].b);
            if(res != 1e18) cout << ori[res] << '\n';
            else cout << "NE\n";
        }
    }
}

// #include <bits/stdc++.h>
// #define ll long long
// #define cll const ll
// #define lp(a, b, c) for(ll a = b; a <= c; ++a)
// #define lpd(a, b, c) for(ll a = b; a >= c; --a)
// #define vec(a) vector<a>
// #define pp(a, b) pair<a, b>
// #define EACHCASE lpd(cs, read(), 1)
// #define Fname "f"
// using namespace std;

// template <typename T> inline void Read(T &x){
//     x = 0; char c;
//     while(!isdigit(c = getchar()));
//     do
//     {
//         x = x * 10 + c - '0';
//     } while (isdigit(c = getchar()));
// }

// ll read(){
//     ll tmp;
//     cin >> tmp;
//     return tmp;
// }

// void giuncute(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
// }

// void OF(){
//     freopen(Fname".inp", "r", stdin);
//     freopen(Fname".out", "w", stdout);
// }

// // key = b, prior = a, heap giam

// struct Node{
//     ll key, prior, id;
//     Node *left = nullptr, *right = nullptr, *par = nullptr;
//     Node(ll _key, ll _prior, ll _id, Node *_par) : key(_key), prior(_prior), id(_id), par(_par){}
// };

// cll mxn = 2e5 + 7;
// Node *p[mxn];

// #define upd_par x -> par = par_node, node -> par = x

// Node *rot_right(Node *node){
//     Node *x = node -> left, *t = x -> right, *par_node = node -> par;
//     x -> right = node;
//     node -> left = t;
//     upd_par;
//     if(t != nullptr) t -> par = node;
//     return x;
// }

// Node *rot_left(Node *node){
//     Node *x = node -> right, *t = x -> left, *par_node = node -> par;
//     x -> left = node;
//     node -> right = t;
//     upd_par;
//     if(t != nullptr) t -> par = node;
//     return x;
// }

// Node *insert(Node *root, ll key, ll prior, ll id, Node *par){
//     if(!root) return p[id] = new Node(key, prior, id, par);
//     if(key <= root -> key){
//         root -> left = insert(root -> left, key, prior, id, root);
//         if(root -> prior < root -> left -> prior)
//             root = rot_right(root);
//     } else{
//         root -> right = insert(root -> right, key, prior, id, root);
//         if(root -> prior <= root -> right -> prior)
//             root = rot_left(root);
//     }
//     return root;
// }

// int main(){
//     giuncute();
//     #ifndef ONLINE_JUDGE
//     OF();
//     #endif
//     char c;
//     ll a, b, tot = 0;
//     Node *root = nullptr, *tmp = nullptr;
//     EACHCASE{
//         cin >> c;
//         if(c == 'D'){
//             cin >> a >> b;
//             root = insert(root, b, a, ++tot, nullptr);
//         } else{
//             cin >> a;
//             tmp = p[a] -> par;
//             while(tmp != nullptr && tmp -> key < p[a] -> key) tmp = tmp -> par;
//             if(tmp == nullptr) cout << "NE\n";
//             else cout << tmp -> id << '\n';
//         }
//     }
// }