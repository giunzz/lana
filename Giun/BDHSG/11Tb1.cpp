#include <iostream>
using namespace std;

int a[(int)1e6], n, i;

int main(){
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> a[i];
    }
    int max = a[0];
    for(i = 1; i < n; i++){
        if(a[i] > max) max = a[i];
    }
    cout << max;
}