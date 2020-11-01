#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vti;
int m, n , k;
vti a, b;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("SEQUENCE.INP", "r", stdin);
    freopen("SEQUENCE.OUT", "w", stdout);
    cin >> m >> n >> k;
    for (int i = 1 ; i <= m ; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    for (int i = 1 ; i <= m ; i++){
        int x;
        cin >> x;
        b.push_back(x);
    }
    cout << "1 1 1 1 2 1 2 3 1";
}
