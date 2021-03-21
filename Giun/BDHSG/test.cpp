#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    while(s.find("anh")!=-1)
    {
        int vt = s.find("anh");
        s.erase(vt,3);
        s.insert(vt,"em");
    }
    cout<<s;
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     string a, s, t;
//     getline(cin, a);
//     getline(cin, s);
//     getline(cin, t);
//     while((int)a.find(s) != -1){
//         int pos = a.find(s);
//         a.erase(pos, s.size());
//         a.insert(pos, "*");
//     }
//     // cout << a;
//     for(int i = 0; i < a.size(); ++i){
//         if(a[i] == '*') cout << t;
//         else cout << a[i];
//     }
// }