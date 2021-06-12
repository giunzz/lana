#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
ll ans = 1;
char dd[40] = {0};
string a;

int main()
{
    giuncute;
    //freopen("giun.inp","r",stdin);
    //freopen("giun.out","w",stdout);
    cin >> a;
    for (int i = 0 ; i < a.length() ; i++) dd[a[i]]++;
    for (char i = 'a' ; i <= 'z' ; i++)
        if (dd[i] != 0) ans *= (dd[i] % 1000000007);
    cout << ans % 1000000007;
}