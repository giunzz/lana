#include <bits/stdc++.h>
using namespace std;

void change(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void change1(int &x, int &y){
    int tmp = x;
    x = y;
    y = tmp;
}

void change2(int &x, int &y){
    x = x ^ y;
    y = x ^ y;   
    x = x ^ y;
}

int main(){
    int a = 6, b = 9;
    change1(a, b);
    change(&a, &b);
    change2(a, b);
    cout << a << " " << b; 
}
// a b  a xor b
// 0 0     0
// 1 1     0
// 0 1     1
// 1 0     1