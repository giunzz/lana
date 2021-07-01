#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("giun.inp" , "r",stdin);
    freopen("giun.out", "w" ,stdout);
    int n , x , y ;
    cin >> n ;
    vector<int> a(n);
    for (int i = 1 ; i < a.size() ; i++) cin >> x >> y , a[i] = x + y;
    vector<int>  b(n+1, INT_MAX);
    b[0] = INT_MIN;
    int result = 0;
    for (int x: a) 
    {
        int i = lower_bound(b.begin(), b.end(), x) - b.begin();
        b[i] = b[i-1] + x ;
        result = max(result, i);
    }
    cout << result ;
    return 0;
}