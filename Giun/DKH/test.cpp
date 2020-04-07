#include <bits/stdc++.h>

using namespace std;
stack<string> st;

int main(){
    st.push("ab");
    st.push("cd");
    cout << st.top() << endl;
    st.pop();
    cout << st.top();
}