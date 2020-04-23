#include <bits/stdc++.h>
using namespace std;
int n, m, a[(int)1e5 + 7];

void enter(){
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    enter();
    return 0;
}