#include <bits/stdc++.h>

using namespace std;
unsigned int n;
unsigned long long t;

bool ktnt(int t){
    if (t == 0 || t == 1) return 0;
    for (int i = 2; i <= sqrt(t); i++)
        if (t % i == 0) return 0;
    return 1;
}

void sol(int i){
    for (int j = 0; j <= 9; j++){
        if (ktnt(t * 10 + j)){
            t = t * 10 + j;
            if (i == n){
                //cerr << t << endl; 
                cout << t << "\n";
            }
            else sol(i + 1);
            t = t / 10;
        }
    }
}

int main(){
    freopen("bai40ql.INP", "r", stdin);
    freopen("bai40ql.OUT", "w", stdout);
    cin >> n;
    if (n == 1) cout << "2\n3\n5\n7\n";
    else if (n == 0 || n == 9) cout << "-1";
    else sol(1);
    //cerr << 1;
    return 0;
}