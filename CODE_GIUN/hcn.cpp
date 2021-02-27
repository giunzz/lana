#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);

int n , a[5];

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun8.out","w",stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> a[1] >> a[2] >> a[3] >> a[4];
        cout << min(a[1],a[4]) *min(a[3],a[2]) << endl;
    }
}