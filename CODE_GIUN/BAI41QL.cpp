#include<bits/stdc++.h>
using namespace std;
const string tenfile = "BAI41QL";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);

int d[11] = {0}, n, l = 0, k = 0;

void giunnn(int vt)
{
    for (int i = 0; i <= 9; i++)
    {
        if (vt == 1 && i == 0) continue;
        if(d[i])
        {
            k = k * 10 + i;
            --d[i];
            if (vt == l) cout << k << endl;
            else giunnn(vt + 1);
            ++d[i];
            k = k / 10;
        }
    }
}

int main(){
    giuncute;
    balabalo;
    cin >> n;
    while (n)
    {
        ++d[n % 10], ++l, n /= 10;
    }
    giunnn(1);
}