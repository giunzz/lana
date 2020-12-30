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

#define NO "NO\n"
#define YES "YES\n"

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    ll cs;
    cin >> cs;
    while(cs--){
        stack<ll> st_op;
        deque<ll> st_ch;
        string s;
        cin >> s;
        vec(bool) d(s.size(), 0);
        ll cnth = 0, cnt_op = 0;
        bool ans = 1;
        lp(i, 0, s.size() - 1){
            char c = s[i];
            if(c == '(') {++cnt_op; st_op.push(i);}
            else if(c == '?') {++cnth; st_ch.push_back(i);}
            else{
                if(cnt_op) {--cnt_op; d[st_op.top()] = d[i] = 1; st_op.pop();}
                else if(cnth) {--cnth; d[st_ch.front()] = d[i] = 1; st_ch.pop_front();}
                else {
                    ans = 0;
                    break;
                }
            }
        }
        if(!ans){
            cout << NO;
            continue; 
        }
        while(1){
            if(st_ch.empty()) break;
            if(st_op.empty()) break;
            if(st_op.top() > st_ch.back()) {
                ans = 0;
                break;
            }
            while(st_ch.size() && st_op.size() && st_op.top() < st_ch.back()) st_op.pop(), st_ch.pop_back();
        }
        if(st_op.size() || !ans) cout << NO;
        else {
            if(st_ch.size() & 1) cout << NO;
            else cout << YES;
        }  
    }
}