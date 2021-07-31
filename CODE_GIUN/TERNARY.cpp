#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
using namespace std;

ll a , c , ans = 0 ;
vector<ll> tc , ta;

vector<ll> doi(ll num)
{
    vector<ll> tmp;
    if(num == 0) tmp.push_back(0);
    while (num != 0)
    {
        tmp.push_back(num % 3);
        num /= 3;
    }
    return tmp;
}

int main()
{
    giuncute;
    freopen("TERNARY.inp" ,"r",stdin);
    freopen("TERNARY.out", "w" ,stdout);
    cin >> a >> c;
    ta = doi(a);
    tc = doi(c);
    while(ta.size() < tc.size()) ta.push_back(0);
    while(ta.size() > tc.size()) tc.push_back(0);
    for (int i = 0 ; i < ta.size() ; i++) ans += ((6 + (tc[i] - ta[i])) % 3) * pow(3, i);
    cout << ans;
}