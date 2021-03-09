#include <bits/stdc++.h>
using namespace std;
const int minum = '0', manum = '9', c = 12, h = 1, o = 16;
string s;
int t, sum, n;
stack<int> a;

void sol(){
    for (int i = 0; i < s.length(); i++){
        if (s[i + 1] >= minum && s[i + 1] <= manum && i < s.length() - 1){
            if (s[i] == 'C') sum += c*((int)s[i++ + 1] - minum);
            else if (s[i] == 'H') sum += h*((int)s[i++ + 1] - minum);
            else if (s[i] == 'O') sum += o*((int)s[i++ + 1] - minum);
            else {
                sum *= ((int)s[i++ + 1] - minum);
                sum += a.top();
                a.pop();
            }
        }
        else if (s[i] == 'C') sum += c;
        else if (s[i] == 'O') sum += o;
        else if (s[i] == 'H') sum += h;
        else if (s[i] == '(')
        {
            a.push(sum);
            sum = 0;
        }
        else {
            sum += a.top();
            a.pop();
        }
    }
    cout << sum << "\n";
    sum = 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sum = 0;
    cin >> s;
    cin.ignore();
    sol();
}
