#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
int n , a[(int) 1e6+7] , f[(int) 1e6+7]={0};
int main()
{
    giuncute;
    freopen("BOTTLES.inp","r",stdin);
    freopen("BOTTLES.out","w",stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    f[1] = a[
        1] , f[2] = a[1] + a[2] , f[3] = max(a[1]+a[2],max(a[2]+a[3], a[1]+a[3]));
    for (int i = 4 ; i <= n ; i++) 
        f[i] = max(f[i - 1] , max( f[i - 2] + a[i], f[i - 3] + a[i - 1] + a[i]));
    int i = n;
    vector<int> ans;
    if (n == 1) ans.push_back(1);
    else if (n == 2) ans.push_back(1) , ans.push_back(2);
    while ( i > 4)
    {
        if (f[i]  == f[i-3] + a[i] + a[i-1] ) ans.push_back(i) , ans.push_back(i-1), i-=3;
        else if (f[i]  == f[i-2]+a[i] ) ans.push_back(i) , i-=2;
        else if (f[i] == f[i-1]) ans.push_back(i-1) , i-- ;
    }
    if (n >= 3)
    {
        if (a[1] + a[2] >= a[2] + a[3] && a[1] + a[2] >= a[1] + a[3] )  
            ans.push_back(2) , ans.push_back(1);
        if (a[2] + a[3] >= a[1] + a[3] && a[2] + a[3] >= a[1] + a[2] )  
            ans.push_back(3) , ans.push_back(2);
        if (a[1] + a[3] >= a[2] + a[3] && a[1] + a[3] >= a[1] + a[2] )  
            ans.push_back(3) , ans.push_back(1);
    }
    cout << ans.size() << " " << f[n] << endl;
    for (int i = ans.size()-1 ; i >= 0 ; i--) cout << ans[i] << endl;
}
