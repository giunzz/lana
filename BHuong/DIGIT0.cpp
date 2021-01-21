#include <bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
string s ;
int dd[30]={0};
ll POW (int n , int x)
{
    if (n == 0) return 1;
    ll baby = POW(n/x);
    ll ans = baby*baby;
    if (n%x) ans *= x;
    return ans;
}

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("g.out","w",stdout);
    cin >> s;
    for (int i = 0 ; i < s.length() ; i++) dd[s[i]]++;
    int n = s.size();
    int k = 1 , uoc = 0;
    while (n / POW(5,k) != 0)
    {
        k++;
        uoc += n / POW(5,k);
    }
    
}