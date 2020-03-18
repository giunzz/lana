#include<bits/stdc++.h>
using namespace std;
string s1;
string chuhoa(string s){
    for (int i=0;i<s.length();i++){
            if ((int)s[i] >= 97 && int(s[i])<=122)
            s[i]= char(int(s[i])-32);
    }
    return s;
}
int main (){
    freopen("UPC.INP","r",stdin);
    freopen("UPC.OUT","w",stdout);
    getline(cin,s1);
    cout << chuhoa( s1);
    return 0;
}
