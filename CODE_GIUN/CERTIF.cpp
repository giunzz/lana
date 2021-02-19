#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
long long n , x , s = 0;
vector<long long> a;
int main()
{
    giuncute;
    freopen("CERTIF.inp","r",stdin);
    freopen("CERTIF.out","w",stdout);
    cin >>n;
    for (long long i = 1 ; i <= n ; i++)
    {
        cin >> x;
        if (x != 0) a.push_back(x);
    }
    sort(a.begin(),a.end());
    for (long long i = 0 ; i < a.size()-1 ;i++) s += a[i]+1;
    cout << s;
}