#include<bits/stdc++.h>
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define ll long long 
using namespace std;

ll n , a[(int)1e5+7] , t ;
void blablalolo()
{
    freopen("PREOLP1.INP","r",stdin);
    freopen("PREOLP1.OUT","w",stdout);
}
int main()
{
    giuncute;
    blablalolo();
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1 ; i <= n ; i++) cin >> a[i]; 
        sort(a+1,a+1+n);
        cout << a[n]*(n-1)+a[n-1] << endl;
    }
}