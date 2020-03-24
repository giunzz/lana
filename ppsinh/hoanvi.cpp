#include <bits/stdc++.h>

using namespace std;
int hv[23], n;
bool d[23];

void in(){
    for (int i = 1; i <= n; i++){
        cout << hv[i];
        cout << " ";
    }
    cout << "\n";
}

void sol(int i){
    for (int j = 1; j <= n; j++){
        if (d[j] == 0){
            hv[i] = j, d[j] = 1;
            if (i == n){
                in();
                d[j] = 0;
            }   
            else{
                sol(i + 1);
                d[j] = 0;
            }
        }
    }
}

int main(){
    freopen("hoanvi.INP", "r",stdin);
    freopen("hoanvi.OUT", "w",stdout);
    cin >> n;
    sol(1);
    return 0;
}