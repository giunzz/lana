#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("giun.inp" , "r",stdin);
    freopen("giun.out", "w" ,stdout);
    int n,m ;
    cin >> n >> m;
    cout << m / n << endl << m - (m/n)*n;
}