#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
using namespace std;
int n , m;

inline bool check(int x)
{
    int s = 1;
    for (int i = 2 ; i < x ;i++)
    {
        if (x%i == 0) s += i;
        if (s > x) return true;
    }
    return false;
}

int main()
{
    giuncute;
    cin >> n >> m ;
    int ans = 0;
    if (n < 12) n = 12;
    for (int i = n ; i <= m ; i++)
    {
        if (check(i) == true)  ans++;
    }
    cout << ans;
}