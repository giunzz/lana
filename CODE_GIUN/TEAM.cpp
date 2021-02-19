#include<bits/stdc++.h>
using namespace std;
const string tenfile = "TEAM";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;
long long o, b, k, cap, du;

void updatedu()
{
    if (o / 2 > b) du = o - b * 2, cap = b;
    else if (o / 2 <= b) du = o + b - (int)(o / 2) * 3, cap = o / 2;
}

void sol()
{
    if (du >= k)
    {
        cout << cap;
    }
    else {
        k -= du;
        if (k % 3 == 0) cap -= k / 3;
        else cap -= k / 3 + 1;
        cout << cap;
    }
}
int main() {
    giuncute;
    balabalo;
    cin.tie(0);
    cin >> o >> b >> k;
    updatedu();
    sol();
    return 0;
}
