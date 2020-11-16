#include <bits/stdc++.h>
#define M 1000005
#define N 30 

using namespace std;

int trie[M][N];
vector<int> ds_E[M], wf;
stack<int> st;
int n;
int Nnode;
vector<pair<int, int>> ans;

void reup(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(trie, -1, sizeof(trie));
}

void addstring(string s, int cur){
    int node = 0;
    for(int i = 0; i < s.length(); ++i){
        if(trie[node][s[i] - 'a'] == -1)
            trie[node][s[i] - 'a'] = ++Nnode;
        node = trie[node][s[i] - 'a'];
    }
    ds_E[node].push_back(cur);
    wf.push_back(node);
}

void enter(){
    reup();
    wf.push_back(0);
    cin >> n;
    for(int i = 1; i <= 2 * n; ++i){
        string s;
        cin >> s;
        addstring(s, i);
    }
}

void dfs(int node){
    for(int v : ds_E[node])
        st.push(v);

    for(int c = 0; c < 26; ++c)
        if(trie[node][c] > -1)
            dfs(trie[node][c]);
    
    while(st.size() && wf[st.top()]==node){
        int ta = st.top();
        st.pop();
        int tb = st.top();
        st.pop();
        ans.push_back({ta, tb});
    }
}

void solve(){
    dfs(0);
    for(pair<int, int> v : ans)
        cout << v.first << " " << v.second << "\n";
}

int main(){
    //freopen("file.inp", "r", stdin);
    //freopen("file.out", "w", stdout);
    enter();
    solve();
    return 0;
}