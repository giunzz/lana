#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>

using namespace std;
const int minum = '0', manum = '9', c = 12, h = 1, o = 16;
string s;
int t, sum, n, stack[(int)1e7 + 7], top = -1;
//stack<int> a;

//push, pop, top

void Push(int value){
    //++top;
    stack[++top] = value;
}
 
void Pop(){
    --top;
    //return stack[top--];
}
 
int Top(){
    return stack[top];
}
 
void sol(){
    for (int i = 0; i < s.length(); i++){
        if (s[i + 1] >= minum && s[i + 1] <= manum && i < s.length() - 1){
            if (s[i] == 'C') sum += c*((int)s[i++ + 1] - minum);
            else if (s[i] == 'H') sum += h*((int)s[i++ + 1] - minum);
            else if (s[i] == 'O') sum += o*((int)s[i++ + 1] - minum);
            else {
                sum *= ((int)s[i++ + 1] - minum);
                sum += Top();
                Pop();
            }
        }
        else if (s[i] == 'C') sum += c;
        else if (s[i] == 'O') sum += o;
        else if (s[i] == 'H') sum += h;
        else if (s[i] == '('){
            Push(sum);
            sum = 0;
        }
        else {
            sum += Top();
            Pop();
        }
    }
    cout << sum << "\n";
    sum = 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("spc6.inp", "r", stdin);
    freopen("spc6.out", "w", stdout);
    cin >> t;
    for (int i = 1; i <= t; i++){
        sum = 0;
        cin >> s;
        cin.ignore();
        sol();
    }
}