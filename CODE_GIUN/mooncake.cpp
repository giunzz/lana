#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200]={0},n,ans=0;
string s;
int main()
{
	freopen("giun.INP","r",stdin);
	freopen("giun.OUT","w",stdout);
	cin >> n >> s;
    for (int i = 0 ; i <  s.length() ; i++)
    {
        ll t = (ll) s[i];
        if (t >= 97) a[t]++;
        else 
        {
            if (a[t+32] > 0)  a[t+32]--;
            else ans++;
        }
    }
	cout << ans;
    return 0;
}
