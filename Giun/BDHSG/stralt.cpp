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

string s;
stack<ll> st;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> s;
    ll tmp = 0;
    for(ll i = 0; i < s.size(); i++){
        if(s[i]>= '0' && s[i] <= '9'){
            tmp = tmp * 10 + (s[i] - '0');
        }
        else {
            if(tmp != 0) st.push(tmp), tmp = 0;
            if(s[i] == '(') st.push(i);
            else if(s[i] == '[') {
                if(s[i + 1] == '*') st.push(-i);
                else st.push(i);
            } else if(s[i] == ')'){
                ll pos = st.top();
                st.pop();
                ll cnt = st.top();
                st.pop();
                s.erase(s.begin() + i);
                string tmp = s.substr(pos + 1, i - pos - 1);
                string ans;
                while(--cnt) ans += tmp;
                s.insert(i, tmp);
                s.erase(s.begin() + pos - 1, s.begin() + pos);
                i -= 2;
            } else if(s[i] == ']'){
                ll pos = st.top();
                st.pop();
                bool ms = 0;
                if(pos < 0) ms = 1, pos = -pos;
                string tmp;
                if(ms){
                    tmp = s.substr(pos + 2, i - pos - 2);
                    reverse(tmp.begin(), tmp.end());
                    s.erase(s.begin() + i);
                    s.insert(i, tmp);
                    
                }
                else{
                    tmp = s.substr(pos + 1, i - )
                }
            }
        }
    }
}