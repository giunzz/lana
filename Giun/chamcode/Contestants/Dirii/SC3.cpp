#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define er(variable) cerr << variable << " "
#define erl(variable) cerr << variable << "\n"
#define loop(variable, valuegan, valuebehonbang) for(int variable = valuegan; variable <= valuebehonbang; variable++)
#define loopd(variable, valuegan, valuelonhonbang) for(long long variable = valuegan; variable >= valuelonhonbang; variable--)
#define loopdk(variable, valuegan, conditions, thaydoi) for(long long variable = valuegan; conditions; thaydoi) 
#define pp(type, type1) pair<type, type1>
#define mp make_pair
#define vec(type) vector<type>
#define vecite(type) vector<type>::iterator
using namespace std;
const string tenfile = "SC3";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cii maxn = 1e5 + 7;
ii t, n, m, l , r, to[maxn] = {0}, dem = 0, s, ch[maxn] = {0}, ans = 0;
stack<ii> st;
vec(ii) d;

int main(){
    opt;
    fi;
    cin >> t;
    while(t--){
        cin >> n >> m;
        d.resize(n + 2);
        loop(i, 1, n){
            cin >> l >> r;
            st.push(r); st.push(l);
        }
        while(!(st.empty()) && dem < m){
            l = st.top(); st.pop();
            r = st.top(); st.pop();
            //update l r
            while(l <= r){
                if(!to[l]) {
                    to[l] = n, ++dem, d[n] = l++;
                }
                else
                    l = d[to[l]] + 1;
            }
            --n;
        }
        loop(i, 1, m)   
            if(!ch[to[i]] && to[i]) ch[to[i]] = 1, ++ans;
        cout << ans << "\n";
        memset(ch, 0, sizeof(ch));
        memset(to, 0, sizeof(to));
        d.clear();
        ans = 0, dem = 0;
        while(!st.empty()) st.pop();
    }
}