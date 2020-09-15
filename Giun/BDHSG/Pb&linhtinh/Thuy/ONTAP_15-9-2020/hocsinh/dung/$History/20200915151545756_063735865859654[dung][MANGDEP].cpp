#include<bits/stdc++.h>
using namespace std;

int a[(int) 1e6 + 7] , n, ans = 0, d[100] = {0},dem[100] = {0};

void nen()
{
    d[4] = 1 , d[8] = 2 , d[15] = 3, d[16] = 4, d[23] = 5 , d[42] = 6; 
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("mangdep.inp","r",stdin);
    freopen("mangdep.out","w",stdout);
    cin >> n ;
    nen(); 
    for (int i  = 1 ; i <= n ; i++) 
    {
        cin >> a[i];
        a[i] = d[a[i]];
    }
    for (int i = 1 ; i <= n ; i++)
    {
        if (a[i] == 1) dem[a[i]]++;
        else if (dem[a[i] - 1] > 0 ) dem[a[i]]++ , dem[a[i]-1] = 0;
    }
    cout << n - dem[6]*6;
}
