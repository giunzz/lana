// #include<bits/stdc++.h>
// using namespace std;
// // ko lien tiep
// int n , a[10007] , f[1009]={0},t , ma = 0, ans = INT_MIN;

// int main()
// {
//     ios_base::sync_with_stdio(0);cin.tie(0);
//     freopen("giun.inp","r",stdin);freopen("giun.out","w",stdout);
//     cin >> n ;
//     for (int i = 1 ; i <= n ; i++) cin >> a[i];
//     f[1] = 1;
//     for (int i = 2 ; i <= n ; i++ )
//     {
//         ma = 0;
//         for (int j = 1 ; j < i ; j++)
//         {
//             if (a[j] < a[i]) ma = max (ma,f[j]);
//           //  cerr << ma << " ";
//         }
//         //cerr << endl;
//         f[i] = ma+1;
//         ans = max (ans,f[i]);
//     }
//     cout << ans;
// }

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;

    vector<int> f(n+1), b(n+1, INT_MAX);
    b[0] = INT_MIN;
    int result = 0;
    for (int x: a) {
        int k = lower_bound(b.begin(), b.end(), x) - b.begin();
        b[k] = x;
        result = max(result, k);
    }

    cout << result;
    return 0;
}