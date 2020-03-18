#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
string S,s1;
int n;
bool kiemtra(string s){
    int k=s.length()/2;
    for (int i = 0; i < k; i++){
            if (s[i] != s[s.length()-i-1]) return false;
    }
    return true;
}

int main(){
    freopen("BAI59.INP", "r", stdin);
    freopen("BAI59.OUT", "w", stdout);
    cin >> S;
    n=S.length();
    for (int i=1 ; i<= n ; i++){
        s1=S.substr(0,1);
        S.erase(0,1);
        S+=s1;
        if (kiemtra(S)){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
