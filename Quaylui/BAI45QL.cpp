#include<bits/stdc++.h>
using namespace std;
const string tenfile = "BAI45QL";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);

int a[15], s[15], sum[15], n, k;
vector <int> ans[15];

void backtrack(int x)
{
    if(x > n)
    {
        int ok = 0;
        for(int i = 1; i <= n; i++) 
            sum[s[i]] += a[i];
        for(int i = 1; i <= k; i++) 
            if(sum[i] != sum[1] || sum[i] == 0) ok = 1;
        for(int i = 1; i <= k; i++)
             sum[i] = 0;
        if(ok) 
        {
            return;
        }
        for(int i = 1; i <= n; i++) ans[s[i]].push_back(a[i]);
        for(int i = 1; i <= k; i++)
        {
            for(int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " " ;
            cout << endl;
        }
        
        exit(0);
    }
    for(int j = 1; j <= k; j++)
    {
        s[x] = j;
        backtrack(x + 1);
    }
}
int main()
{
    balabalo;
    giuncute;
    cin >> n >> k;
    int summ = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        summ += a[i];
    }
    if ( summ % k != 0  ) cout <<-1; 
    else backtrack(1);
}
