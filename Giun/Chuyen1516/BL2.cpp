#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("BL2.INP", "r", stdin);
    freopen("BL2.OUT", "w", stdout);
    int n, k, a[105], b[205], c[105], amax, amin;
    cin >> n >> a[1];
    memset(b, 0, sizeof(b));
    b[a[1] + 100] = 1;
    c[1] = (a[1] > 0) ? 1 : 0;
    amax = a[1];
    amin = a[1];
    for (int i = 2; i <= n; i++)
    {
        cin >> a[i];
        b[a[i] + 100] = 1; //Số tồn tại
        c[i] = (a[i] > 0) ? (1 + c[i-1]) : 0; //Số dương
        amax = max(amax, a[i]);
        amin = min(amin, a[i]);
    }
    for (int i = amin; i <= amax; i++)
        if (b[i + 100] == 0) cout << i << " ";
    cin >> k;
    for (int i = 1; i <= n; i++)
        if (c[i] == k)
        {
            cout << endl << "CO\n";
            break;
        }
        else if (i == n) cout << endl << "KHONG\n";
    for (int i = 1; i <= n; i++)
    {
        if (b[a[i] + 100] == 1)
        {
            cout << a[i] << " ";
            b[a[i] + 100] = 0;
        }
    }
    return 0;
}
