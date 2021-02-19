#include <bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
int n , k;

inline int check(int x)
{
    int ans = 1 , k = 1;
    while (k % x != 0) 
    {
        k = (k % x )*10+1 ;
        
        ans++;
    }
    return ans;
}
int main()
{
    giuncute;
    freopen("number1.inp","r",stdin);
    freopen("number1.out","w",stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) 
    {
        cin >> k;
        cout << check(k) << endl;
    }
}