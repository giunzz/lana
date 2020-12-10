#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void file(const string file){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen((file + ".inp").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
}

ll n;
string s;
map<string, ll> d;
vec(ll) q;
vec(pp(string, ll)) a;

void prc(){
    n = 0; d.clear(); a.clear();
    lp(i, 0, s.size() - 1){
        if(s[i] == '(') a.push_back({"(", 0});
        else if(s[i] == ')'){
            ll num = 0;
            while(s[i + 1] >= '0' && s[i + 1] <= '9') ++i, num = num * 10 + s[i] - '0';
            a.push_back({")", num});
        }
        else{
            string tmp;
            tmp.push_back(s[i]);
            if(s[i + 1] >= 'a' && s[i + 1] <= 'z') ++i, tmp.push_back(s[i]);
            if(!d[tmp]) d[tmp] = ++n;
            ll num = 0;
            while(s[i + 1] >= '0' && s[i + 1] <= '9') ++i, num = num * 10 + s[i] - '0';
            num = max(num, 1LL);
            a.push_back({tmp, num});
        }
    }
    stack<ll> st;
    lp(i, 0, a.size() - 1){
        if(a[i].first == "(") st.push(i);
        else if(a[i].first == ")"){
            ll tmp = st.top();
            st.pop();
            a[tmp].first = a[i].first = "*";
            lp(j, tmp + 1, i - 1) a[j].second *= a[i].second;
        }
    }
    q.clear();
    q.assign(n + 1, 0);
    string s1;
    ll h;
    lp(i, 1, n - 1){
        cin >> s1 >> h;
        s1.pop_back();
        q[d[s1]] = h;
    }
    ll res = 0, sum = 0;
    lp(i, 0, a.size() - 1){
        if(a[i].first == "*") continue;
        if(!q[d[a[i].first]]) sum += a[i].second;
        else res += a[i].second * q[d[a[i].first]];
    }
    res /= sum;
    cout << -res << '\n';
}

int main(){
    file("spc4");
    ll cs;
    cin >> cs;
    while(cs--){
        cin >> s;
        prc();
    }
}