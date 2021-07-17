#include <bits/stdc++.h>
using namespace std;
string s , res;
int main() 
{
    freopen("hoanvi.inp","r",stdin);
    freopen("hoanvi.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    res = s;
    sort(s.begin(), s.end());
    int ans = 1 ;
    while (s != res) 
    {
        ans++;
        next_permutation(s.begin(), s.end());
    } 
    cout << ans << endl;
}