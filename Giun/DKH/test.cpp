#include <bits/stdc++.h>

using namespace std;

int main(){
    int a[] = {0, 2, 1, 0, -1};
    sort(a + 1, a + 5);
    int k = lower_bound(a + 1, a + 1 + 4, 3) - a;
    for (int i = 0; i <= 4; i++) cout << a[i] << " ";
    cout << endl << k;
}