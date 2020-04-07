#include <iostream>

using namespace std;

string pay(unsigned long long int a, unsigned long long int b, unsigned long long int n, unsigned long long int s){
    unsigned long long int x = 1, p = n;
    while (x < a && s - p >= n) p += n, ++x;
    if ((s - x * n) <= b) return "YES";
    else return "NO";
}

int main(){
    int q;
    unsigned long long int a, b, n, s;
    cin >> q;
    for (int i = 0; i < q; i++){
        cin >> a >> b >> n >> s;
        cout << pay(a, b, n, s) << endl;
    }
    return 0;
}
