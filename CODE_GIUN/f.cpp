#include<bits/stdc++.h>
#define ll long long 
#define cll const long long 
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0)
using namespace std;
string a,b;
ll t, c;
map <string ,ll> dd;
vector <string> res;
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;
        if (dd[a] == 0) res.push_back(a) ;
        dd[a] += c;
        if (dd[b] == 0) res.push_back(b);
        dd[b] += c;  
    }
    sort(res.begin() , res.end());
    for (int i = 0 ; i < res.size() ; i++) cout << res[i] << " " << dd[res[i]] << endl;
}