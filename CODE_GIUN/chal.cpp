#include<bits/stdc++.h>
using namespace std;
int sang[(int)1e6+ 7] ={0};
vector<int> prime;
struct giun{
    int cot = 0, hang = 0;
}f[(int) 1e3+7][(int) 1e3+7];

void ss ()
{
    sang[1] = 1 , sang[0] = 1;
    for (int i = 2 ; i*i <=  1e6 ; i++)
        if(!sang[i])
        {
            prime.push_back(i);
            for (int j = i *i ; j <= 1e6 ; j+=i) sang[j] = 1;
        }
}
int m,n,a[(int) 1e3+7][(int) 1e3+7], d = 0, ans = INT_MAX;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    freopen("chal.inp","r",stdin);
    freopen("chal.out","w",stdout);
    ss();
    cin >> m >> n ;
    for (int i = 1 ; i <= m ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
            cin >> a[i][j];
    }
    for (int i = 1 ; i <= m ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            int t = lower_bound(prime.begin(), prime.end(), a[i][j]) - prime.begin();
            f[i][j] = {prime[t] - a[i][j], prime[t] - a[i][j]};
            f[i][j].cot += f[i - 1][j].cot;
            f[i][j].hang += f[i][j - 1].hang;
            cerr << f[i][j].cot << " " << f[i][j].hang;
        }
    }
    for (int i =1 ; i <= m ; i++) ans = min(ans, f[i][m].hang);
    for (int j = 1 ; j <= n ; j++) ans = min(ans, f[m][j].cot);
    cout << ans;
}