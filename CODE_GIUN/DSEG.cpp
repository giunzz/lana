#include<bits/stdc++.h>
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
using namespace std;
#define ll long long
ll n , a[(int) 1e5+7] , b[(int) 1e5+7]={0} , c[(int)1e5+7]={0};
vector<ll> ans;
int main()
{
    giuncute;
    freopen("dseg.inp","r",stdin);
    freopen("dseg.out","w",stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> a[i] , b[i] = b[i-1] + a[i];
    //for (int i = 1 ; i <= n ; i++) cerr << b[i] << " ";
    //cerr << endl;
    for (int i = 1 ; i < n ; i++) c[i] = b[n]-b[i];
    for (int i = 1 ; i <= n ; i++)
    {
        ll k = 0;
        for (int j = i ; j <= n ; j++) k = max(k,abs(b[i] - c[j]));
        ans.push_back(k);   
    }
 //   for (int i = 1 ; i < n ; i++) cerr << c[i] << " ";
 //   cerr << endl;
    sort (ans.begin() , ans.end());
    cout << ans[ans.size()-1] << " ";
    int d = 0;
    for (int i = ans.size()-1 ; i >= 0 ; i-- ) 
    {
   //     cerr << ans[i] << " ";
        if (ans[i] != ans[ans.size()-1]) {break;}
        d++;
    }
    cout << d;
}