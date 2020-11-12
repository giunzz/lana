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

cll maxn = 1e4 + 7;
string s;
ll k = 0;
pp(ll, string) a[maxn];

void process(){
    ll tmp;
    lp(i, 0, s.size() - 1){
        if(s[i] == '(' || s[i] == ')' || s[i] == '[' || s[i] == ']' || s[i] == '*') a[k++] = make_pair(0LL, s[i]);
        else if(s[i] >= '0' && s[i] <= '9'){
            tmp = 0;
            while(!(s[i] < '0' || s[i] > '9')) tmp = (tmp * 10) + s[i++] - '0';
            a[k++] = make_pair(tmp, "");
            --i;
        }
        else{
            string tp;
            while(!(s[i] < 'a' || s[i] > 'z') && i < s.size()) tp.push_back(s[i++]);
            a[k++] = make_pair(0LL, tp);
            --i;
        }
    }
    --k;
}

stack<ll> st;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // OF();
    cin >> s;
    ll cnt = 0;
    process();
    // cerr << k;
    string ans;
    lp(i, 0, k){
        if(a[i].second == "(" || a[i].second == "[") st.push(i);
        else if(a[i].second == ")"){
            // ++cnt;
            ll pos = st.top();
            st.pop();
            string tmp1, tmp;
            lp(j, pos + 1, i - 1) tmp1 += a[j].second;
            if(tmp1.size()) ++cnt;
            while(--a[pos - 1].first) tmp += tmp1;
            a[pos].second = "";
            a[i].second = tmp;
        } else if(a[i].second == "]"){
            // ++cnt;
            ll pos = st.top();
            st.pop();
            string tmp1, tmp;
            if(a[pos + 1].second == "*"){
                lp(j, pos + 2, i - 1) tmp1 += a[j].second;
                if(tmp1.size()) ++cnt;
                reverse(tmp1.begin(), tmp1.end());
                a[i].second = tmp1;
                a[pos].second = a[pos + 1].second = "";
            }
            else{
                lp(j, pos + 1, i - 2) tmp1 += a[j].second;
                tmp1.pop_back();
                reverse(tmp1.begin(), tmp1.end());
                if(tmp1.size()) ++cnt;
                a[i].second = tmp1;
                a[pos].second = a[i - 1].second = "";
            }
        }
    }
    cout << cnt << '\n';
    lp(i, 0, k) cout << a[i].second;
}