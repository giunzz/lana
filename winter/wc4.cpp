#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,a,  MOD =  1e9+7;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("wc4.inp","r",stdin);
    freopen("wc4.out","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> n >> a;
        if (a == 0 ) cout << 0 << endl;
        else if (a == 1 ) cout << (n * 2) % MOD << endl;
        else if (a == 2 ) cout << (n * 3) % MOD << endl;
        else if (a == 3 ) cout << (n * 4) % MOD << endl;
        else if (a == 4 ) cout << (n * 5) % MOD << endl;
        else if (a == 5 ) cout << (n * 6) % MOD << endl;
        else if (a == 6 ) cout << (n * 7) % MOD << endl;
    }    
    // vi quay lui ngao nen em chon cach nay :(
}