#include <bits/stdc++.h>

using namespace std;

int n , x , y , z;
string st[109];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("Cat.inp","r", stdin);
    freopen("Cat.out","w",stdout);
    cin >> n ;
    st[0] = "";
    for (int i = 1 ; i <= n ; i++){
        cin >> x >> y >> z;
        if ( abs (z - x) >= abs ( z - y ) ) st[i] = "Cat B";
        else st[i] = "Cat A";
    }
    for (int i = 2 ; i<= n ; i++){
        cerr << st[i] << endl;
        if ( st[i-1] == st[i])
        cout << st[i] << endl << "Mouse C" << endl;
        else cout << st[i] << endl;
    }
    return 0;
}


