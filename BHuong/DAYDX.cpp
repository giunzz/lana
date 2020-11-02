#include<bits/stdc++.h>
using namespace std; 
#define ll long long
ll f[1007][1007] ={{0}}, a[1007], n ;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ; 
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    for(int i =  1; i <= n; i++) f[i][i] = 1;
    for (int len = 1 ; len <= n ; len++)
    {
        for (int i = 1 ; i <= n ; i++)
        {
            int j = i + len;
            if (j > n) break;
            if (a[i]== a[j]) f[i][j] = f[i+1][j-1] + 2;
            else f[i][j] = max(max(f[i+1][j] , f[i][j-1]), f[i + 1][j - 1]);
            // cerr << f[i][j] << " ";
        }
        // cerr << endl;
    }
    cout << f[1][n] << endl;
    ll i = 1, j = n;
    vector<ll> ans;
    while (i < j)
    {
        // if(i == j) ans.push_back(i), --j;
        if(f[i][j] == f[i + 1][j - 1]) i++, j--;
        else if (f[i][j] == f[i+1][j-1]+2 && a[i] == a[j]) {
            ans.push_back(i); 
            ans.push_back(j); 
            i++,j--;
        }
        else if(f[i][j] == f[i+1][j]) i++;
        else j--;
        // cerr << i << " " << j << endl;
    }
    if(i == j) ans.push_back(i);
    sort(ans.begin(), ans.end());
    // cerr << ans.size();
    // for (int i = 0 ; i < ans.size() ; i++) cerr << ans[i] << " ";
    for(int i = 0; i < ans.size(); i++) cout << a[ans[i]] << ' ';
    // for(int i = ans.size() - 1 + (f[1][n] & 1); i >= 0; i++) cout << ans[i] << ' ';
}
