#include <iostream>
using namespace std;

long nhap(int &n){
    cout << "\n nhap n:";
    cin >> n;
    return n;
}
long tong(int n){
    long kq = 1;
    for (int i = 1; i <= n; i++)
        kq = kq + i/(i+1);
        return kq;
}
main(){
    int n;
    nhap(n);
    cout << "\n ket qua:" << tong(n);
}