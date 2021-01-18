#include<bits/stdc++.h>
using namespace std;

int main(){
    srand((int)time(0));
    int N = 374637, n, i = 1;
    // cout << N << '\n';
    while(cin >> n){
        if(n == N) {
            cout << "Chien thang" << endl;
            cout << "So lan doan " << i;
            break;
        }
        else{
            if(n > N) {
                cout << "Lon hon" << endl;
            }
            else {
                cout << "Nho hon" << endl;
            }
        }
        ++i;
    }
}