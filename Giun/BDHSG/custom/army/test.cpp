#include<bits/stdc++.h>
using namespace std;

int f[25][7] = {{0}}, n;

void nhap(){
    ifstream ci;
    ci.open("army.inp");
    ci >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 4; j++) {
            ci >> f[i][j];
            f[i][j] /= 10;
        }
    }
    ci.close();
}

void xuat(){
    ofstream co;
    co.open("error.log");
    co << n << endl;
    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= 4; j++){
            co << f[i][j] << " ";
        }
        co << endl;
    }
    co.close();
}

int main(){
    nhap();
    xuat();
}