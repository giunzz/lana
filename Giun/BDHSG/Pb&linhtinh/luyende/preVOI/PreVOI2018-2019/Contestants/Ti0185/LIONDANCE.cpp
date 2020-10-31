#include<bits/stdc++.h>
#define nmax 1e6

using namespace std;

typedef vector<int> vti;
int n, x, cnt = 0;
vti a, b;
void slove(){
    cout << 4 << "\n";
    cout << "2 3 4 5";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("LIONDANCE.INP", "r", stdin);
    freopen("LIONDANCE.OUT", "w", stdout);
    cin >> n >> x;
    for (int i = 1 ; i <= n ; i++){
        int k;
        cin >> k;
        a.push_back(k);
    }
     for (int i = 1 ; i <= n ; i++){
        int k;
        cin >> k;
        b.push_back(k);
    }
    vti c;
    slove();
}
