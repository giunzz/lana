#include <bits/stdc++.h>

using namespace std;

const int change = 48; // : = 4, x = 3, - = 2, + = 1, ( = 0

stack<string> dau;
stack<float> so; // 0 la so, 1 la dau
stack<int> bt;
string s;
int t;

void init(){
    for (int i = 48; i <= 48 + 9; i++){
        bt[(char)i] = i - 48;
    }
    bt['('] = 0;
    bt['x'] = 3;
    bt[':'] = 4;
    bt['-'] = 2;
    bt['+'] = 1;
}

void xuli(){
    int num = 0;
    for (int i = 0; i < s.length(); i++){
        if (s[i] >= '0' && s[i] <= '9'){
            while (s[i] >= '0' && s[i] <= '9'){
                num = num * 10 + bt[s[i++]];
            }
            rpn.push(num);
        }
        //else if (st.empty()) st.push(s[i]);
        if (s[i] == '(' || st.empty()) st.push(bt[s[i]]);
        else if (s[i] == ')'){
            while (st.top() != bt['(']){
                rpn.push(st.top());
                st.pop();
            }
            st.pop();
        }
        else if (s[i] == 'x' || s[i] == ':') st.push(b[s[i]]);
        else {

        }
    } 
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    freopen("bieuthuc.inp", "r", stdin);
    freopen("bieuthuc.out", "w", stdout);
    cin >> t;
    for (int i = 1; i <= t; i++){
        cin >> s;
        xuli();
    }
}