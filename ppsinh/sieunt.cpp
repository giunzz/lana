#include <bits/stdc++.h>

using namespace std;
unsigned int n;
unsigned long long t;

bool ktnt(){
    if (t == 0 || t == 1) return 0;
    for (int i = 2; i <= sqrt(t); i++)
        if (t % i == 0) return 0;
    return 1;
}

void sol(int i){
    for (int j = 1 ; j <= 9; j++){
        if ((j % 2) || j == 2){
            t = t * 10 + j;
            if (ktnt()){
                if (i == n){
                    //cerr << t << endl; 
                    cout << t << "\n";
                }
                else sol(i + 1);
            }
            t = t / 10;
        }
    }
}

int main(){
    //freopen("sieunt.INP", "r", stdin);
    //freopen("sieunt.OUT", "w", stdout);
    cin >> n;
    sol(1);
    //cerr << 1;
    return 0;
}