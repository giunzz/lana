#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

struct quang{
    ll next[27];
    bool leaf = 0;
    ll parent = -1;
    char parentchar;
    ll link = -1;
    ll go[27];

    quang(){
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }

    quang(ll v, char ch){
        this -> parent = v;
        this -> parentchar = ch;
        fill(begin(this -> next), end(this -> next), -1);
        fill(begin(this -> go), end(this -> go), -1);
    }

};

vec(quang) trie(1);

void addstr(string s){
    ll pos = 0;
    for(char c : s){
        ll i = c - 'a';
        if(trie[pos].next[i] == -1){
            trie[pos].next[i] = trie.size();
            trie.emplace_back(pos, c);
        }
        trie[pos].leaf = 0;
        pos = trie[pos].next[i];
    }
    // cerr << pos << '\n';
    trie[pos].leaf = 1;
}

ll go(ll v, char ch);

ll get_link(ll v){
    if(trie[v].link == -1){
        if(v == 0 || trie[v].parent == 0) trie[v].link = 0;
        else trie[v].link = go(get_link(trie[v].parent), trie[v].parentchar);
    }
    return trie[v].link;
} 

ll go(ll v, char ch){
    ll c = ch - 'a';
    if(trie[v].go[c] == -1){
        if(trie[v].next[c] != -1) trie[v].go[c] = trie[v].next[c];
        else trie[v].go[c] = (v == 0) ? 0 : go(get_link(v), ch);
    }
    return trie[v].go[c];
}

ll pi[100];
string t;

void kmp(){
    //string bat dau tu 1
    pi[1] = 0;
    ll k = 0;
    lp(i, 2, t.size() - 1){
        // ll k = pi[i - 1];
        while(k > 0 && t[k + 1] != t[i]) k = pi[k];
        if(t[k + 1] == t[k]) k = k + 1;
        pi[i] = k;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    ll n;
    cin >> n;
    // cerr << trie[0].next[0] << '\n';
    // addstr("ab");
    lp(i, 1, n){
        string s;
        cin >> s;
        addstr(s);
    }
    cerr << trie[0].next['b' - 'a'] << '\n';
    cerr << go(2, 'd');
}